/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $FreeBSD$
 */

const char *cheriabi_syscallnames[] = {
#if !defined(PAD64_REQUIRED) && (defined(__powerpc__) || defined(__mips__))
#define PAD64_REQUIRED
#endif
	"cheriabi_syscall",			/* 0 = cheriabi_syscall */
	"exit",			/* 1 = exit */
	"fork",			/* 2 = fork */
	"cheriabi_read",			/* 3 = cheriabi_read */
	"cheriabi_write",			/* 4 = cheriabi_write */
	"cheriabi_open",			/* 5 = cheriabi_open */
	"close",			/* 6 = close */
	"cheriabi_wait4",			/* 7 = cheriabi_wait4 */
	"obs_old",			/* 8 = obsolete old creat */
	"cheriabi_link",			/* 9 = cheriabi_link */
	"cheriabi_unlink",			/* 10 = cheriabi_unlink */
	"obs_execv",			/* 11 = obsolete execv */
	"cheriabi_chdir",			/* 12 = cheriabi_chdir */
	"fchdir",			/* 13 = fchdir */
	"obs_fbsd11_mknod",			/* 14 = obsolete fbsd11_mknod */
	"cheriabi_chmod",			/* 15 = cheriabi_chmod */
	"cheriabi_chown",			/* 16 = cheriabi_chown */
	"obs_obreak",			/* 17 = obsolete obreak */
	"obs_getstatfs",			/* 18 = obsolete getstatfs */
	"obs_lseek",			/* 19 = obsolete lseek */
	"getpid",			/* 20 = getpid */
	"cheriabi_mount",			/* 21 = cheriabi_mount */
	"cheriabi_unmount",			/* 22 = cheriabi_unmount */
	"setuid",			/* 23 = setuid */
	"getuid",			/* 24 = getuid */
	"geteuid",			/* 25 = geteuid */
	"ptrace",			/* 26 = ptrace */
	"cheriabi_recvmsg",			/* 27 = cheriabi_recvmsg */
	"cheriabi_sendmsg",			/* 28 = cheriabi_sendmsg */
	"recvfrom",			/* 29 = recvfrom */
	"accept",			/* 30 = accept */
	"getpeername",			/* 31 = getpeername */
	"getsockname",			/* 32 = getsockname */
	"cheriabi_access",			/* 33 = cheriabi_access */
	"cheriabi_chflags",			/* 34 = cheriabi_chflags */
	"fchflags",			/* 35 = fchflags */
	"sync",			/* 36 = sync */
	"kill",			/* 37 = kill */
	"obs_stat",			/* 38 = obsolete stat */
	"getppid",			/* 39 = getppid */
	"obs_lstat",			/* 40 = obsolete lstat */
	"dup",			/* 41 = dup */
	"obs_pipe",			/* 42 = obsolete pipe */
	"getegid",			/* 43 = getegid */
	"cheriabi_profil",			/* 44 = cheriabi_profil */
	"cheriabi_ktrace",			/* 45 = cheriabi_ktrace */
	"obs_sigaction",			/* 46 = obsolete sigaction */
	"getgid",			/* 47 = getgid */
	"obs_sigprocmask",			/* 48 = obsolete sigprocmask */
	"cheriabi_getlogin",			/* 49 = cheriabi_getlogin */
	"cheriabi_setlogin",			/* 50 = cheriabi_setlogin */
	"cheriabi_acct",			/* 51 = cheriabi_acct */
	"obs_sigpending",			/* 52 = obsolete sigpending */
	"cheriabi_sigaltstack",			/* 53 = cheriabi_sigaltstack */
	"cheriabi_ioctl",			/* 54 = cheriabi_ioctl */
	"reboot",			/* 55 = reboot */
	"cheriabi_revoke",			/* 56 = cheriabi_revoke */
	"cheriabi_symlink",			/* 57 = cheriabi_symlink */
	"cheriabi_readlink",			/* 58 = cheriabi_readlink */
	"cheriabi_execve",			/* 59 = cheriabi_execve */
	"umask",			/* 60 = umask */
	"cheriabi_chroot",			/* 61 = cheriabi_chroot */
	"obs_fstat",			/* 62 = obsolete fstat */
	"obs_ogetkerninfo",			/* 63 = obsolete ogetkerninfo */
	"obs_getpagesize",			/* 64 = obsolete getpagesize */
	"msync",			/* 65 = msync */
	"vfork",			/* 66 = vfork */
	"obs_vread",			/* 67 = obsolete vread */
	"obs_vwrite",			/* 68 = obsolete vwrite */
	"obs_sbrk",			/* 69 = obsolete sbrk */
	"obs_sstk",			/* 70 = obsolete sstk */
	"obs_mmap",			/* 71 = obsolete mmap */
	"obs_ovadvise",			/* 72 = obsolete ovadvise */
	"munmap",			/* 73 = munmap */
	"cheriabi_mprotect",			/* 74 = cheriabi_mprotect */
	"cheriabi_madvise",			/* 75 = cheriabi_madvise */
	"obs_vhangup",			/* 76 = obsolete vhangup */
	"obs_vlimit",			/* 77 = obsolete vlimit */
	"cheriabi_mincore",			/* 78 = cheriabi_mincore */
	"cheriabi_getgroups",			/* 79 = cheriabi_getgroups */
	"cheriabi_setgroups",			/* 80 = cheriabi_setgroups */
	"getpgrp",			/* 81 = getpgrp */
	"setpgid",			/* 82 = setpgid */
	"cheriabi_setitimer",			/* 83 = cheriabi_setitimer */
	"obs_owait",			/* 84 = obsolete owait */
	"cheriabi_swapon",			/* 85 = cheriabi_swapon */
	"cheriabi_getitimer",			/* 86 = cheriabi_getitimer */
	"obs_ogethostname",			/* 87 = obsolete ogethostname */
	"obs_osethostname",			/* 88 = obsolete osethostname */
	"getdtablesize",			/* 89 = getdtablesize */
	"dup2",			/* 90 = dup2 */
	"#91",			/* 91 = getdopt */
	"fcntl",			/* 92 = fcntl */
	"cheriabi_select",			/* 93 = cheriabi_select */
	"#94",			/* 94 = setdopt */
	"fsync",			/* 95 = fsync */
	"setpriority",			/* 96 = setpriority */
	"socket",			/* 97 = socket */
	"connect",			/* 98 = connect */
	"obs_oaccept",			/* 99 = obsolete oaccept */
	"getpriority",			/* 100 = getpriority */
	"obs_osend",			/* 101 = obsolete osend */
	"obs_orecv",			/* 102 = obsolete orecv */
	"obs_sigreturn",			/* 103 = obsolete sigreturn */
	"bind",			/* 104 = bind */
	"setsockopt",			/* 105 = setsockopt */
	"listen",			/* 106 = listen */
	"obs_vtimes",			/* 107 = obsolete vtimes */
	"obs_sigvec",			/* 108 = obsolete sigvec */
	"obs_sigblock",			/* 109 = obsolete sigblock */
	"obs_sigsetmask",			/* 110 = obsolete sigsetmask */
	"obs_sigsuspend",			/* 111 = obsolete sigsuspend */
	"obs_sigstack",			/* 112 = obsolete sigstack */
	"obs_orecvmsg",			/* 113 = obsolete orecvmsg */
	"obs_osendmsg",			/* 114 = obsolete osendmsg */
	"obs_vtrace",			/* 115 = obsolete vtrace */
	"cheriabi_gettimeofday",			/* 116 = cheriabi_gettimeofday */
	"cheriabi_getrusage",			/* 117 = cheriabi_getrusage */
	"getsockopt",			/* 118 = getsockopt */
	"#119",			/* 119 = resuba */
	"cheriabi_readv",			/* 120 = cheriabi_readv */
	"cheriabi_writev",			/* 121 = cheriabi_writev */
	"cheriabi_settimeofday",			/* 122 = cheriabi_settimeofday */
	"fchown",			/* 123 = fchown */
	"fchmod",			/* 124 = fchmod */
	"obs_orecvfrom",			/* 125 = obsolete orecvfrom */
	"setreuid",			/* 126 = setreuid */
	"setregid",			/* 127 = setregid */
	"cheriabi_rename",			/* 128 = cheriabi_rename */
	"obs_truncate",			/* 129 = obsolete truncate */
	"obs_ftruncate",			/* 130 = obsolete ftruncate */
	"flock",			/* 131 = flock */
	"cheriabi_mkfifo",			/* 132 = cheriabi_mkfifo */
	"sendto",			/* 133 = sendto */
	"shutdown",			/* 134 = shutdown */
	"socketpair",			/* 135 = socketpair */
	"cheriabi_mkdir",			/* 136 = cheriabi_mkdir */
	"cheriabi_rmdir",			/* 137 = cheriabi_rmdir */
	"cheriabi_utimes",			/* 138 = cheriabi_utimes */
	"obs_sigreturn",			/* 139 = obsolete sigreturn */
	"cheriabi_adjtime",			/* 140 = cheriabi_adjtime */
	"obs_ogetpeername",			/* 141 = obsolete ogetpeername */
	"obs_ogethostid",			/* 142 = obsolete ogethostid */
	"obs_sethostid",			/* 143 = obsolete sethostid */
	"obs_getrlimit",			/* 144 = obsolete getrlimit */
	"obs_setrlimit",			/* 145 = obsolete setrlimit */
	"obs_killpg",			/* 146 = obsolete killpg */
	"setsid",			/* 147 = setsid */
	"cheriabi_quotactl",			/* 148 = cheriabi_quotactl */
	"obs_oquota",			/* 149 = obsolete oquota */
	"obs_ogetsockname",			/* 150 = obsolete ogetsockname */
	"#151",			/* 151 = sem_lock */
	"#152",			/* 152 = sem_wakeup */
	"#153",			/* 153 = asyncdaemon */
	"cheriabi_nlm_syscall",			/* 154 = cheriabi_nlm_syscall */
	"cheriabi_nfssvc",			/* 155 = cheriabi_nfssvc */
	"obs_getdirentries",			/* 156 = obsolete getdirentries */
	"obs_statfs",			/* 157 = obsolete statfs */
	"obs_fstatfs",			/* 158 = obsolete fstatfs */
	"#159",			/* 159 = nosys */
	"cheriabi_lgetfh",			/* 160 = cheriabi_lgetfh */
	"cheriabi_getfh",			/* 161 = cheriabi_getfh */
	"obs_getdomainname",			/* 162 = obsolete getdomainname */
	"obs_setdomainname",			/* 163 = obsolete setdomainname */
	"obs_uname",			/* 164 = obsolete uname */
	"cheriabi_sysarch",			/* 165 = cheriabi_sysarch */
	"cheriabi_rtprio",			/* 166 = cheriabi_rtprio */
	"#167",			/* 167 = nosys */
	"#168",			/* 168 = nosys */
	"obs_semsys",			/* 169 = obsolete semsys */
	"obs_msgsys",			/* 170 = obsolete msgsys */
	"obs_shmsys",			/* 171 = obsolete shmsys */
	"#172",			/* 172 = nosys */
	"obs_pread",			/* 173 = obsolete pread */
	"obs_pwrite",			/* 174 = obsolete pwrite */
	"setfib",			/* 175 = setfib */
	"cheriabi_ntp_adjtime",			/* 176 = cheriabi_ntp_adjtime */
	"#177",			/* 177 = sfork */
	"#178",			/* 178 = getdescriptor */
	"#179",			/* 179 = setdescriptor */
	"#180",			/* 180 = nosys */
	"setgid",			/* 181 = setgid */
	"setegid",			/* 182 = setegid */
	"seteuid",			/* 183 = seteuid */
	"#184",			/* 184 = lfs_bmapv */
	"#185",			/* 185 = lfs_markv */
	"#186",			/* 186 = lfs_segclean */
	"#187",			/* 187 = lfs_segwait */
	"obs_fbsd11_stat",			/* 188 = obsolete fbsd11_stat */
	"obs_fbsd11_fstat",			/* 189 = obsolete fbsd11_fstat */
	"obs_fbsd11_lstat",			/* 190 = obsolete fbsd11_lstat */
	"cheriabi_pathconf",			/* 191 = cheriabi_pathconf */
	"fpathconf",			/* 192 = fpathconf */
	"#193",			/* 193 = nosys */
	"cheriabi_getrlimit",			/* 194 = cheriabi_getrlimit */
	"cheriabi_setrlimit",			/* 195 = cheriabi_setrlimit */
	"obs_fbsd11_getdirentries",			/* 196 = obsolete fbsd11_getdirentries */
	"obs_mmap",			/* 197 = obsolete mmap */
	"obs___syscall",			/* 198 = obsolete __syscall */
	"obs_lseek",			/* 199 = obsolete lseek */
	"obs_truncate",			/* 200 = obsolete truncate */
	"obs_ftruncate",			/* 201 = obsolete ftruncate */
	"__sysctl",			/* 202 = __sysctl */
	"mlock",			/* 203 = mlock */
	"munlock",			/* 204 = munlock */
	"cheriabi_undelete",			/* 205 = cheriabi_undelete */
	"cheriabi_futimes",			/* 206 = cheriabi_futimes */
	"getpgid",			/* 207 = getpgid */
	"#208",			/* 208 = newreboot */
	"cheriabi_poll",			/* 209 = cheriabi_poll */
	"lkmnosys",			/* 210 = lkmnosys */
	"lkmnosys",			/* 211 = lkmnosys */
	"lkmnosys",			/* 212 = lkmnosys */
	"lkmnosys",			/* 213 = lkmnosys */
	"lkmnosys",			/* 214 = lkmnosys */
	"lkmnosys",			/* 215 = lkmnosys */
	"lkmnosys",			/* 216 = lkmnosys */
	"lkmnosys",			/* 217 = lkmnosys */
	"lkmnosys",			/* 218 = lkmnosys */
	"lkmnosys",			/* 219 = lkmnosys */
	"obs___semctl",			/* 220 = obsolete __semctl */
	"semget",			/* 221 = semget */
	"cheriabi_semop",			/* 222 = cheriabi_semop */
	"#223",			/* 223 = semconfig */
	"obs_msgctl",			/* 224 = obsolete msgctl */
	"msgget",			/* 225 = msgget */
	"cheriabi_msgsnd",			/* 226 = cheriabi_msgsnd */
	"cheriabi_msgrcv",			/* 227 = cheriabi_msgrcv */
	"shmat",			/* 228 = shmat */
	"obs_shmctl",			/* 229 = obsolete shmctl */
	"shmdt",			/* 230 = shmdt */
	"shmget",			/* 231 = shmget */
	"cheriabi_clock_gettime",			/* 232 = cheriabi_clock_gettime */
	"cheriabi_clock_settime",			/* 233 = cheriabi_clock_settime */
	"cheriabi_clock_getres",			/* 234 = cheriabi_clock_getres */
	"cheriabi_ktimer_create",			/* 235 = cheriabi_ktimer_create */
	"ktimer_delete",			/* 236 = ktimer_delete */
	"cheriabi_ktimer_settime",			/* 237 = cheriabi_ktimer_settime */
	"cheriabi_ktimer_gettime",			/* 238 = cheriabi_ktimer_gettime */
	"ktimer_getoverrun",			/* 239 = ktimer_getoverrun */
	"cheriabi_nanosleep",			/* 240 = cheriabi_nanosleep */
	"cheriabi_ffclock_getcounter",			/* 241 = cheriabi_ffclock_getcounter */
	"cheriabi_ffclock_setestimate",			/* 242 = cheriabi_ffclock_setestimate */
	"cheriabi_ffclock_getestimate",			/* 243 = cheriabi_ffclock_getestimate */
	"cheriabi_clock_nanosleep",			/* 244 = cheriabi_clock_nanosleep */
	"#245",			/* 245 = nosys */
	"#246",			/* 246 = nosys */
	"cheriabi_clock_getcpuclockid2",			/* 247 = cheriabi_clock_getcpuclockid2 */
	"cheriabi_ntp_gettime",			/* 248 = cheriabi_ntp_gettime */
	"#249",			/* 249 = nosys */
	"minherit",			/* 250 = minherit */
	"rfork",			/* 251 = rfork */
	"#252",			/* 252 = openbsd_poll */
	"issetugid",			/* 253 = issetugid */
	"cheriabi_lchown",			/* 254 = cheriabi_lchown */
	"cheriabi_aio_read",			/* 255 = cheriabi_aio_read */
	"cheriabi_aio_write",			/* 256 = cheriabi_aio_write */
	"cheriabi_lio_listio",			/* 257 = cheriabi_lio_listio */
	"cheriabi_kbounce",			/* 258 = cheriabi_kbounce */
	"#259",			/* 259 = nosys */
	"#260",			/* 260 = nosys */
	"#261",			/* 261 = nosys */
	"#262",			/* 262 = nosys */
	"#263",			/* 263 = nosys */
	"#264",			/* 264 = nosys */
	"#265",			/* 265 = nosys */
	"#266",			/* 266 = nosys */
	"#267",			/* 267 = nosys */
	"#268",			/* 268 = nosys */
	"#269",			/* 269 = nosys */
	"#270",			/* 270 = nosys */
	"#271",			/* 271 = nosys */
	"obs_fbsd11_getdents",			/* 272 = obsolete fbsd11_getdents */
	"#273",			/* 273 = nosys */
	"cheriabi_lchmod",			/* 274 = cheriabi_lchmod */
	"#275",			/* 275 = netbsd_lchown */
	"cheriabi_lutimes",			/* 276 = cheriabi_lutimes */
	"#277",			/* 277 = netbsd_msync */
	"#278",			/* 278 = freebsd11_nstat */
	"#279",			/* 279 = freebsd11_nfstat */
	"#280",			/* 280 = freebsd11_nlstat */
	"#281",			/* 281 = nosys */
	"#282",			/* 282 = nosys */
	"#283",			/* 283 = nosys */
	"#284",			/* 284 = nosys */
	"#285",			/* 285 = nosys */
	"#286",			/* 286 = nosys */
	"#287",			/* 287 = nosys */
	"#288",			/* 288 = nosys */
	"cheriabi_preadv",			/* 289 = cheriabi_preadv */
	"cheriabi_pwritev",			/* 290 = cheriabi_pwritev */
	"#291",			/* 291 = nosys */
	"#292",			/* 292 = nosys */
	"#293",			/* 293 = nosys */
	"#294",			/* 294 = nosys */
	"#295",			/* 295 = nosys */
	"#296",			/* 296 = nosys */
	"obs_fhstatfs",			/* 297 = obsolete fhstatfs */
	"fhopen",			/* 298 = fhopen */
	"obs_fbsd11_fhstat",			/* 299 = obsolete fbsd11_fhstat */
	"modnext",			/* 300 = modnext */
	"modstat",			/* 301 = modstat */
	"modfnext",			/* 302 = modfnext */
	"modfind",			/* 303 = modfind */
	"cheriabi_kldload",			/* 304 = cheriabi_kldload */
	"kldunload",			/* 305 = kldunload */
	"cheriabi_kldfind",			/* 306 = cheriabi_kldfind */
	"kldnext",			/* 307 = kldnext */
	"cheriabi_kldstat",			/* 308 = cheriabi_kldstat */
	"kldfirstmod",			/* 309 = kldfirstmod */
	"getsid",			/* 310 = getsid */
	"setresuid",			/* 311 = setresuid */
	"setresgid",			/* 312 = setresgid */
	"obs_signanosleep",			/* 313 = obsolete signanosleep */
	"cheriabi_aio_return",			/* 314 = cheriabi_aio_return */
	"cheriabi_aio_suspend",			/* 315 = cheriabi_aio_suspend */
	"cheriabi_aio_cancel",			/* 316 = cheriabi_aio_cancel */
	"cheriabi_aio_error",			/* 317 = cheriabi_aio_error */
	"obs_oaio_read",			/* 318 = obsolete oaio_read */
	"obs_oaio_write",			/* 319 = obsolete oaio_write */
	"obs_olio_listio",			/* 320 = obsolete olio_listio */
	"obs_yield",			/* 321 = obsolete yield */
	"obs_thr_sleep",			/* 322 = obsolete thr_sleep */
	"obs_thr_wakeup",			/* 323 = obsolete thr_wakeup */
	"mlockall",			/* 324 = mlockall */
	"munlockall",			/* 325 = munlockall */
	"cheriabi___getcwd",			/* 326 = cheriabi___getcwd */
	"cheriabi_sched_setparam",			/* 327 = cheriabi_sched_setparam */
	"cheriabi_sched_getparam",			/* 328 = cheriabi_sched_getparam */
	"cheriabi_sched_setscheduler",			/* 329 = cheriabi_sched_setscheduler */
	"sched_getscheduler",			/* 330 = sched_getscheduler */
	"sched_yield",			/* 331 = sched_yield */
	"sched_get_priority_max",			/* 332 = sched_get_priority_max */
	"sched_get_priority_min",			/* 333 = sched_get_priority_min */
	"cheriabi_sched_rr_get_interval",			/* 334 = cheriabi_sched_rr_get_interval */
	"cheriabi_utrace",			/* 335 = cheriabi_utrace */
	"obs_sendfile",			/* 336 = obsolete sendfile */
	"cheriabi_kldsym",			/* 337 = cheriabi_kldsym */
	"cheriabi_jail",			/* 338 = cheriabi_jail */
	"#339",			/* 339 = nnpfs_syscall */
	"cheriabi_sigprocmask",			/* 340 = cheriabi_sigprocmask */
	"cheriabi_sigsuspend",			/* 341 = cheriabi_sigsuspend */
	"obs_sigaction",			/* 342 = obsolete sigaction */
	"cheriabi_sigpending",			/* 343 = cheriabi_sigpending */
	"obs_sigreturn",			/* 344 = obsolete sigreturn */
	"cheriabi_sigtimedwait",			/* 345 = cheriabi_sigtimedwait */
	"cheriabi_sigwaitinfo",			/* 346 = cheriabi_sigwaitinfo */
	"cheriabi___acl_get_file",			/* 347 = cheriabi___acl_get_file */
	"cheriabi___acl_set_file",			/* 348 = cheriabi___acl_set_file */
	"cheriabi___acl_get_fd",			/* 349 = cheriabi___acl_get_fd */
	"cheriabi___acl_set_fd",			/* 350 = cheriabi___acl_set_fd */
	"cheriabi___acl_delete_file",			/* 351 = cheriabi___acl_delete_file */
	"__acl_delete_fd",			/* 352 = __acl_delete_fd */
	"cheriabi___acl_aclcheck_file",			/* 353 = cheriabi___acl_aclcheck_file */
	"cheriabi___acl_aclcheck_fd",			/* 354 = cheriabi___acl_aclcheck_fd */
	"cheriabi_extattrctl",			/* 355 = cheriabi_extattrctl */
	"cheriabi_extattr_set_file",			/* 356 = cheriabi_extattr_set_file */
	"cheriabi_extattr_get_file",			/* 357 = cheriabi_extattr_get_file */
	"cheriabi_extattr_delete_file",			/* 358 = cheriabi_extattr_delete_file */
	"cheriabi_aio_waitcomplete",			/* 359 = cheriabi_aio_waitcomplete */
	"cheriabi_getresuid",			/* 360 = cheriabi_getresuid */
	"cheriabi_getresgid",			/* 361 = cheriabi_getresgid */
	"kqueue",			/* 362 = kqueue */
	"#363",			/* 363 = kevent11 */
	"#364",			/* 364 = __cap_get_proc */
	"#365",			/* 365 = __cap_set_proc */
	"#366",			/* 366 = __cap_get_fd */
	"#367",			/* 367 = __cap_get_file */
	"#368",			/* 368 = __cap_set_fd */
	"#369",			/* 369 = __cap_set_file */
	"#370",			/* 370 = nosys */
	"cheriabi_extattr_set_fd",			/* 371 = cheriabi_extattr_set_fd */
	"cheriabi_extattr_get_fd",			/* 372 = cheriabi_extattr_get_fd */
	"cheriabi_extattr_delete_fd",			/* 373 = cheriabi_extattr_delete_fd */
	"__setugid",			/* 374 = __setugid */
	"#375",			/* 375 = nfsclnt */
	"cheriabi_eaccess",			/* 376 = cheriabi_eaccess */
	"#377",			/* 377 = afs3_syscall */
	"cheriabi_nmount",			/* 378 = cheriabi_nmount */
	"obs_kse_exit",			/* 379 = obsolete kse_exit */
	"obs_kse_wakeup",			/* 380 = obsolete kse_wakeup */
	"obs_kse_create",			/* 381 = obsolete kse_create */
	"obs_kse_thr_interrupt",			/* 382 = obsolete kse_thr_interrupt */
	"obs_kse_release",			/* 383 = obsolete kse_release */
	"cheriabi___mac_get_proc",			/* 384 = cheriabi___mac_get_proc */
	"cheriabi___mac_set_proc",			/* 385 = cheriabi___mac_set_proc */
	"cheriabi___mac_get_fd",			/* 386 = cheriabi___mac_get_fd */
	"cheriabi___mac_get_file",			/* 387 = cheriabi___mac_get_file */
	"cheriabi___mac_set_fd",			/* 388 = cheriabi___mac_set_fd */
	"cheriabi___mac_set_file",			/* 389 = cheriabi___mac_set_file */
	"cheriabi_kenv",			/* 390 = cheriabi_kenv */
	"cheriabi_lchflags",			/* 391 = cheriabi_lchflags */
	"cheriabi_uuidgen",			/* 392 = cheriabi_uuidgen */
	"cheriabi_sendfile",			/* 393 = cheriabi_sendfile */
	"cheriabi_mac_syscall",			/* 394 = cheriabi_mac_syscall */
	"obs_fbsd11_getfsstat",			/* 395 = obsolete fbsd11_getfsstat */
	"obs_fbsd11_statfs",			/* 396 = obsolete fbsd11_statfs */
	"obs_fbsd11_ftatfs",			/* 397 = obsolete fbsd11_ftatfs */
	"obs_fbsd11_fhstat",			/* 398 = obsolete fbsd11_fhstat */
	"#399",			/* 399 = nosys */
	"obs_ksem_close",			/* 400 = obsolete ksem_close */
	"obs_ksem_post",			/* 401 = obsolete ksem_post */
	"obs_ksem_wait",			/* 402 = obsolete ksem_wait */
	"obs_ksem_trywait",			/* 403 = obsolete ksem_trywait */
	"obs_ksem_init",			/* 404 = obsolete ksem_init */
	"obs_ksem_open",			/* 405 = obsolete ksem_open */
	"obs_ksem_unlink",			/* 406 = obsolete ksem_unlink */
	"obs_ksem_getvalue",			/* 407 = obsolete ksem_getvalue */
	"obs_ksem_destroy",			/* 408 = obsolete ksem_destroy */
	"cheriabi___mac_get_pid",			/* 409 = cheriabi___mac_get_pid */
	"cheriabi___mac_get_link",			/* 410 = cheriabi___mac_get_link */
	"cheriabi___mac_set_link",			/* 411 = cheriabi___mac_set_link */
	"cheriabi_extattr_set_link",			/* 412 = cheriabi_extattr_set_link */
	"cheriabi_extattr_get_link",			/* 413 = cheriabi_extattr_get_link */
	"cheriabi_extattr_delete_link",			/* 414 = cheriabi_extattr_delete_link */
	"cheriabi___mac_execve",			/* 415 = cheriabi___mac_execve */
	"cheriabi_sigaction",			/* 416 = cheriabi_sigaction */
	"cheriabi_sigreturn",			/* 417 = cheriabi_sigreturn */
	"#418",			/* 418 = __xstat */
	"#419",			/* 419 = __xfstat */
	"#420",			/* 420 = __xlstat */
	"cheriabi_getcontext",			/* 421 = cheriabi_getcontext */
	"cheriabi_setcontext",			/* 422 = cheriabi_setcontext */
	"cheriabi_swapcontext",			/* 423 = cheriabi_swapcontext */
	"cheriabi_swapoff",			/* 424 = cheriabi_swapoff */
	"cheriabi___acl_get_link",			/* 425 = cheriabi___acl_get_link */
	"cheriabi___acl_set_link",			/* 426 = cheriabi___acl_set_link */
	"cheriabi___acl_delete_link",			/* 427 = cheriabi___acl_delete_link */
	"cheriabi___acl_aclcheck_link",			/* 428 = cheriabi___acl_aclcheck_link */
	"cheriabi_sigwait",			/* 429 = cheriabi_sigwait */
	"cheriabi_thr_create",			/* 430 = cheriabi_thr_create */
	"thr_exit",			/* 431 = thr_exit */
	"thr_self",			/* 432 = thr_self */
	"thr_kill",			/* 433 = thr_kill */
	"#434",			/* 434 = nosys */
	"#435",			/* 435 = nosys */
	"jail_attach",			/* 436 = jail_attach */
	"cheriabi_extattr_list_fd",			/* 437 = cheriabi_extattr_list_fd */
	"cheriabi_extattr_list_file",			/* 438 = cheriabi_extattr_list_file */
	"cheriabi_extattr_list_link",			/* 439 = cheriabi_extattr_list_link */
	"obs_kse_switchin",			/* 440 = obsolete kse_switchin */
	"ksem_timedwait",			/* 441 = ksem_timedwait */
	"thr_suspend",			/* 442 = thr_suspend */
	"thr_wake",			/* 443 = thr_wake */
	"kldunloadf",			/* 444 = kldunloadf */
	"audit",			/* 445 = audit */
	"cheriabi_auditon",			/* 446 = cheriabi_auditon */
	"getauid",			/* 447 = getauid */
	"setauid",			/* 448 = setauid */
	"getaudit",			/* 449 = getaudit */
	"setaudit",			/* 450 = setaudit */
	"getaudit_addr",			/* 451 = getaudit_addr */
	"setaudit_addr",			/* 452 = setaudit_addr */
	"auditctl",			/* 453 = auditctl */
	"_umtx_op",			/* 454 = _umtx_op */
	"cheriabi_thr_new",			/* 455 = cheriabi_thr_new */
	"cheriabi_sigqueue",			/* 456 = cheriabi_sigqueue */
	"kmq_open",			/* 457 = kmq_open */
	"kmq_setattr",			/* 458 = kmq_setattr */
	"kmq_timedreceive",			/* 459 = kmq_timedreceive */
	"kmq_timedsend",			/* 460 = kmq_timedsend */
	"cheriabi_kmq_notify",			/* 461 = cheriabi_kmq_notify */
	"kmq_unlink",			/* 462 = kmq_unlink */
	"cheriabi_abort2",			/* 463 = cheriabi_abort2 */
	"thr_set_name",			/* 464 = thr_set_name */
	"cheriabi_aio_fsync",			/* 465 = cheriabi_aio_fsync */
	"cheriabi_rtprio_thread",			/* 466 = cheriabi_rtprio_thread */
	"#467",			/* 467 = nosys */
	"#468",			/* 468 = nosys */
	"#469",			/* 469 = __getpath_fromfd */
	"#470",			/* 470 = __getpath_fromaddr */
	"sctp_peeloff",			/* 471 = sctp_peeloff */
	"sctp_generic_sendmsg",			/* 472 = sctp_generic_sendmsg */
	"sctp_generic_sendmsg_iov",			/* 473 = sctp_generic_sendmsg_iov */
	"sctp_generic_recvmsg",			/* 474 = sctp_generic_recvmsg */
	"cheriabi_pread",			/* 475 = cheriabi_pread */
	"cheriabi_pwrite",			/* 476 = cheriabi_pwrite */
	"cheriabi_mmap",			/* 477 = cheriabi_mmap */
	"lseek",			/* 478 = lseek */
	"cheriabi_truncate",			/* 479 = cheriabi_truncate */
	"ftruncate",			/* 480 = ftruncate */
	"thr_kill2",			/* 481 = thr_kill2 */
	"cheriabi_shm_open",			/* 482 = cheriabi_shm_open */
	"cheriabi_shm_unlink",			/* 483 = cheriabi_shm_unlink */
	"cheriabi_cpuset",			/* 484 = cheriabi_cpuset */
	"cpuset_setid",			/* 485 = cpuset_setid */
	"cheriabi_cpuset_getid",			/* 486 = cheriabi_cpuset_getid */
	"cheriabi_cpuset_getaffinity",			/* 487 = cheriabi_cpuset_getaffinity */
	"cheriabi_cpuset_setaffinity",			/* 488 = cheriabi_cpuset_setaffinity */
	"cheriabi_faccessat",			/* 489 = cheriabi_faccessat */
	"cheriabi_fchmodat",			/* 490 = cheriabi_fchmodat */
	"cheriabi_fchownat",			/* 491 = cheriabi_fchownat */
	"cheriabi_fexecve",			/* 492 = cheriabi_fexecve */
	"obs_fbsd11_fstatat",			/* 493 = obsolete fbsd11_fstatat */
	"cheriabi_futimesat",			/* 494 = cheriabi_futimesat */
	"cheriabi_linkat",			/* 495 = cheriabi_linkat */
	"cheriabi_mkdirat",			/* 496 = cheriabi_mkdirat */
	"cheriabi_mkfifoat",			/* 497 = cheriabi_mkfifoat */
	"obs_fbsd11_mknodat",			/* 498 = obsolete fbsd11_mknodat */
	"cheriabi_openat",			/* 499 = cheriabi_openat */
	"cheriabi_readlinkat",			/* 500 = cheriabi_readlinkat */
	"cheriabi_renameat",			/* 501 = cheriabi_renameat */
	"cheriabi_symlinkat",			/* 502 = cheriabi_symlinkat */
	"cheriabi_unlinkat",			/* 503 = cheriabi_unlinkat */
	"posix_openpt",			/* 504 = posix_openpt */
	"cheriabi_gssd_syscall",			/* 505 = cheriabi_gssd_syscall */
	"cheriabi_jail_get",			/* 506 = cheriabi_jail_get */
	"cheriabi_jail_set",			/* 507 = cheriabi_jail_set */
	"jail_remove",			/* 508 = jail_remove */
	"closefrom",			/* 509 = closefrom */
	"cheriabi___semctl",			/* 510 = cheriabi___semctl */
	"cheriabi_msgctl",			/* 511 = cheriabi_msgctl */
	"cheriabi_shmctl",			/* 512 = cheriabi_shmctl */
	"cheriabi_lpathconf",			/* 513 = cheriabi_lpathconf */
	"obs_cap_new",			/* 514 = obsolete cap_new */
	"__cap_rights_get",			/* 515 = __cap_rights_get */
	"cap_enter",			/* 516 = cap_enter */
	"cap_getmode",			/* 517 = cap_getmode */
	"cheriabi_pdfork",			/* 518 = cheriabi_pdfork */
	"pdkill",			/* 519 = pdkill */
	"cheriabi_pdgetpid",			/* 520 = cheriabi_pdgetpid */
	"#521",			/* 521 = pdwait4 */
	"cheriabi_pselect",			/* 522 = cheriabi_pselect */
	"cheriabi_getloginclass",			/* 523 = cheriabi_getloginclass */
	"cheriabi_setloginclass",			/* 524 = cheriabi_setloginclass */
	"rctl_get_racct",			/* 525 = rctl_get_racct */
	"rctl_get_rules",			/* 526 = rctl_get_rules */
	"rctl_get_limits",			/* 527 = rctl_get_limits */
	"rctl_add_rule",			/* 528 = rctl_add_rule */
	"rctl_remove_rule",			/* 529 = rctl_remove_rule */
	"posix_fallocate",			/* 530 = posix_fallocate */
	"posix_fadvise",			/* 531 = posix_fadvise */
	"cheriabi_wait6",			/* 532 = cheriabi_wait6 */
	"cap_rights_limit",			/* 533 = cap_rights_limit */
	"cap_ioctls_limit",			/* 534 = cap_ioctls_limit */
	"cap_ioctls_get",			/* 535 = cap_ioctls_get */
	"cap_fcntls_limit",			/* 536 = cap_fcntls_limit */
	"cap_fcntls_get",			/* 537 = cap_fcntls_get */
	"bindat",			/* 538 = bindat */
	"connectat",			/* 539 = connectat */
	"cheriabi_chflagsat",			/* 540 = cheriabi_chflagsat */
	"accept4",			/* 541 = accept4 */
	"cheriabi_pipe2",			/* 542 = cheriabi_pipe2 */
	"cheriabi_aio_mlock",			/* 543 = cheriabi_aio_mlock */
	"cheriabi_procctl",			/* 544 = cheriabi_procctl */
	"cheriabi_ppoll",			/* 545 = cheriabi_ppoll */
	"cheriabi_futimens",			/* 546 = cheriabi_futimens */
	"cheriabi_utimensat",			/* 547 = cheriabi_utimensat */
	"#548",			/* 548 = freebsd11_numa_getaffinity */
	"#549",			/* 549 = freebsd11_numa_setaffinity */
	"fdatasync",			/* 550 = fdatasync */
	"fstat",			/* 551 = fstat */
	"fstatat",			/* 552 = fstatat */
	"fhstat",			/* 553 = fhstat */
	"getdirentries",			/* 554 = getdirentries */
	"statfs",			/* 555 = statfs */
	"fstatfs",			/* 556 = fstatfs */
	"getfsstat",			/* 557 = getfsstat */
	"fhstatfs",			/* 558 = fhstatfs */
	"cheriabi_mknodat",			/* 559 = cheriabi_mknodat */
	"cheriabi_kevent",			/* 560 = cheriabi_kevent */
};
