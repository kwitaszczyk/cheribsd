/*-
 * Copyright (c) 2018 Edward Tomasz Napierala <trasz@FreeBSD.org>
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/mman.h>
#include <sys/proc.h>
#include <sys/syscall.h>
#include <sys/syscallsubr.h>
#include <sys/sysent.h>
#include <sys/sysproto.h>
#include <sys/unistd.h>

#include <cheri/cheri.h>
#include <cheri/cheric.h>

#include <vm/vm.h>
#include <vm/vm_param.h>
#include <vm/vm_extern.h>
#include <vm/vm_page.h>
#include <vm/vm_pageout.h>
#include <vm/vm_map.h>

/*
 * Capability used to seal capability pairs returned by cosetup(2).
 */
void * __capability	switcher_sealcap;

/*
 * Capability used to seal capabilities returned by coregister(2)/colookup(2).
 */
void * __capability	switcher_sealcap2;

struct mtx		switcher_lock;

/*
 * For now, all we do is declare what we support, as most initialisation took
 * place in the MIPS machine-dependent assembly.  CHERI doesn't need a lot of
 * actual boot-time initialisation.
 */
static void
colocation_startup(void)
{

	cheri_capability_set(&switcher_sealcap, CHERI_SEALCAP_SWITCHER_PERMS,
	    CHERI_SEALCAP_SWITCHER_BASE, CHERI_SEALCAP_SWITCHER_LENGTH,
	    CHERI_SEALCAP_SWITCHER_OFFSET);

	cheri_capability_set(&switcher_sealcap2, CHERI_SEALCAP_SWITCHER2_PERMS,
	    CHERI_SEALCAP_SWITCHER2_BASE, CHERI_SEALCAP_SWITCHER2_LENGTH,
	    CHERI_SEALCAP_SWITCHER2_OFFSET);

	mtx_init(&switcher_lock, "switcher lock", NULL, MTX_DEF);
}
SYSINIT(colocation_startup, SI_SUB_CPU, SI_ORDER_FIRST, colocation_startup,
    NULL);

void
colocation_thread_exit(struct thread *td)
{
	struct switcher_context sc, *peersc;
	vaddr_t addr;
	int error;

	addr = td->td_md.md_switcher_context;
	if (addr == 0)
		return;

	error = copyincap_c(__USER_CAP((void *)addr, sizeof(sc)), &sc, sizeof(sc));
	if (error != 0) {
		printf("%s: copyincap_c from %p failed with error %d\n",
		    __func__, (void *)addr, error);
		return;
	}

	peersc = (__cheri_fromcap struct switcher_context *)sc.sc_peer_context;
	//printf("%s: terminating thread %p, peer context %p\n", __func__, td, peersc);


	/*
	 * Set sc_peer_context to a special "null" capability, so that cocall(2)
	 * can see the callee thread is dead.
	 */
	cheri_capability_set((void * __capability *)&sc.sc_peer_context, 0, 0, 0, 0);
	sc.sc_td = NULL;
	sc.sc_borrower_td = NULL;

	error = copyoutcap_c(&sc, __USER_CAP((void *)addr, sizeof(sc)), sizeof(sc));
	if (error != 0) {
		printf("%s: copyoutcap_c to %p failed with error %d\n",
		    __func__, (void *)addr, error);
		return;
	}

	if (peersc == NULL)
		return;

	error = copyincap_c(__USER_CAP((void *)peersc, sizeof(sc)), &sc, sizeof(sc));
	if (error != 0) {
		printf("%s: peer copyincap_c from %p failed with error %d\n",
		    __func__, (void *)peersc, error);
		return;
	}

	sc.sc_peer_context = NULL;
	sc.sc_borrower_td = NULL;

	error = copyoutcap_c(&sc, __USER_CAP((void *)peersc, sizeof(sc)), sizeof(sc));
	if (error != 0) {
		printf("%s: peer copyoutcap_c to %p failed with error %d\n",
		    __func__, (void *)peersc, error);
		return;
	}
}

/*
 * Called from trap().
 */
void
colocation_unborrow(struct thread *td, struct trapframe **trapframep, int type)
{
	struct switcher_context sc;
	struct thread *peertd;
	struct trapframe peertrapframe;
	struct syscall_args peersa;
	register_t peertpc;
	int error;

	if (td->td_md.md_switcher_context == 0) {
		/*
		 * We've never called cosetup(2).
		 */
		return;
	}

	/*
	 * Fetch switcher context for currently executing userspace thread.
	 */
	error = copyincap_c(__USER_CAP((const void *)td->td_md.md_switcher_context, sizeof(sc)), &sc, sizeof(sc));
	KASSERT(error == 0, ("%s: copyincap_c from %p failed with error %d\n",
	    __func__, (void *)td->td_md.md_switcher_context, error));

	peertd = sc.sc_borrower_td;
	if (peertd == NULL) {
		/*
		 * Nothing borrowed yet.
		 */
		return;
	}

	KASSERT(peertd != td, ("%s: peertd %p == td %p\n", __func__, peertd, td));

#if 0
	printf("%s: trap type %#x, replacing current td %p, switcher_context %#lx, md_tls %p, md_tls_tcb_offset %zd, "
	    "with td %p, switcher_context %#lx, md_tls %p, md_tls_tcb_offset %zd\n", __func__, type,
	    td, td->td_md.md_switcher_context, (__cheri_fromcap void *)td->td_md.md_tls, td->td_md.md_tls_tcb_offset,
	    peertd, peertd->td_md.md_switcher_context, (__cheri_fromcap void *)peertd->td_md.md_tls, peertd->td_md.md_tls_tcb_offset);
#endif

	/*
	 * Assign our trapframe (userspace context) to the thread waiting
	 * in copark(2) and wake it up; it'll return to userspace with ERESTART
	 * and then bounce back.
	 */
	KASSERT(td->td_frame == &td->td_pcb->pcb_regs,
	    ("%s: td->td_frame %p != &td->td_pcb->pcb_regs %p, td %p",
	    __func__, td->td_frame, &td->td_pcb->pcb_regs, td));
	KASSERT(peertd->td_frame == &peertd->td_pcb->pcb_regs,
	    ("%s: peertd->td_frame %p != &peertd->td_pcb->pcb_regs %p, peertd %p",
	    __func__, peertd->td_frame, &peertd->td_pcb->pcb_regs, peertd));

	peersa = peertd->td_sa;
	cheri_memcpy(&peertrapframe, peertd->td_sa.trapframe, sizeof(struct trapframe));
	peertpc = peertd->td_pcb->pcb_tpc;

	peertd->td_sa = td->td_sa;
	cheri_memcpy(peertd->td_frame, *trapframep, sizeof(struct trapframe));
	peertd->td_pcb->pcb_tpc = td->td_pcb->pcb_tpc;

	td->td_sa = peersa;
	cheri_memcpy(td->td_frame, &peertrapframe, sizeof(struct trapframe));
	td->td_pcb->pcb_tpc = peertpc;

	*trapframep = td->td_frame;

	wakeup(&peertd->td_md.md_switcher_context);

	/*
	 * Continue as usual, but calling copark(2) instead of whatever
	 * syscall it was.
	 */
	KASSERT(td->td_sa.code == SYS_copark,
	    ("%s: td_sa.code %d != %d\n", __func__, td->td_sa.code, SYS_copark));
}

static int
cosetup(struct thread *td)
{
	struct switcher_context sc;
	vm_map_t map;
	vm_map_entry_t entry;
	vaddr_t addr;
	boolean_t found;
	int error;

	KASSERT(td->td_md.md_switcher_context == 0, ("%s: already initialized\n", __func__));

	/*
	 * XXX: Race between this and setting the owner.
	 */
	error = kern_mmap(td, 0, 0, PAGE_SIZE, VM_PROT_READ | VM_PROT_WRITE, MAP_ANON, -1, 0);
	if (error != 0) {
		printf("%s: kern_mmap() failed with error %d\n", __func__, error);
		return (error);
	}

	addr = td->td_retval[0];
	td->td_md.md_switcher_context = addr;
	td->td_retval[0] = 0;

	map = &td->td_proc->p_vmspace->vm_map;
	vm_map_lock(map);
	found = vm_map_lookup_entry(map, addr, &entry);
	KASSERT(found == TRUE, ("%s: vm_map_lookup_entry returned false\n", __func__));

	entry->owner = 0;
	vm_map_unlock(map);

	//printf("%s: context at %p, td %p\n", __func__, (void *)addr, td);
	sc.sc_unsealcap = switcher_sealcap2;
	sc.sc_td = td;
	sc.sc_borrower_td = NULL;
	sc.sc_peer_context = NULL;

	error = copyoutcap_c(&sc, __USER_CAP((void *)addr, sizeof(sc)), sizeof(sc));
	KASSERT(error == 0, ("%s: copyout failed with error %d\n", __func__, error));

	return (0);
}

int
sys_cosetup(struct thread *td, struct cosetup_args *uap)
{
	void * __capability codecap;
	void * __capability datacap;
	vaddr_t addr;
	int error;

	if (td->td_md.md_switcher_context == 0) {
		error = cosetup(td);
		if (error != 0)
			return (error);
	}

	addr = td->td_md.md_switcher_context;

	switch (uap->what) {
	case COSETUP_COCALL:
		cheri_capability_set(&codecap, CHERI_CAP_USER_CODE_PERMS,
		    td->td_proc->p_sysent->sv_cocall_base,
		    td->td_proc->p_sysent->sv_cocall_len, 0);
		codecap = cheri_seal(codecap, switcher_sealcap);
		error = copyoutcap_c(&codecap, __USER_CAP(uap->code, sizeof(codecap)), sizeof(codecap));
		if (error != 0)
			return (error);

		cheri_capability_set(&datacap,
		    CHERI_CAP_USER_DATA_PERMS, addr, PAGE_SIZE, 0);
		datacap = cheri_seal(datacap, switcher_sealcap);
		error = copyoutcap_c(&datacap, __USER_CAP(uap->data, sizeof(datacap)), sizeof(datacap));
		return (0);

	case COSETUP_COACCEPT:
		cheri_capability_set(&codecap, CHERI_CAP_USER_CODE_PERMS,
		    td->td_proc->p_sysent->sv_coaccept_base,
		    td->td_proc->p_sysent->sv_coaccept_len, 0);
		codecap = cheri_seal(codecap, switcher_sealcap);
		error = copyoutcap_c(&codecap, __USER_CAP(uap->code, sizeof(codecap)), sizeof(codecap));
		if (error != 0)
			return (error);

		cheri_capability_set(&datacap,
		    CHERI_CAP_USER_DATA_PERMS, addr, PAGE_SIZE, 0);
		datacap = cheri_seal(datacap, switcher_sealcap);
		error = copyoutcap_c(&datacap, __USER_CAP(uap->data, sizeof(datacap)), sizeof(datacap));
		return (0);

	default:
		return (EINVAL);
	}
}

int
sys_coregister(struct thread *td, struct coregister_args *uap)
{
	struct vmspace *vmspace;
	struct coname *con;
	char name[PATH_MAX];
	void * __capability cap;
	vaddr_t addr;
	int error;

	vmspace = td->td_proc->p_vmspace;

	error = copyinstr(uap->name, name, sizeof(name), NULL);
	if (error != 0)
		return (error);

	if (strlen(name) == 0)
		return (EINVAL);

	if (strlen(name) >= PATH_MAX)
		return (ENAMETOOLONG);

	if (td->td_md.md_switcher_context == 0) {
		error = cosetup(td);
		if (error != 0)
			return (error);
	}

	addr = td->td_md.md_switcher_context;

	vm_map_lock(&vmspace->vm_map);
	LIST_FOREACH(con, &vmspace->vm_conames, c_next) {
		if (strcmp(name, con->c_name) == 0) {
			vm_map_unlock(&vmspace->vm_map);
			return (EEXIST);
		}
	}

	cheri_capability_set(&cap, CHERI_CAP_USER_DATA_PERMS, addr, PAGE_SIZE, 0);
	cap = cheri_seal(cap, switcher_sealcap2);

	if (uap->cap != NULL) {
		error = copyoutcap_c(&cap, __USER_CAP(uap->cap, sizeof(cap)), sizeof(cap));
		if (error != 0) {
			vm_map_unlock(&vmspace->vm_map);
			return (error);
		}
	}

	con = malloc(sizeof(struct coname), M_TEMP, M_WAITOK);
	con->c_name = strdup(name, M_TEMP);
	con->c_value = cap;
	LIST_INSERT_HEAD(&vmspace->vm_conames, con, c_next);
	vm_map_unlock(&vmspace->vm_map);

	return (0);
}

int
sys_colookup(struct thread *td, struct colookup_args *uap)
{
	struct vmspace *vmspace;
	const struct coname *con;
	char name[PATH_MAX];
	int error;

	vmspace = td->td_proc->p_vmspace;

	error = copyinstr(uap->name, name, sizeof(name), NULL);
	if (error != 0)
		return (error);

	vm_map_lock(&vmspace->vm_map);
	LIST_FOREACH(con, &vmspace->vm_conames, c_next) {
		if (strcmp(name, con->c_name) == 0)
			break;
	}

	if (con == NULL) {
		vm_map_unlock(&vmspace->vm_map);
		return (ESRCH);
	}

	error = copyoutcap_c(&con->c_value, __USER_CAP(uap->cap, sizeof(con->c_value)), sizeof(con->c_value));
	vm_map_unlock(&vmspace->vm_map);
	return (error);
}

int
sys_copark(struct thread *td, struct copark_args *uap)
{
	int error;

	//printf("%s: go, td %p!\n", __func__, td);

	mtx_lock(&switcher_lock);
	error = msleep(&td->td_md.md_switcher_context, &switcher_lock,
	    PPAUSE | PCATCH, "copark", 0);
	mtx_unlock(&switcher_lock);

	if (error == 0) {
		/*
		 * We got woken up.  This means we got our userspace thread back
		 * (its context is in our trapframe) and we can return with ERESTART,
		 * to "bounce back" and execute the syscall userspace requested.
		 */
		//printf("%s: got switched to, td %p, returning ERESTART\n", __func__, td);
		return (ERESTART);
	} else {
		//printf("%s: error %d, td %p\n", __func__, error, td);
	}

	return (error);
}
