/*
 * Dispatch function to fill syscall uap structs.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 */

#ifndef _SYS_COMPAT_CHERIABI_DISPATCH_FILL_UAP_H_
#define	_SYS_COMPAT_CHERIABI_DISPATCH_FILL_UAP_H_

typedef int(*fill_uap_fp)(struct thread *, void *);

static int
nop_fill_uap(struct thread *td __unused, void *uap __unused)
{

	return (0);
}

static fill_uap_fp cheriabi_fill_uap_funcs[CHERIABI_SYS_MAXSYSCALL] = {
	[CHERIABI_SYS_cheriabi_syscall] = (fill_uap_fp)CHERIABI_SYS_cheriabi_syscall_fill_uap,
	[CHERIABI_SYS_exit] = (fill_uap_fp)CHERIABI_SYS_exit_fill_uap,
	[CHERIABI_SYS_fork] = nop_fill_uap,
	[CHERIABI_SYS_read] = (fill_uap_fp)CHERIABI_SYS_read_fill_uap,
	[CHERIABI_SYS_write] = (fill_uap_fp)CHERIABI_SYS_write_fill_uap,
	[CHERIABI_SYS_cheriabi_open] = (fill_uap_fp)CHERIABI_SYS_cheriabi_open_fill_uap,
	[CHERIABI_SYS_close] = (fill_uap_fp)CHERIABI_SYS_close_fill_uap,
	[CHERIABI_SYS_wait4] = (fill_uap_fp)CHERIABI_SYS_wait4_fill_uap,
	[CHERIABI_SYS_cheriabi_link] = (fill_uap_fp)CHERIABI_SYS_cheriabi_link_fill_uap,
	[CHERIABI_SYS_unlink] = (fill_uap_fp)CHERIABI_SYS_unlink_fill_uap,
	[CHERIABI_SYS_chdir] = (fill_uap_fp)CHERIABI_SYS_chdir_fill_uap,
	[CHERIABI_SYS_fchdir] = (fill_uap_fp)CHERIABI_SYS_fchdir_fill_uap,
	[CHERIABI_SYS_chmod] = (fill_uap_fp)CHERIABI_SYS_chmod_fill_uap,
	[CHERIABI_SYS_chown] = (fill_uap_fp)CHERIABI_SYS_chown_fill_uap,
	[CHERIABI_SYS_getpid] = nop_fill_uap,
	[CHERIABI_SYS_cheriabi_mount] = (fill_uap_fp)CHERIABI_SYS_cheriabi_mount_fill_uap,
	[CHERIABI_SYS_unmount] = (fill_uap_fp)CHERIABI_SYS_unmount_fill_uap,
	[CHERIABI_SYS_setuid] = (fill_uap_fp)CHERIABI_SYS_setuid_fill_uap,
	[CHERIABI_SYS_getuid] = nop_fill_uap,
	[CHERIABI_SYS_geteuid] = nop_fill_uap,
	[CHERIABI_SYS_ptrace] = (fill_uap_fp)CHERIABI_SYS_ptrace_fill_uap,
	[CHERIABI_SYS_cheriabi_recvmsg] = (fill_uap_fp)CHERIABI_SYS_cheriabi_recvmsg_fill_uap,
	[CHERIABI_SYS_cheriabi_sendmsg] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sendmsg_fill_uap,
	[CHERIABI_SYS_recvfrom] = (fill_uap_fp)CHERIABI_SYS_recvfrom_fill_uap,
	[CHERIABI_SYS_accept] = (fill_uap_fp)CHERIABI_SYS_accept_fill_uap,
	[CHERIABI_SYS_getpeername] = (fill_uap_fp)CHERIABI_SYS_getpeername_fill_uap,
	[CHERIABI_SYS_getsockname] = (fill_uap_fp)CHERIABI_SYS_getsockname_fill_uap,
	[CHERIABI_SYS_access] = (fill_uap_fp)CHERIABI_SYS_access_fill_uap,
	[CHERIABI_SYS_chflags] = (fill_uap_fp)CHERIABI_SYS_chflags_fill_uap,
	[CHERIABI_SYS_fchflags] = (fill_uap_fp)CHERIABI_SYS_fchflags_fill_uap,
	[CHERIABI_SYS_sync] = nop_fill_uap,
	[CHERIABI_SYS_kill] = (fill_uap_fp)CHERIABI_SYS_kill_fill_uap,
	[CHERIABI_SYS_getppid] = nop_fill_uap,
	[CHERIABI_SYS_dup] = (fill_uap_fp)CHERIABI_SYS_dup_fill_uap,
	[CHERIABI_SYS_getegid] = nop_fill_uap,
	[CHERIABI_SYS_profil] = (fill_uap_fp)CHERIABI_SYS_profil_fill_uap,
	[CHERIABI_SYS_ktrace] = (fill_uap_fp)CHERIABI_SYS_ktrace_fill_uap,
	[CHERIABI_SYS_getgid] = nop_fill_uap,
	[CHERIABI_SYS_getlogin] = (fill_uap_fp)CHERIABI_SYS_getlogin_fill_uap,
	[CHERIABI_SYS_setlogin] = (fill_uap_fp)CHERIABI_SYS_setlogin_fill_uap,
	[CHERIABI_SYS_acct] = (fill_uap_fp)CHERIABI_SYS_acct_fill_uap,
	[CHERIABI_SYS_cheriabi_sigaltstack] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigaltstack_fill_uap,
	[CHERIABI_SYS_cheriabi_ioctl] = (fill_uap_fp)CHERIABI_SYS_cheriabi_ioctl_fill_uap,
	[CHERIABI_SYS_reboot] = (fill_uap_fp)CHERIABI_SYS_reboot_fill_uap,
	[CHERIABI_SYS_revoke] = (fill_uap_fp)CHERIABI_SYS_revoke_fill_uap,
	[CHERIABI_SYS_symlink] = (fill_uap_fp)CHERIABI_SYS_symlink_fill_uap,
	[CHERIABI_SYS_readlink] = (fill_uap_fp)CHERIABI_SYS_readlink_fill_uap,
	[CHERIABI_SYS_cheriabi_execve] = (fill_uap_fp)CHERIABI_SYS_cheriabi_execve_fill_uap,
	[CHERIABI_SYS_umask] = (fill_uap_fp)CHERIABI_SYS_umask_fill_uap,
	[CHERIABI_SYS_chroot] = (fill_uap_fp)CHERIABI_SYS_chroot_fill_uap,
	[CHERIABI_SYS_msync] = (fill_uap_fp)CHERIABI_SYS_msync_fill_uap,
	[CHERIABI_SYS_vfork] = nop_fill_uap,
	[CHERIABI_SYS_munmap] = (fill_uap_fp)CHERIABI_SYS_munmap_fill_uap,
	[CHERIABI_SYS_cheriabi_mprotect] = (fill_uap_fp)CHERIABI_SYS_cheriabi_mprotect_fill_uap,
	[CHERIABI_SYS_cheriabi_madvise] = (fill_uap_fp)CHERIABI_SYS_cheriabi_madvise_fill_uap,
	[CHERIABI_SYS_mincore] = (fill_uap_fp)CHERIABI_SYS_mincore_fill_uap,
	[CHERIABI_SYS_getgroups] = (fill_uap_fp)CHERIABI_SYS_getgroups_fill_uap,
	[CHERIABI_SYS_setgroups] = (fill_uap_fp)CHERIABI_SYS_setgroups_fill_uap,
	[CHERIABI_SYS_getpgrp] = nop_fill_uap,
	[CHERIABI_SYS_setpgid] = (fill_uap_fp)CHERIABI_SYS_setpgid_fill_uap,
	[CHERIABI_SYS_setitimer] = (fill_uap_fp)CHERIABI_SYS_setitimer_fill_uap,
	[CHERIABI_SYS_swapon] = (fill_uap_fp)CHERIABI_SYS_swapon_fill_uap,
	[CHERIABI_SYS_getitimer] = (fill_uap_fp)CHERIABI_SYS_getitimer_fill_uap,
	[CHERIABI_SYS_getdtablesize] = nop_fill_uap,
	[CHERIABI_SYS_dup2] = (fill_uap_fp)CHERIABI_SYS_dup2_fill_uap,
	[CHERIABI_SYS_fcntl] = (fill_uap_fp)CHERIABI_SYS_fcntl_fill_uap,
	[CHERIABI_SYS_select] = (fill_uap_fp)CHERIABI_SYS_select_fill_uap,
	[CHERIABI_SYS_fsync] = (fill_uap_fp)CHERIABI_SYS_fsync_fill_uap,
	[CHERIABI_SYS_setpriority] = (fill_uap_fp)CHERIABI_SYS_setpriority_fill_uap,
	[CHERIABI_SYS_socket] = (fill_uap_fp)CHERIABI_SYS_socket_fill_uap,
	[CHERIABI_SYS_connect] = (fill_uap_fp)CHERIABI_SYS_connect_fill_uap,
	[CHERIABI_SYS_getpriority] = (fill_uap_fp)CHERIABI_SYS_getpriority_fill_uap,
	[CHERIABI_SYS_bind] = (fill_uap_fp)CHERIABI_SYS_bind_fill_uap,
	[CHERIABI_SYS_setsockopt] = (fill_uap_fp)CHERIABI_SYS_setsockopt_fill_uap,
	[CHERIABI_SYS_listen] = (fill_uap_fp)CHERIABI_SYS_listen_fill_uap,
	[CHERIABI_SYS_gettimeofday] = (fill_uap_fp)CHERIABI_SYS_gettimeofday_fill_uap,
	[CHERIABI_SYS_getrusage] = (fill_uap_fp)CHERIABI_SYS_getrusage_fill_uap,
	[CHERIABI_SYS_getsockopt] = (fill_uap_fp)CHERIABI_SYS_getsockopt_fill_uap,
	[CHERIABI_SYS_cheriabi_readv] = (fill_uap_fp)CHERIABI_SYS_cheriabi_readv_fill_uap,
	[CHERIABI_SYS_cheriabi_writev] = (fill_uap_fp)CHERIABI_SYS_cheriabi_writev_fill_uap,
	[CHERIABI_SYS_settimeofday] = (fill_uap_fp)CHERIABI_SYS_settimeofday_fill_uap,
	[CHERIABI_SYS_fchown] = (fill_uap_fp)CHERIABI_SYS_fchown_fill_uap,
	[CHERIABI_SYS_fchmod] = (fill_uap_fp)CHERIABI_SYS_fchmod_fill_uap,
	[CHERIABI_SYS_setreuid] = (fill_uap_fp)CHERIABI_SYS_setreuid_fill_uap,
	[CHERIABI_SYS_setregid] = (fill_uap_fp)CHERIABI_SYS_setregid_fill_uap,
	[CHERIABI_SYS_rename] = (fill_uap_fp)CHERIABI_SYS_rename_fill_uap,
	[CHERIABI_SYS_flock] = (fill_uap_fp)CHERIABI_SYS_flock_fill_uap,
	[CHERIABI_SYS_mkfifo] = (fill_uap_fp)CHERIABI_SYS_mkfifo_fill_uap,
	[CHERIABI_SYS_sendto] = (fill_uap_fp)CHERIABI_SYS_sendto_fill_uap,
	[CHERIABI_SYS_shutdown] = (fill_uap_fp)CHERIABI_SYS_shutdown_fill_uap,
	[CHERIABI_SYS_socketpair] = (fill_uap_fp)CHERIABI_SYS_socketpair_fill_uap,
	[CHERIABI_SYS_mkdir] = (fill_uap_fp)CHERIABI_SYS_mkdir_fill_uap,
	[CHERIABI_SYS_rmdir] = (fill_uap_fp)CHERIABI_SYS_rmdir_fill_uap,
	[CHERIABI_SYS_utimes] = (fill_uap_fp)CHERIABI_SYS_utimes_fill_uap,
	[CHERIABI_SYS_adjtime] = (fill_uap_fp)CHERIABI_SYS_adjtime_fill_uap,
	[CHERIABI_SYS_setsid] = nop_fill_uap,
	[CHERIABI_SYS_cheriabi_quotactl] = (fill_uap_fp)CHERIABI_SYS_cheriabi_quotactl_fill_uap,
	[CHERIABI_SYS_cheriabi_nlm_syscall] = (fill_uap_fp)CHERIABI_SYS_cheriabi_nlm_syscall_fill_uap,
	[CHERIABI_SYS_cheriabi_nfssvc] = (fill_uap_fp)CHERIABI_SYS_cheriabi_nfssvc_fill_uap,
	[CHERIABI_SYS_lgetfh] = (fill_uap_fp)CHERIABI_SYS_lgetfh_fill_uap,
	[CHERIABI_SYS_getfh] = (fill_uap_fp)CHERIABI_SYS_getfh_fill_uap,
	[CHERIABI_SYS_cheriabi_sysarch] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sysarch_fill_uap,
	[CHERIABI_SYS_rtprio] = (fill_uap_fp)CHERIABI_SYS_rtprio_fill_uap,
	[CHERIABI_SYS_setfib] = (fill_uap_fp)CHERIABI_SYS_setfib_fill_uap,
	[CHERIABI_SYS_ntp_adjtime] = (fill_uap_fp)CHERIABI_SYS_ntp_adjtime_fill_uap,
	[CHERIABI_SYS_setgid] = (fill_uap_fp)CHERIABI_SYS_setgid_fill_uap,
	[CHERIABI_SYS_setegid] = (fill_uap_fp)CHERIABI_SYS_setegid_fill_uap,
	[CHERIABI_SYS_seteuid] = (fill_uap_fp)CHERIABI_SYS_seteuid_fill_uap,
	[CHERIABI_SYS_pathconf] = (fill_uap_fp)CHERIABI_SYS_pathconf_fill_uap,
	[CHERIABI_SYS_fpathconf] = (fill_uap_fp)CHERIABI_SYS_fpathconf_fill_uap,
	[CHERIABI_SYS_getrlimit] = (fill_uap_fp)CHERIABI_SYS_getrlimit_fill_uap,
	[CHERIABI_SYS_setrlimit] = (fill_uap_fp)CHERIABI_SYS_setrlimit_fill_uap,
	[CHERIABI_SYS___sysctl] = (fill_uap_fp)CHERIABI_SYS___sysctl_fill_uap,
	[CHERIABI_SYS_mlock] = (fill_uap_fp)CHERIABI_SYS_mlock_fill_uap,
	[CHERIABI_SYS_munlock] = (fill_uap_fp)CHERIABI_SYS_munlock_fill_uap,
	[CHERIABI_SYS_undelete] = (fill_uap_fp)CHERIABI_SYS_undelete_fill_uap,
	[CHERIABI_SYS_futimes] = (fill_uap_fp)CHERIABI_SYS_futimes_fill_uap,
	[CHERIABI_SYS_getpgid] = (fill_uap_fp)CHERIABI_SYS_getpgid_fill_uap,
	[CHERIABI_SYS_poll] = (fill_uap_fp)CHERIABI_SYS_poll_fill_uap,
	[CHERIABI_SYS_semget] = (fill_uap_fp)CHERIABI_SYS_semget_fill_uap,
	[CHERIABI_SYS_semop] = (fill_uap_fp)CHERIABI_SYS_semop_fill_uap,
	[CHERIABI_SYS_msgget] = (fill_uap_fp)CHERIABI_SYS_msgget_fill_uap,
	[CHERIABI_SYS_msgsnd] = (fill_uap_fp)CHERIABI_SYS_msgsnd_fill_uap,
	[CHERIABI_SYS_msgrcv] = (fill_uap_fp)CHERIABI_SYS_msgrcv_fill_uap,
	[CHERIABI_SYS_shmat] = (fill_uap_fp)CHERIABI_SYS_shmat_fill_uap,
	[CHERIABI_SYS_shmdt] = (fill_uap_fp)CHERIABI_SYS_shmdt_fill_uap,
	[CHERIABI_SYS_shmget] = (fill_uap_fp)CHERIABI_SYS_shmget_fill_uap,
	[CHERIABI_SYS_clock_gettime] = (fill_uap_fp)CHERIABI_SYS_clock_gettime_fill_uap,
	[CHERIABI_SYS_clock_settime] = (fill_uap_fp)CHERIABI_SYS_clock_settime_fill_uap,
	[CHERIABI_SYS_clock_getres] = (fill_uap_fp)CHERIABI_SYS_clock_getres_fill_uap,
	[CHERIABI_SYS_cheriabi_ktimer_create] = (fill_uap_fp)CHERIABI_SYS_cheriabi_ktimer_create_fill_uap,
	[CHERIABI_SYS_ktimer_delete] = (fill_uap_fp)CHERIABI_SYS_ktimer_delete_fill_uap,
	[CHERIABI_SYS_ktimer_settime] = (fill_uap_fp)CHERIABI_SYS_ktimer_settime_fill_uap,
	[CHERIABI_SYS_ktimer_gettime] = (fill_uap_fp)CHERIABI_SYS_ktimer_gettime_fill_uap,
	[CHERIABI_SYS_ktimer_getoverrun] = (fill_uap_fp)CHERIABI_SYS_ktimer_getoverrun_fill_uap,
	[CHERIABI_SYS_nanosleep] = (fill_uap_fp)CHERIABI_SYS_nanosleep_fill_uap,
	[CHERIABI_SYS_ffclock_getcounter] = (fill_uap_fp)CHERIABI_SYS_ffclock_getcounter_fill_uap,
	[CHERIABI_SYS_ffclock_setestimate] = (fill_uap_fp)CHERIABI_SYS_ffclock_setestimate_fill_uap,
	[CHERIABI_SYS_ffclock_getestimate] = (fill_uap_fp)CHERIABI_SYS_ffclock_getestimate_fill_uap,
	[CHERIABI_SYS_clock_nanosleep] = (fill_uap_fp)CHERIABI_SYS_clock_nanosleep_fill_uap,
	[CHERIABI_SYS_clock_getcpuclockid2] = (fill_uap_fp)CHERIABI_SYS_clock_getcpuclockid2_fill_uap,
	[CHERIABI_SYS_ntp_gettime] = (fill_uap_fp)CHERIABI_SYS_ntp_gettime_fill_uap,
	[CHERIABI_SYS_minherit] = (fill_uap_fp)CHERIABI_SYS_minherit_fill_uap,
	[CHERIABI_SYS_rfork] = (fill_uap_fp)CHERIABI_SYS_rfork_fill_uap,
	[CHERIABI_SYS_issetugid] = nop_fill_uap,
	[CHERIABI_SYS_lchown] = (fill_uap_fp)CHERIABI_SYS_lchown_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_read] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_read_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_write] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_write_fill_uap,
	[CHERIABI_SYS_cheriabi_lio_listio] = (fill_uap_fp)CHERIABI_SYS_cheriabi_lio_listio_fill_uap,
	[CHERIABI_SYS_lchmod] = (fill_uap_fp)CHERIABI_SYS_lchmod_fill_uap,
	[CHERIABI_SYS_lutimes] = (fill_uap_fp)CHERIABI_SYS_lutimes_fill_uap,
	[CHERIABI_SYS_cheriabi_preadv] = (fill_uap_fp)CHERIABI_SYS_cheriabi_preadv_fill_uap,
	[CHERIABI_SYS_cheriabi_pwritev] = (fill_uap_fp)CHERIABI_SYS_cheriabi_pwritev_fill_uap,
	[CHERIABI_SYS_fhopen] = (fill_uap_fp)CHERIABI_SYS_fhopen_fill_uap,
	[CHERIABI_SYS_modnext] = (fill_uap_fp)CHERIABI_SYS_modnext_fill_uap,
	[CHERIABI_SYS_modstat] = (fill_uap_fp)CHERIABI_SYS_modstat_fill_uap,
	[CHERIABI_SYS_modfnext] = (fill_uap_fp)CHERIABI_SYS_modfnext_fill_uap,
	[CHERIABI_SYS_modfind] = (fill_uap_fp)CHERIABI_SYS_modfind_fill_uap,
	[CHERIABI_SYS_kldload] = (fill_uap_fp)CHERIABI_SYS_kldload_fill_uap,
	[CHERIABI_SYS_kldunload] = (fill_uap_fp)CHERIABI_SYS_kldunload_fill_uap,
	[CHERIABI_SYS_kldfind] = (fill_uap_fp)CHERIABI_SYS_kldfind_fill_uap,
	[CHERIABI_SYS_kldnext] = (fill_uap_fp)CHERIABI_SYS_kldnext_fill_uap,
	[CHERIABI_SYS_cheriabi_kldstat] = (fill_uap_fp)CHERIABI_SYS_cheriabi_kldstat_fill_uap,
	[CHERIABI_SYS_kldfirstmod] = (fill_uap_fp)CHERIABI_SYS_kldfirstmod_fill_uap,
	[CHERIABI_SYS_getsid] = (fill_uap_fp)CHERIABI_SYS_getsid_fill_uap,
	[CHERIABI_SYS_setresuid] = (fill_uap_fp)CHERIABI_SYS_setresuid_fill_uap,
	[CHERIABI_SYS_setresgid] = (fill_uap_fp)CHERIABI_SYS_setresgid_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_return] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_return_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_suspend] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_suspend_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_cancel] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_cancel_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_error] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_error_fill_uap,
	[CHERIABI_SYS_mlockall] = (fill_uap_fp)CHERIABI_SYS_mlockall_fill_uap,
	[CHERIABI_SYS_munlockall] = nop_fill_uap,
	[CHERIABI_SYS___getcwd] = (fill_uap_fp)CHERIABI_SYS___getcwd_fill_uap,
	[CHERIABI_SYS_sched_setparam] = (fill_uap_fp)CHERIABI_SYS_sched_setparam_fill_uap,
	[CHERIABI_SYS_sched_getparam] = (fill_uap_fp)CHERIABI_SYS_sched_getparam_fill_uap,
	[CHERIABI_SYS_sched_setscheduler] = (fill_uap_fp)CHERIABI_SYS_sched_setscheduler_fill_uap,
	[CHERIABI_SYS_sched_getscheduler] = (fill_uap_fp)CHERIABI_SYS_sched_getscheduler_fill_uap,
	[CHERIABI_SYS_sched_yield] = nop_fill_uap,
	[CHERIABI_SYS_sched_get_priority_max] = (fill_uap_fp)CHERIABI_SYS_sched_get_priority_max_fill_uap,
	[CHERIABI_SYS_sched_get_priority_min] = (fill_uap_fp)CHERIABI_SYS_sched_get_priority_min_fill_uap,
	[CHERIABI_SYS_sched_rr_get_interval] = (fill_uap_fp)CHERIABI_SYS_sched_rr_get_interval_fill_uap,
	[CHERIABI_SYS_utrace] = (fill_uap_fp)CHERIABI_SYS_utrace_fill_uap,
	[CHERIABI_SYS_cheriabi_kldsym] = (fill_uap_fp)CHERIABI_SYS_cheriabi_kldsym_fill_uap,
	[CHERIABI_SYS_cheriabi_jail] = (fill_uap_fp)CHERIABI_SYS_cheriabi_jail_fill_uap,
	[CHERIABI_SYS_sigprocmask] = (fill_uap_fp)CHERIABI_SYS_sigprocmask_fill_uap,
	[CHERIABI_SYS_sigsuspend] = (fill_uap_fp)CHERIABI_SYS_sigsuspend_fill_uap,
	[CHERIABI_SYS_sigpending] = (fill_uap_fp)CHERIABI_SYS_sigpending_fill_uap,
	[CHERIABI_SYS_cheriabi_sigtimedwait] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigtimedwait_fill_uap,
	[CHERIABI_SYS_cheriabi_sigwaitinfo] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigwaitinfo_fill_uap,
	[CHERIABI_SYS___acl_get_file] = (fill_uap_fp)CHERIABI_SYS___acl_get_file_fill_uap,
	[CHERIABI_SYS___acl_set_file] = (fill_uap_fp)CHERIABI_SYS___acl_set_file_fill_uap,
	[CHERIABI_SYS___acl_get_fd] = (fill_uap_fp)CHERIABI_SYS___acl_get_fd_fill_uap,
	[CHERIABI_SYS___acl_set_fd] = (fill_uap_fp)CHERIABI_SYS___acl_set_fd_fill_uap,
	[CHERIABI_SYS___acl_delete_file] = (fill_uap_fp)CHERIABI_SYS___acl_delete_file_fill_uap,
	[CHERIABI_SYS___acl_delete_fd] = (fill_uap_fp)CHERIABI_SYS___acl_delete_fd_fill_uap,
	[CHERIABI_SYS___acl_aclcheck_file] = (fill_uap_fp)CHERIABI_SYS___acl_aclcheck_file_fill_uap,
	[CHERIABI_SYS___acl_aclcheck_fd] = (fill_uap_fp)CHERIABI_SYS___acl_aclcheck_fd_fill_uap,
	[CHERIABI_SYS_extattrctl] = (fill_uap_fp)CHERIABI_SYS_extattrctl_fill_uap,
	[CHERIABI_SYS_extattr_set_file] = (fill_uap_fp)CHERIABI_SYS_extattr_set_file_fill_uap,
	[CHERIABI_SYS_extattr_get_file] = (fill_uap_fp)CHERIABI_SYS_extattr_get_file_fill_uap,
	[CHERIABI_SYS_extattr_delete_file] = (fill_uap_fp)CHERIABI_SYS_extattr_delete_file_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_waitcomplete] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_waitcomplete_fill_uap,
	[CHERIABI_SYS_getresuid] = (fill_uap_fp)CHERIABI_SYS_getresuid_fill_uap,
	[CHERIABI_SYS_getresgid] = (fill_uap_fp)CHERIABI_SYS_getresgid_fill_uap,
	[CHERIABI_SYS_kqueue] = nop_fill_uap,
	[CHERIABI_SYS_extattr_set_fd] = (fill_uap_fp)CHERIABI_SYS_extattr_set_fd_fill_uap,
	[CHERIABI_SYS_extattr_get_fd] = (fill_uap_fp)CHERIABI_SYS_extattr_get_fd_fill_uap,
	[CHERIABI_SYS_extattr_delete_fd] = (fill_uap_fp)CHERIABI_SYS_extattr_delete_fd_fill_uap,
	[CHERIABI_SYS___setugid] = (fill_uap_fp)CHERIABI_SYS___setugid_fill_uap,
	[CHERIABI_SYS_eaccess] = (fill_uap_fp)CHERIABI_SYS_eaccess_fill_uap,
	[CHERIABI_SYS_cheriabi_nmount] = (fill_uap_fp)CHERIABI_SYS_cheriabi_nmount_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_get_proc] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_get_proc_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_set_proc] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_set_proc_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_get_fd] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_get_fd_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_get_file] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_get_file_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_set_fd] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_set_fd_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_set_file] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_set_file_fill_uap,
	[CHERIABI_SYS_kenv] = (fill_uap_fp)CHERIABI_SYS_kenv_fill_uap,
	[CHERIABI_SYS_lchflags] = (fill_uap_fp)CHERIABI_SYS_lchflags_fill_uap,
	[CHERIABI_SYS_uuidgen] = (fill_uap_fp)CHERIABI_SYS_uuidgen_fill_uap,
	[CHERIABI_SYS_cheriabi_sendfile] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sendfile_fill_uap,
	[CHERIABI_SYS_cheriabi_mac_syscall] = (fill_uap_fp)CHERIABI_SYS_cheriabi_mac_syscall_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_get_pid] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_get_pid_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_get_link] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_get_link_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_set_link] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_set_link_fill_uap,
	[CHERIABI_SYS_extattr_set_link] = (fill_uap_fp)CHERIABI_SYS_extattr_set_link_fill_uap,
	[CHERIABI_SYS_extattr_get_link] = (fill_uap_fp)CHERIABI_SYS_extattr_get_link_fill_uap,
	[CHERIABI_SYS_extattr_delete_link] = (fill_uap_fp)CHERIABI_SYS_extattr_delete_link_fill_uap,
	[CHERIABI_SYS_cheriabi___mac_execve] = (fill_uap_fp)CHERIABI_SYS_cheriabi___mac_execve_fill_uap,
	[CHERIABI_SYS_cheriabi_sigaction] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigaction_fill_uap,
	[CHERIABI_SYS_cheriabi_sigreturn] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigreturn_fill_uap,
	[CHERIABI_SYS_cheriabi_getcontext] = (fill_uap_fp)CHERIABI_SYS_cheriabi_getcontext_fill_uap,
	[CHERIABI_SYS_cheriabi_setcontext] = (fill_uap_fp)CHERIABI_SYS_cheriabi_setcontext_fill_uap,
	[CHERIABI_SYS_cheriabi_swapcontext] = (fill_uap_fp)CHERIABI_SYS_cheriabi_swapcontext_fill_uap,
	[CHERIABI_SYS_swapoff] = (fill_uap_fp)CHERIABI_SYS_swapoff_fill_uap,
	[CHERIABI_SYS___acl_get_link] = (fill_uap_fp)CHERIABI_SYS___acl_get_link_fill_uap,
	[CHERIABI_SYS___acl_set_link] = (fill_uap_fp)CHERIABI_SYS___acl_set_link_fill_uap,
	[CHERIABI_SYS___acl_delete_link] = (fill_uap_fp)CHERIABI_SYS___acl_delete_link_fill_uap,
	[CHERIABI_SYS___acl_aclcheck_link] = (fill_uap_fp)CHERIABI_SYS___acl_aclcheck_link_fill_uap,
	[CHERIABI_SYS_sigwait] = (fill_uap_fp)CHERIABI_SYS_sigwait_fill_uap,
	[CHERIABI_SYS_cheriabi_thr_create] = (fill_uap_fp)CHERIABI_SYS_cheriabi_thr_create_fill_uap,
	[CHERIABI_SYS_thr_exit] = (fill_uap_fp)CHERIABI_SYS_thr_exit_fill_uap,
	[CHERIABI_SYS_thr_self] = (fill_uap_fp)CHERIABI_SYS_thr_self_fill_uap,
	[CHERIABI_SYS_thr_kill] = (fill_uap_fp)CHERIABI_SYS_thr_kill_fill_uap,
	[CHERIABI_SYS_jail_attach] = (fill_uap_fp)CHERIABI_SYS_jail_attach_fill_uap,
	[CHERIABI_SYS_extattr_list_fd] = (fill_uap_fp)CHERIABI_SYS_extattr_list_fd_fill_uap,
	[CHERIABI_SYS_extattr_list_file] = (fill_uap_fp)CHERIABI_SYS_extattr_list_file_fill_uap,
	[CHERIABI_SYS_extattr_list_link] = (fill_uap_fp)CHERIABI_SYS_extattr_list_link_fill_uap,
	[CHERIABI_SYS_ksem_timedwait] = (fill_uap_fp)CHERIABI_SYS_ksem_timedwait_fill_uap,
	[CHERIABI_SYS_thr_suspend] = (fill_uap_fp)CHERIABI_SYS_thr_suspend_fill_uap,
	[CHERIABI_SYS_thr_wake] = (fill_uap_fp)CHERIABI_SYS_thr_wake_fill_uap,
	[CHERIABI_SYS_kldunloadf] = (fill_uap_fp)CHERIABI_SYS_kldunloadf_fill_uap,
	[CHERIABI_SYS_audit] = (fill_uap_fp)CHERIABI_SYS_audit_fill_uap,
	[CHERIABI_SYS_cheriabi_auditon] = (fill_uap_fp)CHERIABI_SYS_cheriabi_auditon_fill_uap,
	[CHERIABI_SYS_getauid] = (fill_uap_fp)CHERIABI_SYS_getauid_fill_uap,
	[CHERIABI_SYS_setauid] = (fill_uap_fp)CHERIABI_SYS_setauid_fill_uap,
	[CHERIABI_SYS_getaudit] = (fill_uap_fp)CHERIABI_SYS_getaudit_fill_uap,
	[CHERIABI_SYS_setaudit] = (fill_uap_fp)CHERIABI_SYS_setaudit_fill_uap,
	[CHERIABI_SYS_getaudit_addr] = (fill_uap_fp)CHERIABI_SYS_getaudit_addr_fill_uap,
	[CHERIABI_SYS_setaudit_addr] = (fill_uap_fp)CHERIABI_SYS_setaudit_addr_fill_uap,
	[CHERIABI_SYS_auditctl] = (fill_uap_fp)CHERIABI_SYS_auditctl_fill_uap,
	[CHERIABI_SYS__umtx_op] = (fill_uap_fp)CHERIABI_SYS__umtx_op_fill_uap,
	[CHERIABI_SYS_cheriabi_thr_new] = (fill_uap_fp)CHERIABI_SYS_cheriabi_thr_new_fill_uap,
	[CHERIABI_SYS_cheriabi_sigqueue] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sigqueue_fill_uap,
	[CHERIABI_SYS_kmq_open] = (fill_uap_fp)CHERIABI_SYS_kmq_open_fill_uap,
	[CHERIABI_SYS_kmq_setattr] = (fill_uap_fp)CHERIABI_SYS_kmq_setattr_fill_uap,
	[CHERIABI_SYS_kmq_timedreceive] = (fill_uap_fp)CHERIABI_SYS_kmq_timedreceive_fill_uap,
	[CHERIABI_SYS_kmq_timedsend] = (fill_uap_fp)CHERIABI_SYS_kmq_timedsend_fill_uap,
	[CHERIABI_SYS_cheriabi_kmq_notify] = (fill_uap_fp)CHERIABI_SYS_cheriabi_kmq_notify_fill_uap,
	[CHERIABI_SYS_kmq_unlink] = (fill_uap_fp)CHERIABI_SYS_kmq_unlink_fill_uap,
	[CHERIABI_SYS_cheriabi_abort2] = (fill_uap_fp)CHERIABI_SYS_cheriabi_abort2_fill_uap,
	[CHERIABI_SYS_thr_set_name] = (fill_uap_fp)CHERIABI_SYS_thr_set_name_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_fsync] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_fsync_fill_uap,
	[CHERIABI_SYS_rtprio_thread] = (fill_uap_fp)CHERIABI_SYS_rtprio_thread_fill_uap,
	[CHERIABI_SYS_sctp_peeloff] = (fill_uap_fp)CHERIABI_SYS_sctp_peeloff_fill_uap,
	[CHERIABI_SYS_sctp_generic_sendmsg] = (fill_uap_fp)CHERIABI_SYS_sctp_generic_sendmsg_fill_uap,
	[CHERIABI_SYS_cheriabi_sctp_generic_sendmsg_iov] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sctp_generic_sendmsg_iov_fill_uap,
	[CHERIABI_SYS_cheriabi_sctp_generic_recvmsg] = (fill_uap_fp)CHERIABI_SYS_cheriabi_sctp_generic_recvmsg_fill_uap,
	[CHERIABI_SYS_pread] = (fill_uap_fp)CHERIABI_SYS_pread_fill_uap,
	[CHERIABI_SYS_pwrite] = (fill_uap_fp)CHERIABI_SYS_pwrite_fill_uap,
	[CHERIABI_SYS_cheriabi_mmap] = (fill_uap_fp)CHERIABI_SYS_cheriabi_mmap_fill_uap,
	[CHERIABI_SYS_lseek] = (fill_uap_fp)CHERIABI_SYS_lseek_fill_uap,
	[CHERIABI_SYS_truncate] = (fill_uap_fp)CHERIABI_SYS_truncate_fill_uap,
	[CHERIABI_SYS_ftruncate] = (fill_uap_fp)CHERIABI_SYS_ftruncate_fill_uap,
	[CHERIABI_SYS_thr_kill2] = (fill_uap_fp)CHERIABI_SYS_thr_kill2_fill_uap,
	[CHERIABI_SYS_shm_open] = (fill_uap_fp)CHERIABI_SYS_shm_open_fill_uap,
	[CHERIABI_SYS_shm_unlink] = (fill_uap_fp)CHERIABI_SYS_shm_unlink_fill_uap,
	[CHERIABI_SYS_cpuset] = (fill_uap_fp)CHERIABI_SYS_cpuset_fill_uap,
	[CHERIABI_SYS_cpuset_setid] = (fill_uap_fp)CHERIABI_SYS_cpuset_setid_fill_uap,
	[CHERIABI_SYS_cpuset_getid] = (fill_uap_fp)CHERIABI_SYS_cpuset_getid_fill_uap,
	[CHERIABI_SYS_cpuset_getaffinity] = (fill_uap_fp)CHERIABI_SYS_cpuset_getaffinity_fill_uap,
	[CHERIABI_SYS_cpuset_setaffinity] = (fill_uap_fp)CHERIABI_SYS_cpuset_setaffinity_fill_uap,
	[CHERIABI_SYS_faccessat] = (fill_uap_fp)CHERIABI_SYS_faccessat_fill_uap,
	[CHERIABI_SYS_fchmodat] = (fill_uap_fp)CHERIABI_SYS_fchmodat_fill_uap,
	[CHERIABI_SYS_fchownat] = (fill_uap_fp)CHERIABI_SYS_fchownat_fill_uap,
	[CHERIABI_SYS_cheriabi_fexecve] = (fill_uap_fp)CHERIABI_SYS_cheriabi_fexecve_fill_uap,
	[CHERIABI_SYS_futimesat] = (fill_uap_fp)CHERIABI_SYS_futimesat_fill_uap,
	[CHERIABI_SYS_cheriabi_linkat] = (fill_uap_fp)CHERIABI_SYS_cheriabi_linkat_fill_uap,
	[CHERIABI_SYS_mkdirat] = (fill_uap_fp)CHERIABI_SYS_mkdirat_fill_uap,
	[CHERIABI_SYS_mkfifoat] = (fill_uap_fp)CHERIABI_SYS_mkfifoat_fill_uap,
	[CHERIABI_SYS_cheriabi_openat] = (fill_uap_fp)CHERIABI_SYS_cheriabi_openat_fill_uap,
	[CHERIABI_SYS_readlinkat] = (fill_uap_fp)CHERIABI_SYS_readlinkat_fill_uap,
	[CHERIABI_SYS_renameat] = (fill_uap_fp)CHERIABI_SYS_renameat_fill_uap,
	[CHERIABI_SYS_symlinkat] = (fill_uap_fp)CHERIABI_SYS_symlinkat_fill_uap,
	[CHERIABI_SYS_unlinkat] = (fill_uap_fp)CHERIABI_SYS_unlinkat_fill_uap,
	[CHERIABI_SYS_posix_openpt] = (fill_uap_fp)CHERIABI_SYS_posix_openpt_fill_uap,
	[CHERIABI_SYS_gssd_syscall] = (fill_uap_fp)CHERIABI_SYS_gssd_syscall_fill_uap,
	[CHERIABI_SYS_cheriabi_jail_get] = (fill_uap_fp)CHERIABI_SYS_cheriabi_jail_get_fill_uap,
	[CHERIABI_SYS_cheriabi_jail_set] = (fill_uap_fp)CHERIABI_SYS_cheriabi_jail_set_fill_uap,
	[CHERIABI_SYS_jail_remove] = (fill_uap_fp)CHERIABI_SYS_jail_remove_fill_uap,
	[CHERIABI_SYS_closefrom] = (fill_uap_fp)CHERIABI_SYS_closefrom_fill_uap,
	[CHERIABI_SYS_cheriabi___semctl] = (fill_uap_fp)CHERIABI_SYS_cheriabi___semctl_fill_uap,
	[CHERIABI_SYS_cheriabi_msgctl] = (fill_uap_fp)CHERIABI_SYS_cheriabi_msgctl_fill_uap,
	[CHERIABI_SYS_shmctl] = (fill_uap_fp)CHERIABI_SYS_shmctl_fill_uap,
	[CHERIABI_SYS_lpathconf] = (fill_uap_fp)CHERIABI_SYS_lpathconf_fill_uap,
	[CHERIABI_SYS___cap_rights_get] = (fill_uap_fp)CHERIABI_SYS___cap_rights_get_fill_uap,
	[CHERIABI_SYS_cap_enter] = nop_fill_uap,
	[CHERIABI_SYS_cap_getmode] = (fill_uap_fp)CHERIABI_SYS_cap_getmode_fill_uap,
	[CHERIABI_SYS_pdfork] = (fill_uap_fp)CHERIABI_SYS_pdfork_fill_uap,
	[CHERIABI_SYS_pdkill] = (fill_uap_fp)CHERIABI_SYS_pdkill_fill_uap,
	[CHERIABI_SYS_pdgetpid] = (fill_uap_fp)CHERIABI_SYS_pdgetpid_fill_uap,
	[CHERIABI_SYS_pselect] = (fill_uap_fp)CHERIABI_SYS_pselect_fill_uap,
	[CHERIABI_SYS_getloginclass] = (fill_uap_fp)CHERIABI_SYS_getloginclass_fill_uap,
	[CHERIABI_SYS_setloginclass] = (fill_uap_fp)CHERIABI_SYS_setloginclass_fill_uap,
	[CHERIABI_SYS_rctl_get_racct] = (fill_uap_fp)CHERIABI_SYS_rctl_get_racct_fill_uap,
	[CHERIABI_SYS_rctl_get_rules] = (fill_uap_fp)CHERIABI_SYS_rctl_get_rules_fill_uap,
	[CHERIABI_SYS_rctl_get_limits] = (fill_uap_fp)CHERIABI_SYS_rctl_get_limits_fill_uap,
	[CHERIABI_SYS_rctl_add_rule] = (fill_uap_fp)CHERIABI_SYS_rctl_add_rule_fill_uap,
	[CHERIABI_SYS_rctl_remove_rule] = (fill_uap_fp)CHERIABI_SYS_rctl_remove_rule_fill_uap,
	[CHERIABI_SYS_posix_fallocate] = (fill_uap_fp)CHERIABI_SYS_posix_fallocate_fill_uap,
	[CHERIABI_SYS_posix_fadvise] = (fill_uap_fp)CHERIABI_SYS_posix_fadvise_fill_uap,
	[CHERIABI_SYS_cheriabi_wait6] = (fill_uap_fp)CHERIABI_SYS_cheriabi_wait6_fill_uap,
	[CHERIABI_SYS_cap_rights_limit] = (fill_uap_fp)CHERIABI_SYS_cap_rights_limit_fill_uap,
	[CHERIABI_SYS_cap_ioctls_limit] = (fill_uap_fp)CHERIABI_SYS_cap_ioctls_limit_fill_uap,
	[CHERIABI_SYS_cap_ioctls_get] = (fill_uap_fp)CHERIABI_SYS_cap_ioctls_get_fill_uap,
	[CHERIABI_SYS_cap_fcntls_limit] = (fill_uap_fp)CHERIABI_SYS_cap_fcntls_limit_fill_uap,
	[CHERIABI_SYS_cap_fcntls_get] = (fill_uap_fp)CHERIABI_SYS_cap_fcntls_get_fill_uap,
	[CHERIABI_SYS_bindat] = (fill_uap_fp)CHERIABI_SYS_bindat_fill_uap,
	[CHERIABI_SYS_connectat] = (fill_uap_fp)CHERIABI_SYS_connectat_fill_uap,
	[CHERIABI_SYS_chflagsat] = (fill_uap_fp)CHERIABI_SYS_chflagsat_fill_uap,
	[CHERIABI_SYS_accept4] = (fill_uap_fp)CHERIABI_SYS_accept4_fill_uap,
	[CHERIABI_SYS_pipe2] = (fill_uap_fp)CHERIABI_SYS_pipe2_fill_uap,
	[CHERIABI_SYS_cheriabi_aio_mlock] = (fill_uap_fp)CHERIABI_SYS_cheriabi_aio_mlock_fill_uap,
	[CHERIABI_SYS_cheriabi_procctl] = (fill_uap_fp)CHERIABI_SYS_cheriabi_procctl_fill_uap,
	[CHERIABI_SYS_ppoll] = (fill_uap_fp)CHERIABI_SYS_ppoll_fill_uap,
	[CHERIABI_SYS_futimens] = (fill_uap_fp)CHERIABI_SYS_futimens_fill_uap,
	[CHERIABI_SYS_utimensat] = (fill_uap_fp)CHERIABI_SYS_utimensat_fill_uap,
	[CHERIABI_SYS_numa_getaffinity] = (fill_uap_fp)CHERIABI_SYS_numa_getaffinity_fill_uap,
	[CHERIABI_SYS_numa_setaffinity] = (fill_uap_fp)CHERIABI_SYS_numa_setaffinity_fill_uap,
	[CHERIABI_SYS_fdatasync] = (fill_uap_fp)CHERIABI_SYS_fdatasync_fill_uap,
	[CHERIABI_SYS_fstat] = (fill_uap_fp)CHERIABI_SYS_fstat_fill_uap,
	[CHERIABI_SYS_fstatat] = (fill_uap_fp)CHERIABI_SYS_fstatat_fill_uap,
	[CHERIABI_SYS_fhstat] = (fill_uap_fp)CHERIABI_SYS_fhstat_fill_uap,
	[CHERIABI_SYS_getdirentries] = (fill_uap_fp)CHERIABI_SYS_getdirentries_fill_uap,
	[CHERIABI_SYS_statfs] = (fill_uap_fp)CHERIABI_SYS_statfs_fill_uap,
	[CHERIABI_SYS_fstatfs] = (fill_uap_fp)CHERIABI_SYS_fstatfs_fill_uap,
	[CHERIABI_SYS_getfsstat] = (fill_uap_fp)CHERIABI_SYS_getfsstat_fill_uap,
	[CHERIABI_SYS_fhstatfs] = (fill_uap_fp)CHERIABI_SYS_fhstatfs_fill_uap,
	[CHERIABI_SYS_mknodat] = (fill_uap_fp)CHERIABI_SYS_mknodat_fill_uap,
	[CHERIABI_SYS_cheriabi_kevent] = (fill_uap_fp)CHERIABI_SYS_cheriabi_kevent_fill_uap,
};

static inline int
cheriabi_dispatch_fill_uap(struct thread *td, int syscall, void *uap)
{

	if (syscall < 0 || syscall >= CHERIABI_SYS_MAXSYSCALL)
		return (ENOSYS);

	if (cheriabi_fill_uap_funcs[syscall] != NULL)
		return (cheriabi_fill_uap_funcs[syscall](td, uap));
	else
		return(ENOSYS);
}

#endif /* !_SYS_COMPAT_CHERIABI_DISPATCH_FILL_UAP_H_ */
