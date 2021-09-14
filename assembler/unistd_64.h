/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 18:06:12 CST. */


/**
 *	/usr/include/asm/unistd_64.h
 */
#ifndef _ASM_X86_UNISTD_64_H
#define _ASM_X86_UNISTD_64_H 1

#define __NR_read 0
#define __NR_write 1
#define __NR_open 2
#define __NR_close 3
#define __NR_stat 4
#define __NR_fstat 5
#define __NR_lstat 6
#define __NR_poll 7
#define __NR_lseek 8
#define __NR_mmap 9
#define __NR_mprotect 10
#define __NR_munmap 11
#define __NR_brk 12
#define __NR_rt_sigaction 13
#define __NR_rt_sigprocmask 14
#define __NR_rt_sigreturn 15
#define __NR_ioctl 16
#define __NR_pread64 17
#define __NR_pwrite64 18
#define __NR_readv 19
#define __NR_writev 20
#define __NR_access 21
#define __NR_pipe 22
#define __NR_select 23
#define __NR_sched_yield 24
#define __NR_mremap 25
#define __NR_msync 26
#define __NR_mincore 27
#define __NR_madvise 28
#define __NR_shmget 29
#define __NR_shmat 30
#define __NR_shmctl 31
#define __NR_dup 32
#define __NR_dup2 33
#define __NR_pause 34
#define __NR_nanosleep 35
#define __NR_getitimer 36
#define __NR_alarm 37
#define __NR_setitimer 38
#define __NR_getpid 39
#define __NR_sendfile 40
#define __NR_socket 41
#define __NR_connect 42
#define __NR_accept 43
#define __NR_sendto 44
#define __NR_recvfrom 45
#define __NR_sendmsg 46
#define __NR_recvmsg 47
#define __NR_shutdown 48
#define __NR_bind 49
#define __NR_listen 50
#define __NR_getsockname 51
#define __NR_getpeername 52
#define __NR_socketpair 53
#define __NR_setsockopt 54
#define __NR_getsockopt 55
#define __NR_clone 56
#define __NR_fork 57
#define __NR_vfork 58
#define __NR_execve 59
#define __NR_exit 60
#define __NR_wait4 61
#define __NR_kill 62
#define __NR_uname 63
#define __NR_semget 64
#define __NR_semop 65
#define __NR_semctl 66
#define __NR_shmdt 67
#define __NR_msgget 68
#define __NR_msgsnd 69
#define __NR_msgrcv 70
#define __NR_msgctl 71
#define __NR_fcntl 72
#define __NR_flock 73
#define __NR_fsync 74
#define __NR_fdatasync 75
#define __NR_truncate 76
#define __NR_ftruncate 77
#define __NR_getdents 78
#define __NR_getcwd 79
#define __NR_chdir 80
#define __NR_fchdir 81
#define __NR_rename 82
#define __NR_mkdir 83
#define __NR_rmdir 84
#define __NR_creat 85
#define __NR_link 86
#define __NR_unlink 87
#define __NR_symlink 88
#define __NR_readlink 89
#define __NR_chmod 90
#define __NR_fchmod 91
#define __NR_chown 92
#define __NR_fchown 93
#define __NR_lchown 94
#define __NR_umask 95
#define __NR_gettimeofday 96
#define __NR_getrlimit 97
#define __NR_getrusage 98
#define __NR_sysinfo 99
#define __NR_times 100
#define __NR_ptrace 101
#define __NR_getuid 102
#define __NR_syslog 103
#define __NR_getgid 104
#define __NR_setuid 105
#define __NR_setgid 106
#define __NR_geteuid 107
#define __NR_getegid 108
#define __NR_setpgid 109
#define __NR_getppid 110
#define __NR_getpgrp 111
#define __NR_setsid 112
#define __NR_setreuid 113
#define __NR_setregid 114
#define __NR_getgroups 115
#define __NR_setgroups 116
#define __NR_setresuid 117
#define __NR_getresuid 118
#define __NR_setresgid 119
#define __NR_getresgid 120
#define __NR_getpgid 121
#define __NR_setfsuid 122
#define __NR_setfsgid 123
#define __NR_getsid 124
#define __NR_capget 125
#define __NR_capset 126
#define __NR_rt_sigpending 127
#define __NR_rt_sigtimedwait 128
#define __NR_rt_sigqueueinfo 129
#define __NR_rt_sigsuspend 130
#define __NR_sigaltstack 131
#define __NR_utime 132
#define __NR_mknod 133
#define __NR_uselib 134
#define __NR_personality 135
#define __NR_ustat 136
#define __NR_statfs 137
#define __NR_fstatfs 138
#define __NR_sysfs 139
#define __NR_getpriority 140
#define __NR_setpriority 141
#define __NR_sched_setparam 142
#define __NR_sched_getparam 143
#define __NR_sched_setscheduler 144
#define __NR_sched_getscheduler 145
#define __NR_sched_get_priority_max 146
#define __NR_sched_get_priority_min 147
#define __NR_sched_rr_get_interval 148
#define __NR_mlock 149
#define __NR_munlock 150
#define __NR_mlockall 151
#define __NR_munlockall 152
#define __NR_vhangup 153
#define __NR_modify_ldt 154
#define __NR_pivot_root 155
#define __NR__sysctl 156
#define __NR_prctl 157
#define __NR_arch_prctl 158
#define __NR_adjtimex 159
#define __NR_setrlimit 160
#define __NR_chroot 161
#define __NR_sync 162
#define __NR_acct 163
#define __NR_settimeofday 164
#define __NR_mount 165
#define __NR_umount2 166
#define __NR_swapon 167
#define __NR_swapoff 168
#define __NR_reboot 169
#define __NR_sethostname 170
#define __NR_setdomainname 171
#define __NR_iopl 172
#define __NR_ioperm 173
#define __NR_create_module 174
#define __NR_init_module 175
#define __NR_delete_module 176
#define __NR_get_kernel_syms 177
#define __NR_query_module 178
#define __NR_quotactl 179
#define __NR_nfsservctl 180
#define __NR_getpmsg 181
#define __NR_putpmsg 182
#define __NR_afs_syscall 183
#define __NR_tuxcall 184
#define __NR_security 185
#define __NR_gettid 186
#define __NR_readahead 187
#define __NR_setxattr 188
#define __NR_lsetxattr 189
#define __NR_fsetxattr 190
#define __NR_getxattr 191
#define __NR_lgetxattr 192
#define __NR_fgetxattr 193
#define __NR_listxattr 194
#define __NR_llistxattr 195
#define __NR_flistxattr 196
#define __NR_removexattr 197
#define __NR_lremovexattr 198
#define __NR_fremovexattr 199
#define __NR_tkill 200
#define __NR_time 201
#define __NR_futex 202
#define __NR_sched_setaffinity 203
#define __NR_sched_getaffinity 204
#define __NR_set_thread_area 205
#define __NR_io_setup 206
#define __NR_io_destroy 207
#define __NR_io_getevents 208
#define __NR_io_submit 209
#define __NR_io_cancel 210
#define __NR_get_thread_area 211
#define __NR_lookup_dcookie 212
#define __NR_epoll_create 213
#define __NR_epoll_ctl_old 214
#define __NR_epoll_wait_old 215
#define __NR_remap_file_pages 216
#define __NR_getdents64 217
#define __NR_set_tid_address 218
#define __NR_restart_syscall 219
#define __NR_semtimedop 220
#define __NR_fadvise64 221
#define __NR_timer_create 222
#define __NR_timer_settime 223
#define __NR_timer_gettime 224
#define __NR_timer_getoverrun 225
#define __NR_timer_delete 226
#define __NR_clock_settime 227
#define __NR_clock_gettime 228
#define __NR_clock_getres 229
#define __NR_clock_nanosleep 230
#define __NR_exit_group 231
#define __NR_epoll_wait 232
#define __NR_epoll_ctl 233
#define __NR_tgkill 234
#define __NR_utimes 235
#define __NR_vserver 236
#define __NR_mbind 237
#define __NR_set_mempolicy 238
#define __NR_get_mempolicy 239
#define __NR_mq_open 240
#define __NR_mq_unlink 241
#define __NR_mq_timedsend 242
#define __NR_mq_timedreceive 243
#define __NR_mq_notify 244
#define __NR_mq_getsetattr 245
#define __NR_kexec_load 246
#define __NR_waitid 247
#define __NR_add_key 248
#define __NR_request_key 249
#define __NR_keyctl 250
#define __NR_ioprio_set 251
#define __NR_ioprio_get 252
#define __NR_inotify_init 253
#define __NR_inotify_add_watch 254
#define __NR_inotify_rm_watch 255
#define __NR_migrate_pages 256
#define __NR_openat 257
#define __NR_mkdirat 258
#define __NR_mknodat 259
#define __NR_fchownat 260
#define __NR_futimesat 261
#define __NR_newfstatat 262
#define __NR_unlinkat 263
#define __NR_renameat 264
#define __NR_linkat 265
#define __NR_symlinkat 266
#define __NR_readlinkat 267
#define __NR_fchmodat 268
#define __NR_faccessat 269
#define __NR_pselect6 270
#define __NR_ppoll 271
#define __NR_unshare 272
#define __NR_set_robust_list 273
#define __NR_get_robust_list 274
#define __NR_splice 275
#define __NR_tee 276
#define __NR_sync_file_range 277
#define __NR_vmsplice 278
#define __NR_move_pages 279
#define __NR_utimensat 280
#define __NR_epoll_pwait 281
#define __NR_signalfd 282
#define __NR_timerfd_create 283
#define __NR_eventfd 284
#define __NR_fallocate 285
#define __NR_timerfd_settime 286
#define __NR_timerfd_gettime 287
#define __NR_accept4 288
#define __NR_signalfd4 289
#define __NR_eventfd2 290
#define __NR_epoll_create1 291
#define __NR_dup3 292
#define __NR_pipe2 293
#define __NR_inotify_init1 294
#define __NR_preadv 295
#define __NR_pwritev 296
#define __NR_rt_tgsigqueueinfo 297
#define __NR_perf_event_open 298
#define __NR_recvmmsg 299
#define __NR_fanotify_init 300
#define __NR_fanotify_mark 301
#define __NR_prlimit64 302
#define __NR_name_to_handle_at 303
#define __NR_open_by_handle_at 304
#define __NR_clock_adjtime 305
#define __NR_syncfs 306
#define __NR_sendmmsg 307
#define __NR_setns 308
#define __NR_getcpu 309
#define __NR_process_vm_readv 310
#define __NR_process_vm_writev 311
#define __NR_kcmp 312
#define __NR_finit_module 313
#define __NR_sched_setattr 314
#define __NR_sched_getattr 315
#define __NR_renameat2 316
#define __NR_getrandom 318
#define __NR_memfd_create 319
#define __NR_kexec_file_load 320
#define __NR_userfaultfd 323
#define __NR_copy_file_range 326

#endif /* _ASM_X86_UNISTD_64_H */

fndef _ASM_X86_UNISTD_64_H
#define _ASM_X86_UNISTD_64_H

#ifndef __SYSCALL
#define __SYSCALL(a, b)
#endif

/*
 * * This file contains the system call numbers.
 * *
 * * Note: holes are not allowed.
 * */

/* at least 8 syscall per cacheline */
#define __NR_read				0
__SYSCALL(__NR_read, sys_read)
#define __NR_write				1
	__SYSCALL(__NR_write, sys_write)
#define __NR_open				2
	__SYSCALL(__NR_open, sys_open)
#define __NR_close				3
	__SYSCALL(__NR_close, sys_close)
#define __NR_stat				4
	__SYSCALL(__NR_stat, sys_newstat)
#define __NR_fstat				5
	__SYSCALL(__NR_fstat, sys_newfstat)
#define __NR_lstat				6
	__SYSCALL(__NR_lstat, sys_newlstat)
#define __NR_poll				7
	__SYSCALL(__NR_poll, sys_poll)

#define __NR_lseek				8
	__SYSCALL(__NR_lseek, sys_lseek)
#define __NR_mmap				9
	__SYSCALL(__NR_mmap, sys_mmap)
#define __NR_mprotect				10
	__SYSCALL(__NR_mprotect, sys_mprotect)
#define __NR_munmap				11
	__SYSCALL(__NR_munmap, sys_munmap)
#define __NR_brk				12
	__SYSCALL(__NR_brk, sys_brk)
#define __NR_rt_sigaction			13
	__SYSCALL(__NR_rt_sigaction, sys_rt_sigaction)
#define __NR_rt_sigprocmask			14
	__SYSCALL(__NR_rt_sigprocmask, sys_rt_sigprocmask)
#define __NR_rt_sigreturn			15
	__SYSCALL(__NR_rt_sigreturn, stub_rt_sigreturn)

#define __NR_ioctl				16
	__SYSCALL(__NR_ioctl, sys_ioctl)
#define __NR_pread64				17
	__SYSCALL(__NR_pread64, sys_pread64)
#define __NR_pwrite64				18
	__SYSCALL(__NR_pwrite64, sys_pwrite64)
#define __NR_readv				19
	__SYSCALL(__NR_readv, sys_readv)
#define __NR_writev				20
	__SYSCALL(__NR_writev, sys_writev)
#define __NR_access				21
	__SYSCALL(__NR_access, sys_access)
#define __NR_pipe				22
	__SYSCALL(__NR_pipe, sys_pipe)
#define __NR_select				23
	__SYSCALL(__NR_select, sys_select)

#define __NR_sched_yield			24
	__SYSCALL(__NR_sched_yield, sys_sched_yield)
#define __NR_mremap				25
	__SYSCALL(__NR_mremap, sys_mremap)
#define __NR_msync				26
	__SYSCALL(__NR_msync, sys_msync)
#define __NR_mincore				27
	__SYSCALL(__NR_mincore, sys_mincore)
#define __NR_madvise				28
	__SYSCALL(__NR_madvise, sys_madvise)
#define __NR_shmget				29
	__SYSCALL(__NR_shmget, sys_shmget)
#define __NR_shmat				30
	__SYSCALL(__NR_shmat, sys_shmat)
#define __NR_shmctl				31
	__SYSCALL(__NR_shmctl, sys_shmctl)

#define __NR_dup				32
	__SYSCALL(__NR_dup, sys_dup)
#define __NR_dup2				33
	__SYSCALL(__NR_dup2, sys_dup2)
#define __NR_pause				34
	__SYSCALL(__NR_pause, sys_pause)
#define __NR_nanosleep				35
	__SYSCALL(__NR_nanosleep, sys_nanosleep)
#define __NR_getitimer				36
	__SYSCALL(__NR_getitimer, sys_getitimer)
#define __NR_alarm				37
	__SYSCALL(__NR_alarm, sys_alarm)
#define __NR_setitimer				38
	__SYSCALL(__NR_setitimer, sys_setitimer)
#define __NR_getpid				39
	__SYSCALL(__NR_getpid, sys_getpid)

#define __NR_sendfile				40
	__SYSCALL(__NR_sendfile, sys_sendfile64)
#define __NR_socket				41
	__SYSCALL(__NR_socket, sys_socket)
#define __NR_connect				42
	__SYSCALL(__NR_connect, sys_connect)
#define __NR_accept				43
	__SYSCALL(__NR_accept, sys_accept)
#define __NR_sendto				44
	__SYSCALL(__NR_sendto, sys_sendto)
#define __NR_recvfrom				45
	__SYSCALL(__NR_recvfrom, sys_recvfrom)
#define __NR_sendmsg				46
	__SYSCALL(__NR_sendmsg, sys_sendmsg)
#define __NR_recvmsg				47
	__SYSCALL(__NR_recvmsg, sys_recvmsg)

#define __NR_shutdown				48
	__SYSCALL(__NR_shutdown, sys_shutdown)
#define __NR_bind				49
	__SYSCALL(__NR_bind, sys_bind)
#define __NR_listen				50
	__SYSCALL(__NR_listen, sys_listen)
#define __NR_getsockname			51
	__SYSCALL(__NR_getsockname, sys_getsockname)
#define __NR_getpeername			52
	__SYSCALL(__NR_getpeername, sys_getpeername)
#define __NR_socketpair				53
	__SYSCALL(__NR_socketpair, sys_socketpair)
#define __NR_setsockopt				54
	__SYSCALL(__NR_setsockopt, sys_setsockopt)
#define __NR_getsockopt				55
	__SYSCALL(__NR_getsockopt, sys_getsockopt)

#define __NR_clone				56
	__SYSCALL(__NR_clone, stub_clone)
#define __NR_fork				57
	__SYSCALL(__NR_fork, stub_fork)
#define __NR_vfork				58
	__SYSCALL(__NR_vfork, stub_vfork)
#define __NR_execve				59
	__SYSCALL(__NR_execve, stub_execve)
#define __NR_exit				60
	__SYSCALL(__NR_exit, sys_exit)
#define __NR_wait4				61
	__SYSCALL(__NR_wait4, sys_wait4)
#define __NR_kill				62
	__SYSCALL(__NR_kill, sys_kill)
#define __NR_uname				63
	__SYSCALL(__NR_uname, sys_newuname)

#define __NR_semget				64
	__SYSCALL(__NR_semget, sys_semget)
#define __NR_semop				65
	__SYSCALL(__NR_semop, sys_semop)
#define __NR_semctl				66
	__SYSCALL(__NR_semctl, sys_semctl)
#define __NR_shmdt				67
	__SYSCALL(__NR_shmdt, sys_shmdt)
#define __NR_msgget				68
	__SYSCALL(__NR_msgget, sys_msgget)
#define __NR_msgsnd				69
	__SYSCALL(__NR_msgsnd, sys_msgsnd)
#define __NR_msgrcv				70
	__SYSCALL(__NR_msgrcv, sys_msgrcv)
#define __NR_msgctl				71
	__SYSCALL(__NR_msgctl, sys_msgctl)

#define __NR_fcntl				72
	__SYSCALL(__NR_fcntl, sys_fcntl)
#define __NR_flock				73
	__SYSCALL(__NR_flock, sys_flock)
#define __NR_fsync				74
	__SYSCALL(__NR_fsync, sys_fsync)
#define __NR_fdatasync				75
	__SYSCALL(__NR_fdatasync, sys_fdatasync)
#define __NR_truncate				76
	__SYSCALL(__NR_truncate, sys_truncate)
#define __NR_ftruncate				77
	__SYSCALL(__NR_ftruncate, sys_ftruncate)
#define __NR_getdents				78
	__SYSCALL(__NR_getdents, sys_getdents)
#define __NR_getcwd				79
	__SYSCALL(__NR_getcwd, sys_getcwd)

#define __NR_chdir				80
	__SYSCALL(__NR_chdir, sys_chdir)
#define __NR_fchdir				81
	__SYSCALL(__NR_fchdir, sys_fchdir)
#define __NR_rename				82
	__SYSCALL(__NR_rename, sys_rename)
#define __NR_mkdir				83
	__SYSCALL(__NR_mkdir, sys_mkdir)
#define __NR_rmdir				84
	__SYSCALL(__NR_rmdir, sys_rmdir)
#define __NR_creat				85
	__SYSCALL(__NR_creat, sys_creat)
#define __NR_link				86
	__SYSCALL(__NR_link, sys_link)
#define __NR_unlink				87
	__SYSCALL(__NR_unlink, sys_unlink)

#define __NR_symlink				88
	__SYSCALL(__NR_symlink, sys_symlink)
#define __NR_readlink				89
	__SYSCALL(__NR_readlink, sys_readlink)
#define __NR_chmod				90
	__SYSCALL(__NR_chmod, sys_chmod)
#define __NR_fchmod				91
	__SYSCALL(__NR_fchmod, sys_fchmod)
#define __NR_chown				92
	__SYSCALL(__NR_chown, sys_chown)
#define __NR_fchown				93
	__SYSCALL(__NR_fchown, sys_fchown)
#define __NR_lchown				94
	__SYSCALL(__NR_lchown, sys_lchown)
#define __NR_umask				95
	__SYSCALL(__NR_umask, sys_umask)

#define __NR_gettimeofday			96
	__SYSCALL(__NR_gettimeofday, sys_gettimeofday)
#define __NR_getrlimit				97
	__SYSCALL(__NR_getrlimit, sys_getrlimit)
#define __NR_getrusage				98
	__SYSCALL(__NR_getrusage, sys_getrusage)
#define __NR_sysinfo				99
	__SYSCALL(__NR_sysinfo, sys_sysinfo)
#define __NR_times				100
	__SYSCALL(__NR_times, sys_times)
#define __NR_ptrace				101
	__SYSCALL(__NR_ptrace, sys_ptrace)
#define __NR_getuid				102
	__SYSCALL(__NR_getuid, sys_getuid)
#define __NR_syslog				103
	__SYSCALL(__NR_syslog, sys_syslog)

	/* at the very end the stuff that never runs during the benchmarks */
#define __NR_getgid				104
	__SYSCALL(__NR_getgid, sys_getgid)
#define __NR_setuid				105
	__SYSCALL(__NR_setuid, sys_setuid)
#define __NR_setgid				106
	__SYSCALL(__NR_setgid, sys_setgid)
#define __NR_geteuid				107
	__SYSCALL(__NR_geteuid, sys_geteuid)
#define __NR_getegid				108
	__SYSCALL(__NR_getegid, sys_getegid)
#define __NR_setpgid				109
	__SYSCALL(__NR_setpgid, sys_setpgid)
#define __NR_getppid				110
	__SYSCALL(__NR_getppid, sys_getppid)
#define __NR_getpgrp				111
	__SYSCALL(__NR_getpgrp, sys_getpgrp)

#define __NR_setsid				112
	__SYSCALL(__NR_setsid, sys_setsid)
#define __NR_setreuid				113
	__SYSCALL(__NR_setreuid, sys_setreuid)
#define __NR_setregid				114
	__SYSCALL(__NR_setregid, sys_setregid)
#define __NR_getgroups				115
	__SYSCALL(__NR_getgroups, sys_getgroups)
#define __NR_setgroups				116
	__SYSCALL(__NR_setgroups, sys_setgroups)
#define __NR_setresuid				117
	__SYSCALL(__NR_setresuid, sys_setresuid)
#define __NR_getresuid				118
	__SYSCALL(__NR_getresuid, sys_getresuid)
#define __NR_setresgid				119
	__SYSCALL(__NR_setresgid, sys_setresgid)

#define __NR_getresgid				120
	__SYSCALL(__NR_getresgid, sys_getresgid)
#define __NR_getpgid				121
	__SYSCALL(__NR_getpgid, sys_getpgid)
#define __NR_setfsuid				122
	__SYSCALL(__NR_setfsuid, sys_setfsuid)
#define __NR_setfsgid				123
	__SYSCALL(__NR_setfsgid, sys_setfsgid)
#define __NR_getsid				124
	__SYSCALL(__NR_getsid, sys_getsid)
#define __NR_capget				125
	__SYSCALL(__NR_capget, sys_capget)
#define __NR_capset				126
	__SYSCALL(__NR_capset, sys_capset)

#define __NR_rt_sigpending			127
	__SYSCALL(__NR_rt_sigpending, sys_rt_sigpending)
#define __NR_rt_sigtimedwait			128
	__SYSCALL(__NR_rt_sigtimedwait, sys_rt_sigtimedwait)
#define __NR_rt_sigqueueinfo			129
	__SYSCALL(__NR_rt_sigqueueinfo, sys_rt_sigqueueinfo)
#define __NR_rt_sigsuspend			130
	__SYSCALL(__NR_rt_sigsuspend, sys_rt_sigsuspend)
#define __NR_sigaltstack			131
	__SYSCALL(__NR_sigaltstack, stub_sigaltstack)
#define __NR_utime				132
	__SYSCALL(__NR_utime, sys_utime)
#define __NR_mknod				133
	__SYSCALL(__NR_mknod, sys_mknod)

	/* Only needed for a.out */
#define __NR_uselib				134
	__SYSCALL(__NR_uselib, sys_ni_syscall)
#define __NR_personality			135
	__SYSCALL(__NR_personality, sys_personality)

#define __NR_ustat				136
	__SYSCALL(__NR_ustat, sys_ustat)
#define __NR_statfs				137
	__SYSCALL(__NR_statfs, sys_statfs)
#define __NR_fstatfs				138
	__SYSCALL(__NR_fstatfs, sys_fstatfs)
#define __NR_sysfs				139
	__SYSCALL(__NR_sysfs, sys_sysfs)

#define __NR_getpriority			140
	__SYSCALL(__NR_getpriority, sys_getpriority)
#define __NR_setpriority			141
	__SYSCALL(__NR_setpriority, sys_setpriority)
#define __NR_sched_setparam			142
	__SYSCALL(__NR_sched_setparam, sys_sched_setparam)
#define __NR_sched_getparam			143
	__SYSCALL(__NR_sched_getparam, sys_sched_getparam)
#define __NR_sched_setscheduler			144
	__SYSCALL(__NR_sched_setscheduler, sys_sched_setscheduler)
#define __NR_sched_getscheduler			145
	__SYSCALL(__NR_sched_getscheduler, sys_sched_getscheduler)
#define __NR_sched_get_priority_max		146
	__SYSCALL(__NR_sched_get_priority_max, sys_sched_get_priority_max)
#define __NR_sched_get_priority_min		147
	__SYSCALL(__NR_sched_get_priority_min, sys_sched_get_priority_min)
#define __NR_sched_rr_get_interval		148
	__SYSCALL(__NR_sched_rr_get_interval, sys_sched_rr_get_interval)

#define __NR_mlock				149
	__SYSCALL(__NR_mlock, sys_mlock)
#define __NR_munlock				150
	__SYSCALL(__NR_munlock, sys_munlock)
#define __NR_mlockall				151
	__SYSCALL(__NR_mlockall, sys_mlockall)
#define __NR_munlockall				152
	__SYSCALL(__NR_munlockall, sys_munlockall)

#define __NR_vhangup				153
	__SYSCALL(__NR_vhangup, sys_vhangup)

#define __NR_modify_ldt				154
	__SYSCALL(__NR_modify_ldt, sys_modify_ldt)

#define __NR_pivot_root				155
	__SYSCALL(__NR_pivot_root, sys_pivot_root)

#define __NR__sysctl				156
	__SYSCALL(__NR__sysctl, sys_sysctl)

#define __NR_prctl				157
	__SYSCALL(__NR_prctl, sys_prctl)
#define __NR_arch_prctl				158
	__SYSCALL(__NR_arch_prctl, sys_arch_prctl)

#define __NR_adjtimex				159
	__SYSCALL(__NR_adjtimex, sys_adjtimex)

#define __NR_setrlimit				160
	__SYSCALL(__NR_setrlimit, sys_setrlimit)

#define __NR_chroot				161
	__SYSCALL(__NR_chroot, sys_chroot)

#define __NR_sync				162
	__SYSCALL(__NR_sync, sys_sync)

#define __NR_acct				163
	__SYSCALL(__NR_acct, sys_acct)

#define __NR_settimeofday			164
	__SYSCALL(__NR_settimeofday, sys_settimeofday)

#define __NR_mount				165
	__SYSCALL(__NR_mount, sys_mount)
#define __NR_umount2				166
	__SYSCALL(__NR_umount2, sys_umount)

#define __NR_swapon				167
	__SYSCALL(__NR_swapon, sys_swapon)
#define __NR_swapoff				168
	__SYSCALL(__NR_swapoff, sys_swapoff)

#define __NR_reboot				169
	__SYSCALL(__NR_reboot, sys_reboot)

#define __NR_sethostname			170
	__SYSCALL(__NR_sethostname, sys_sethostname)
#define __NR_setdomainname			171
	__SYSCALL(__NR_setdomainname, sys_setdomainname)

#define __NR_iopl				172
	__SYSCALL(__NR_iopl, stub_iopl)
#define __NR_ioperm				173
	__SYSCALL(__NR_ioperm, sys_ioperm)

#define __NR_create_module			174
	__SYSCALL(__NR_create_module, sys_ni_syscall)
#define __NR_init_module			175
	__SYSCALL(__NR_init_module, sys_init_module)
#define __NR_delete_module			176
	__SYSCALL(__NR_delete_module, sys_delete_module)
#define __NR_get_kernel_syms			177
	__SYSCALL(__NR_get_kernel_syms, sys_ni_syscall)
#define __NR_query_module			178
	__SYSCALL(__NR_query_module, sys_ni_syscall)

#define __NR_quotactl				179
	__SYSCALL(__NR_quotactl, sys_quotactl)

#define __NR_nfsservctl				180
	__SYSCALL(__NR_nfsservctl, sys_nfsservctl)

	/* reserved for LiS/STREAMS */
#define __NR_getpmsg				181
	__SYSCALL(__NR_getpmsg, sys_ni_syscall)
#define __NR_putpmsg				182
	__SYSCALL(__NR_putpmsg, sys_ni_syscall)

	/* reserved for AFS */
#define __NR_afs_syscall			183
	__SYSCALL(__NR_afs_syscall, sys_ni_syscall)

	/* reserved for tux */
#define __NR_tuxcall				184
	__SYSCALL(__NR_tuxcall, sys_ni_syscall)

#define __NR_security				185
	__SYSCALL(__NR_security, sys_ni_syscall)

#define __NR_gettid				186
	__SYSCALL(__NR_gettid, sys_gettid)

#define __NR_readahead				187
	__SYSCALL(__NR_readahead, sys_readahead)
#define __NR_setxattr				188
	__SYSCALL(__NR_setxattr, sys_setxattr)
#define __NR_lsetxattr				189
	__SYSCALL(__NR_lsetxattr, sys_lsetxattr)
#define __NR_fsetxattr				190
	__SYSCALL(__NR_fsetxattr, sys_fsetxattr)
#define __NR_getxattr				191
	__SYSCALL(__NR_getxattr, sys_getxattr)
#define __NR_lgetxattr				192
	__SYSCALL(__NR_lgetxattr, sys_lgetxattr)
#define __NR_fgetxattr				193
	__SYSCALL(__NR_fgetxattr, sys_fgetxattr)
#define __NR_listxattr				194
	__SYSCALL(__NR_listxattr, sys_listxattr)
#define __NR_llistxattr				195
	__SYSCALL(__NR_llistxattr, sys_llistxattr)
#define __NR_flistxattr				196
	__SYSCALL(__NR_flistxattr, sys_flistxattr)
#define __NR_removexattr			197
	__SYSCALL(__NR_removexattr, sys_removexattr)
#define __NR_lremovexattr			198
	__SYSCALL(__NR_lremovexattr, sys_lremovexattr)
#define __NR_fremovexattr			199
	__SYSCALL(__NR_fremovexattr, sys_fremovexattr)
#define __NR_tkill				200
	__SYSCALL(__NR_tkill, sys_tkill)
#define __NR_time				201
	__SYSCALL(__NR_time, sys_time)
#define __NR_futex				202
	__SYSCALL(__NR_futex, sys_futex)
#define __NR_sched_setaffinity			203
	__SYSCALL(__NR_sched_setaffinity, sys_sched_setaffinity)
#define __NR_sched_getaffinity			204
	__SYSCALL(__NR_sched_getaffinity, sys_sched_getaffinity)
#define __NR_set_thread_area			205
	__SYSCALL(__NR_set_thread_area, sys_ni_syscall)	/* use arch_prctl */
#define __NR_io_setup				206
	__SYSCALL(__NR_io_setup, sys_io_setup)
#define __NR_io_destroy				207
	__SYSCALL(__NR_io_destroy, sys_io_destroy)
#define __NR_io_getevents			208
	__SYSCALL(__NR_io_getevents, sys_io_getevents)
#define __NR_io_submit				209
	__SYSCALL(__NR_io_submit, sys_io_submit)
#define __NR_io_cancel				210
	__SYSCALL(__NR_io_cancel, sys_io_cancel)
#define __NR_get_thread_area			211
	__SYSCALL(__NR_get_thread_area, sys_ni_syscall)	/* use arch_prctl */
#define __NR_lookup_dcookie			212
	__SYSCALL(__NR_lookup_dcookie, sys_lookup_dcookie)
#define __NR_epoll_create			213
	__SYSCALL(__NR_epoll_create, sys_epoll_create)
#define __NR_epoll_ctl_old			214
	__SYSCALL(__NR_epoll_ctl_old, sys_ni_syscall)
#define __NR_epoll_wait_old			215
	__SYSCALL(__NR_epoll_wait_old, sys_ni_syscall)
#define __NR_remap_file_pages			216
	__SYSCALL(__NR_remap_file_pages, sys_remap_file_pages)
#define __NR_getdents64				217
	__SYSCALL(__NR_getdents64, sys_getdents64)
#define __NR_set_tid_address			218
	__SYSCALL(__NR_set_tid_address, sys_set_tid_address)
#define __NR_restart_syscall			219
	__SYSCALL(__NR_restart_syscall, sys_restart_syscall)
#define __NR_semtimedop				220
	__SYSCALL(__NR_semtimedop, sys_semtimedop)
#define __NR_fadvise64				221
	__SYSCALL(__NR_fadvise64, sys_fadvise64)
#define __NR_timer_create			222
	__SYSCALL(__NR_timer_create, sys_timer_create)
#define __NR_timer_settime			223
	__SYSCALL(__NR_timer_settime, sys_timer_settime)
#define __NR_timer_gettime			224
	__SYSCALL(__NR_timer_gettime, sys_timer_gettime)
#define __NR_timer_getoverrun			225
	__SYSCALL(__NR_timer_getoverrun, sys_timer_getoverrun)
#define __NR_timer_delete			226
	__SYSCALL(__NR_timer_delete, sys_timer_delete)
#define __NR_clock_settime			227
	__SYSCALL(__NR_clock_settime, sys_clock_settime)
#define __NR_clock_gettime			228
	__SYSCALL(__NR_clock_gettime, sys_clock_gettime)
#define __NR_clock_getres			229
	__SYSCALL(__NR_clock_getres, sys_clock_getres)
#define __NR_clock_nanosleep			230
	__SYSCALL(__NR_clock_nanosleep, sys_clock_nanosleep)
#define __NR_exit_group				231
	__SYSCALL(__NR_exit_group, sys_exit_group)
#define __NR_epoll_wait				232
	__SYSCALL(__NR_epoll_wait, sys_epoll_wait)
#define __NR_epoll_ctl				233
	__SYSCALL(__NR_epoll_ctl, sys_epoll_ctl)
#define __NR_tgkill				234
	__SYSCALL(__NR_tgkill, sys_tgkill)
#define __NR_utimes				235
	__SYSCALL(__NR_utimes, sys_utimes)
#define __NR_vserver				236
	__SYSCALL(__NR_vserver, sys_ni_syscall)
#define __NR_mbind				237
	__SYSCALL(__NR_mbind, sys_mbind)
#define __NR_set_mempolicy			238
	__SYSCALL(__NR_set_mempolicy, sys_set_mempolicy)
#define __NR_get_mempolicy			239
	__SYSCALL(__NR_get_mempolicy, sys_get_mempolicy)
#define __NR_mq_open				240
	__SYSCALL(__NR_mq_open, sys_mq_open)
#define __NR_mq_unlink				241
	__SYSCALL(__NR_mq_unlink, sys_mq_unlink)
#define __NR_mq_timedsend			242
	__SYSCALL(__NR_mq_timedsend, sys_mq_timedsend)
#define __NR_mq_timedreceive			243
	__SYSCALL(__NR_mq_timedreceive, sys_mq_timedreceive)
#define __NR_mq_notify				244
	__SYSCALL(__NR_mq_notify, sys_mq_notify)
#define __NR_mq_getsetattr			245
	__SYSCALL(__NR_mq_getsetattr, sys_mq_getsetattr)
#define __NR_kexec_load				246
	__SYSCALL(__NR_kexec_load, sys_kexec_load)
#define __NR_waitid				247
	__SYSCALL(__NR_waitid, sys_waitid)
#define __NR_add_key				248
	__SYSCALL(__NR_add_key, sys_add_key)
#define __NR_request_key			249
	__SYSCALL(__NR_request_key, sys_request_key)
#define __NR_keyctl				250
	__SYSCALL(__NR_keyctl, sys_keyctl)
#define __NR_ioprio_set				251
	__SYSCALL(__NR_ioprio_set, sys_ioprio_set)
#define __NR_ioprio_get				252
	__SYSCALL(__NR_ioprio_get, sys_ioprio_get)
#define __NR_inotify_init			253
	__SYSCALL(__NR_inotify_init, sys_inotify_init)
#define __NR_inotify_add_watch			254
	__SYSCALL(__NR_inotify_add_watch, sys_inotify_add_watch)
#define __NR_inotify_rm_watch			255
	__SYSCALL(__NR_inotify_rm_watch, sys_inotify_rm_watch)
#define __NR_migrate_pages			256
	__SYSCALL(__NR_migrate_pages, sys_migrate_pages)
#define __NR_openat				257
	__SYSCALL(__NR_openat, sys_openat)
#define __NR_mkdirat				258
	__SYSCALL(__NR_mkdirat, sys_mkdirat)
#define __NR_mknodat				259
	__SYSCALL(__NR_mknodat, sys_mknodat)
#define __NR_fchownat				260
	__SYSCALL(__NR_fchownat, sys_fchownat)
#define __NR_futimesat				261
	__SYSCALL(__NR_futimesat, sys_futimesat)
#define __NR_newfstatat				262
	__SYSCALL(__NR_newfstatat, sys_newfstatat)
#define __NR_unlinkat				263
	__SYSCALL(__NR_unlinkat, sys_unlinkat)
#define __NR_renameat				264
	__SYSCALL(__NR_renameat, sys_renameat)
#define __NR_linkat				265
	__SYSCALL(__NR_linkat, sys_linkat)
#define __NR_symlinkat				266
	__SYSCALL(__NR_symlinkat, sys_symlinkat)
#define __NR_readlinkat				267
	__SYSCALL(__NR_readlinkat, sys_readlinkat)
#define __NR_fchmodat				268
	__SYSCALL(__NR_fchmodat, sys_fchmodat)
#define __NR_faccessat				269
	__SYSCALL(__NR_faccessat, sys_faccessat)
#define __NR_pselect6				270
	__SYSCALL(__NR_pselect6, sys_pselect6)
#define __NR_ppoll				271
	__SYSCALL(__NR_ppoll,	sys_ppoll)
#define __NR_unshare				272
	__SYSCALL(__NR_unshare,	sys_unshare)
#define __NR_set_robust_list			273
	__SYSCALL(__NR_set_robust_list, sys_set_robust_list)
#define __NR_get_robust_list			274
	__SYSCALL(__NR_get_robust_list, sys_get_robust_list)
#define __NR_splice				275
	__SYSCALL(__NR_splice, sys_splice)
#define __NR_tee				276
	__SYSCALL(__NR_tee, sys_tee)
#define __NR_sync_file_range			277
	__SYSCALL(__NR_sync_file_range, sys_sync_file_range)
#define __NR_vmsplice				278
	__SYSCALL(__NR_vmsplice, sys_vmsplice)
#define __NR_move_pages				279
	__SYSCALL(__NR_move_pages, sys_move_pages)
#define __NR_utimensat				280
	__SYSCALL(__NR_utimensat, sys_utimensat)
#define __IGNORE_getcpu		/* implemented as a vsyscall */
#define __NR_epoll_pwait			281
	__SYSCALL(__NR_epoll_pwait, sys_epoll_pwait)
#define __NR_signalfd				282
	__SYSCALL(__NR_signalfd, sys_signalfd)
#define __NR_timerfd_create			283
	__SYSCALL(__NR_timerfd_create, sys_timerfd_create)
#define __NR_eventfd				284
	__SYSCALL(__NR_eventfd, sys_eventfd)
#define __NR_fallocate				285
	__SYSCALL(__NR_fallocate, sys_fallocate)
#define __NR_timerfd_settime			286
	__SYSCALL(__NR_timerfd_settime, sys_timerfd_settime)
#define __NR_timerfd_gettime			287
	__SYSCALL(__NR_timerfd_gettime, sys_timerfd_gettime)
#define __NR_accept4				288
	__SYSCALL(__NR_accept4, sys_accept4)
#define __NR_signalfd4				289
	__SYSCALL(__NR_signalfd4, sys_signalfd4)
#define __NR_eventfd2				290
	__SYSCALL(__NR_eventfd2, sys_eventfd2)
#define __NR_epoll_create1			291
	__SYSCALL(__NR_epoll_create1, sys_epoll_create1)
#define __NR_dup3				292
	__SYSCALL(__NR_dup3, sys_dup3)
#define __NR_pipe2				293
	__SYSCALL(__NR_pipe2, sys_pipe2)
#define __NR_inotify_init1			294
	__SYSCALL(__NR_inotify_init1, sys_inotify_init1)
#define __NR_preadv				295
	__SYSCALL(__NR_preadv, sys_preadv)
#define __NR_pwritev				296
	__SYSCALL(__NR_pwritev, sys_pwritev)
#define __NR_rt_tgsigqueueinfo			297
	__SYSCALL(__NR_rt_tgsigqueueinfo, sys_rt_tgsigqueueinfo)
#define __NR_perf_event_open			298
	__SYSCALL(__NR_perf_event_open, sys_perf_event_open)
#define __NR_recvmmsg				299
	__SYSCALL(__NR_recvmmsg, sys_recvmmsg)
#define __NR_fanotify_init			300
	__SYSCALL(__NR_fanotify_init, sys_fanotify_init)
#define __NR_fanotify_mark			301
	__SYSCALL(__NR_fanotify_mark, sys_fanotify_mark)
#define __NR_prlimit64				302
	__SYSCALL(__NR_prlimit64, sys_prlimit64)

#ifndef __NO_STUBS
#define __ARCH_WANT_OLD_READDIR
#define __ARCH_WANT_OLD_STAT
#define __ARCH_WANT_SYS_ALARM
#define __ARCH_WANT_SYS_GETHOSTNAME
#define __ARCH_WANT_SYS_PAUSE
#define __ARCH_WANT_SYS_SGETMASK
#define __ARCH_WANT_SYS_SIGNAL
#define __ARCH_WANT_SYS_UTIME
#define __ARCH_WANT_SYS_WAITPID
#define __ARCH_WANT_SYS_SOCKETCALL
#define __ARCH_WANT_SYS_FADVISE64
#define __ARCH_WANT_SYS_GETPGRP
#define __ARCH_WANT_SYS_LLSEEK
#define __ARCH_WANT_SYS_NICE
#define __ARCH_WANT_SYS_OLD_GETRLIMIT
#define __ARCH_WANT_SYS_OLD_UNAME
#define __ARCH_WANT_SYS_OLDUMOUNT
#define __ARCH_WANT_SYS_SIGPENDING
#define __ARCH_WANT_SYS_SIGPROCMASK
#define __ARCH_WANT_SYS_RT_SIGACTION
#define __ARCH_WANT_SYS_RT_SIGSUSPEND
#define __ARCH_WANT_SYS_TIME
#define __ARCH_WANT_COMPAT_SYS_TIME
#endif	/* __NO_STUBS */

#ifdef __KERNEL__

#ifndef COMPILE_OFFSETS
#include <asm/asm-offsets.h>
#define NR_syscalls (__NR_syscall_max + 1)
#endif

	/*
	 * * "Conditional" syscalls
	 * *
	 * * What we want is __attribute__((weak,alias("sys_ni_syscall"))),
	 * * but it doesn't work on all toolchains, so we just do it by hand
	 * */
#define cond_syscall(x) asm(".weak\t" #x "\n\t.set\t" #x ",sys_ni_syscall")
#endif	/* __KERNEL__ */

#endif /* _ASM_X86_UNISTD_64_H */



/*
 * * syscalls.h - Linux syscall interfaces (non-arch-specific)
 * *
 * * Copyright (c) 2004 Randy Dunlap
 * * Copyright (c) 2004 Open Source Development Labs
 * *
 * * This file is released under the GPLv2.
 * * See the file COPYING for more details.
 * */

#ifndef _LINUX_SYSCALLS_H
#define _LINUX_SYSCALLS_H

	struct epoll_event;
	struct iattr;
	struct inode;
	struct iocb;
	struct io_event;
	struct iovec;
	struct itimerspec;
	struct itimerval;
	struct kexec_segment;
	struct linux_dirent;
	struct linux_dirent64;
	struct list_head;
	struct mmap_arg_struct;
	struct msgbuf;
	struct msghdr;
	struct mmsghdr;
	struct msqid_ds;
	struct new_utsname;
	struct nfsctl_arg;
	struct __old_kernel_stat;
	struct oldold_utsname;
	struct old_utsname;
	struct pollfd;
	struct rlimit;
	struct rlimit64;
	struct rusage;
	struct sched_param;
	struct sel_arg_struct;
	struct semaphore;
	struct sembuf;
	struct shmid_ds;
	struct sockaddr;
	struct stat;
	struct stat64;
	struct statfs;
	struct statfs64;
	struct __sysctl_args;
	struct sysinfo;
	struct timespec;
	struct timeval;
	struct timex;
	struct timezone;
	struct tms;
	struct utimbuf;
	struct mq_attr;
	struct compat_stat;
	struct compat_timeval;
	struct robust_list_head;
	struct getcpu_cache;
	struct old_linux_dirent;
	struct perf_event_attr;

#include <linux/types.h>
#include <linux/aio_abi.h>
#include <linux/capability.h>
#include <linux/list.h>
#include <linux/sem.h>
#include <asm/siginfo.h>
#include <asm/signal.h>
#include <linux/unistd.h>
#include <linux/quota.h>
#include <linux/key.h>
#include <trace/syscall.h>

#define __SC_DECL1(t1, a1)	t1 a1
#define __SC_DECL2(t2, a2, ...) t2 a2, __SC_DECL1(__VA_ARGS__)
#define __SC_DECL3(t3, a3, ...) t3 a3, __SC_DECL2(__VA_ARGS__)
#define __SC_DECL4(t4, a4, ...) t4 a4, __SC_DECL3(__VA_ARGS__)
#define __SC_DECL5(t5, a5, ...) t5 a5, __SC_DECL4(__VA_ARGS__)
#define __SC_DECL6(t6, a6, ...) t6 a6, __SC_DECL5(__VA_ARGS__)

#define __SC_LONG1(t1, a1)	long a1
#define __SC_LONG2(t2, a2, ...) long a2, __SC_LONG1(__VA_ARGS__)
#define __SC_LONG3(t3, a3, ...) long a3, __SC_LONG2(__VA_ARGS__)
#define __SC_LONG4(t4, a4, ...) long a4, __SC_LONG3(__VA_ARGS__)
#define __SC_LONG5(t5, a5, ...) long a5, __SC_LONG4(__VA_ARGS__)
#define __SC_LONG6(t6, a6, ...) long a6, __SC_LONG5(__VA_ARGS__)

#define __SC_CAST1(t1, a1)	(t1) a1
#define __SC_CAST2(t2, a2, ...) (t2) a2, __SC_CAST1(__VA_ARGS__)
#define __SC_CAST3(t3, a3, ...) (t3) a3, __SC_CAST2(__VA_ARGS__)
#define __SC_CAST4(t4, a4, ...) (t4) a4, __SC_CAST3(__VA_ARGS__)
#define __SC_CAST5(t5, a5, ...) (t5) a5, __SC_CAST4(__VA_ARGS__)
#define __SC_CAST6(t6, a6, ...) (t6) a6, __SC_CAST5(__VA_ARGS__)

#define __SC_TEST(type)		BUILD_BUG_ON(sizeof(type) > sizeof(long))
#define __SC_TEST1(t1, a1)	__SC_TEST(t1)
#define __SC_TEST2(t2, a2, ...)	__SC_TEST(t2); __SC_TEST1(__VA_ARGS__)
#define __SC_TEST3(t3, a3, ...)	__SC_TEST(t3); __SC_TEST2(__VA_ARGS__)
#define __SC_TEST4(t4, a4, ...)	__SC_TEST(t4); __SC_TEST3(__VA_ARGS__)
#define __SC_TEST5(t5, a5, ...)	__SC_TEST(t5); __SC_TEST4(__VA_ARGS__)
#define __SC_TEST6(t6, a6, ...)	__SC_TEST(t6); __SC_TEST5(__VA_ARGS__)

#ifdef CONFIG_FTRACE_SYSCALLS
#define __SC_STR_ADECL1(t, a)		#a
#define __SC_STR_ADECL2(t, a, ...)	#a, __SC_STR_ADECL1(__VA_ARGS__)
#define __SC_STR_ADECL3(t, a, ...)	#a, __SC_STR_ADECL2(__VA_ARGS__)
#define __SC_STR_ADECL4(t, a, ...)	#a, __SC_STR_ADECL3(__VA_ARGS__)
#define __SC_STR_ADECL5(t, a, ...)	#a, __SC_STR_ADECL4(__VA_ARGS__)
#define __SC_STR_ADECL6(t, a, ...)	#a, __SC_STR_ADECL5(__VA_ARGS__)

#define __SC_STR_TDECL1(t, a)		#t
#define __SC_STR_TDECL2(t, a, ...)	#t, __SC_STR_TDECL1(__VA_ARGS__)
#define __SC_STR_TDECL3(t, a, ...)	#t, __SC_STR_TDECL2(__VA_ARGS__)
#define __SC_STR_TDECL4(t, a, ...)	#t, __SC_STR_TDECL3(__VA_ARGS__)
#define __SC_STR_TDECL5(t, a, ...)	#t, __SC_STR_TDECL4(__VA_ARGS__)
#define __SC_STR_TDECL6(t, a, ...)	#t, __SC_STR_TDECL5(__VA_ARGS__)

	extern struct ftrace_event_class event_class_syscall_enter;
	extern struct ftrace_event_class event_class_syscall_exit;
	extern struct trace_event_functions enter_syscall_print_funcs;
	extern struct trace_event_functions exit_syscall_print_funcs;

#define SYSCALL_TRACE_ENTER_EVENT(sname)				\
		static struct syscall_metadata __syscall_meta_##sname;		\
	static struct ftrace_event_call __used				\
	event_enter_##sname = {					\
		.name                   = "sys_enter"#sname,		\
		.class			= &event_class_syscall_enter,	\
		.event.funcs            = &enter_syscall_print_funcs,	\
		.data			= (void *)&__syscall_meta_##sname,\
	};								\
	static struct ftrace_event_call __used				\
	__attribute__((section("_ftrace_events")))			\
	*__event_enter_##sname = &event_enter_##sname;			\
	__TRACE_EVENT_FLAGS(enter_##sname, TRACE_EVENT_FL_CAP_ANY)

#define SYSCALL_TRACE_EXIT_EVENT(sname)					\
		static struct syscall_metadata __syscall_meta_##sname;		\
	static struct ftrace_event_call __used				\
	event_exit_##sname = {					\
		.name                   = "sys_exit"#sname,		\
		.class			= &event_class_syscall_exit,	\
		.event.funcs		= &exit_syscall_print_funcs,	\
		.data			= (void *)&__syscall_meta_##sname,\
	};								\
	static struct ftrace_event_call __used				\
	__attribute__((section("_ftrace_events")))			\
	*__event_exit_##sname = &event_exit_##sname;			\
	__TRACE_EVENT_FLAGS(exit_##sname, TRACE_EVENT_FL_CAP_ANY)

#define SYSCALL_METADATA(sname, nb)				\
		SYSCALL_TRACE_ENTER_EVENT(sname);			\
	SYSCALL_TRACE_EXIT_EVENT(sname);			\
	static struct syscall_metadata __used			\
	__syscall_meta_##sname = {				\
		.name		= "sys"#sname,			\
		.nb_args	= nb,				\
		.types		= types_##sname,		\
		.args		= args_##sname,			\
		.enter_event	= &event_enter_##sname,		\
		.exit_event	= &event_exit_##sname,		\
		.enter_fields	= LIST_HEAD_INIT(__syscall_meta_##sname.enter_fields), \
	};							\
	static struct syscall_metadata __used			\
	__attribute__((section("__syscalls_metadata")))	\
	*__p_syscall_meta_##sname = &__syscall_meta_##sname;

#define SYSCALL_DEFINE0(sname)					\
		SYSCALL_TRACE_ENTER_EVENT(_##sname);			\
	SYSCALL_TRACE_EXIT_EVENT(_##sname);			\
	static struct syscall_metadata __used			\
	__syscall_meta__##sname = {				\
		.name		= "sys_"#sname,			\
		.nb_args	= 0,				\
		.enter_event	= &event_enter__##sname,	\
		.exit_event	= &event_exit__##sname,		\
		.enter_fields	= LIST_HEAD_INIT(__syscall_meta__##sname.enter_fields), \
	};							\
	static struct syscall_metadata __used			\
	__attribute__((section("__syscalls_metadata")))	\
	*__p_syscall_meta_##sname = &__syscall_meta__##sname;	\
	asmlinkage long sys_##sname(void)
#else
#define SYSCALL_DEFINE0(name)	   asmlinkage long sys_##name(void)
#endif

#define SYSCALL_DEFINE1(name, ...) SYSCALL_DEFINEx(1, _##name, __VA_ARGS__)
#define SYSCALL_DEFINE2(name, ...) SYSCALL_DEFINEx(2, _##name, __VA_ARGS__)
#define SYSCALL_DEFINE3(name, ...) SYSCALL_DEFINEx(3, _##name, __VA_ARGS__)
#define SYSCALL_DEFINE4(name, ...) SYSCALL_DEFINEx(4, _##name, __VA_ARGS__)
#define SYSCALL_DEFINE5(name, ...) SYSCALL_DEFINEx(5, _##name, __VA_ARGS__)
#define SYSCALL_DEFINE6(name, ...) SYSCALL_DEFINEx(6, _##name, __VA_ARGS__)

#ifdef CONFIG_PPC64
#define SYSCALL_ALIAS(alias, name)					\
		asm ("\t.globl " #alias "\n\t.set " #alias ", " #name "\n"	\
				"\t.globl ." #alias "\n\t.set ." #alias ", ." #name)
#else
#if defined(CONFIG_ALPHA) || defined(CONFIG_MIPS)
#define SYSCALL_ALIAS(alias, name)					\
		asm ( #alias " = " #name "\n\t.globl " #alias)
#else
#define SYSCALL_ALIAS(alias, name)					\
		asm ("\t.globl " #alias "\n\t.set " #alias ", " #name)
#endif
#endif

#ifdef CONFIG_FTRACE_SYSCALLS
#define SYSCALL_DEFINEx(x, sname, ...)				\
		static const char *types_##sname[] = {			\
			__SC_STR_TDECL##x(__VA_ARGS__)			\
		};							\
	static const char *args_##sname[] = {			\
		__SC_STR_ADECL##x(__VA_ARGS__)			\
	};							\
	SYSCALL_METADATA(sname, x);				\
	__SYSCALL_DEFINEx(x, sname, __VA_ARGS__)
#else
#define SYSCALL_DEFINEx(x, sname, ...)				\
		__SYSCALL_DEFINEx(x, sname, __VA_ARGS__)
#endif

#ifdef CONFIG_HAVE_SYSCALL_WRAPPERS

#define SYSCALL_DEFINE(name) static inline long SYSC_##name

#define __SYSCALL_DEFINEx(x, name, ...)					\
		asmlinkage long sys##name(__SC_DECL##x(__VA_ARGS__));		\
	static inline long SYSC##name(__SC_DECL##x(__VA_ARGS__));	\
	asmlinkage long SyS##name(__SC_LONG##x(__VA_ARGS__))		\
{								\
	__SC_TEST##x(__VA_ARGS__);				\
	return (long) SYSC##name(__SC_CAST##x(__VA_ARGS__));	\
}								\
	SYSCALL_ALIAS(sys##name, SyS##name);				\
	static inline long SYSC##name(__SC_DECL##x(__VA_ARGS__))

#else /* CONFIG_HAVE_SYSCALL_WRAPPERS */

#define SYSCALL_DEFINE(name) asmlinkage long sys_##name
#define __SYSCALL_DEFINEx(x, name, ...)					\
		asmlinkage long sys##name(__SC_DECL##x(__VA_ARGS__))

#endif /* CONFIG_HAVE_SYSCALL_WRAPPERS */

	asmlinkage long sys_time(time_t __user *tloc);
	asmlinkage long sys_stime(time_t __user *tptr);
	asmlinkage long sys_gettimeofday(struct timeval __user *tv,
			struct timezone __user *tz);
asmlinkage long sys_settimeofday(struct timeval __user *tv,
		struct timezone __user *tz);
asmlinkage long sys_adjtimex(struct timex __user *txc_p);

asmlinkage long sys_times(struct tms __user *tbuf);

asmlinkage long sys_gettid(void);
asmlinkage long sys_nanosleep(struct timespec __user *rqtp, struct timespec __user *rmtp);
asmlinkage long sys_alarm(unsigned int seconds);
asmlinkage long sys_getpid(void);
asmlinkage long sys_getppid(void);
asmlinkage long sys_getuid(void);
asmlinkage long sys_geteuid(void);
asmlinkage long sys_getgid(void);
asmlinkage long sys_getegid(void);
asmlinkage long sys_getresuid(uid_t __user *ruid, uid_t __user *euid, uid_t __user *suid);
asmlinkage long sys_getresgid(gid_t __user *rgid, gid_t __user *egid, gid_t __user *sgid);
asmlinkage long sys_getpgid(pid_t pid);
asmlinkage long sys_getpgrp(void);
asmlinkage long sys_getsid(pid_t pid);
asmlinkage long sys_getgroups(int gidsetsize, gid_t __user *grouplist);

asmlinkage long sys_setregid(gid_t rgid, gid_t egid);
asmlinkage long sys_setgid(gid_t gid);
asmlinkage long sys_setreuid(uid_t ruid, uid_t euid);
asmlinkage long sys_setuid(uid_t uid);
asmlinkage long sys_setresuid(uid_t ruid, uid_t euid, uid_t suid);
asmlinkage long sys_setresgid(gid_t rgid, gid_t egid, gid_t sgid);
asmlinkage long sys_setfsuid(uid_t uid);
asmlinkage long sys_setfsgid(gid_t gid);
asmlinkage long sys_setpgid(pid_t pid, pid_t pgid);
asmlinkage long sys_setsid(void);
asmlinkage long sys_setgroups(int gidsetsize, gid_t __user *grouplist);

asmlinkage long sys_acct(const char __user *name);
asmlinkage long sys_capget(cap_user_header_t header,
		cap_user_data_t dataptr);
asmlinkage long sys_capset(cap_user_header_t header,
		const cap_user_data_t data);
asmlinkage long sys_personality(unsigned int personality);

asmlinkage long sys_sigpending(old_sigset_t __user *set);
asmlinkage long sys_sigprocmask(int how, old_sigset_t __user *set,
		old_sigset_t __user *oset);
asmlinkage long sys_getitimer(int which, struct itimerval __user *value);
asmlinkage long sys_setitimer(int which,
		struct itimerval __user *value,
		struct itimerval __user *ovalue);
asmlinkage long sys_timer_create(clockid_t which_clock,
		struct sigevent __user *timer_event_spec,
		timer_t __user * created_timer_id);
asmlinkage long sys_timer_gettime(timer_t timer_id,
		struct itimerspec __user *setting);
asmlinkage long sys_timer_getoverrun(timer_t timer_id);
asmlinkage long sys_timer_settime(timer_t timer_id, int flags,
		const struct itimerspec __user *new_setting,
		struct itimerspec __user *old_setting);
asmlinkage long sys_timer_delete(timer_t timer_id);
asmlinkage long sys_clock_settime(clockid_t which_clock,
		const struct timespec __user *tp);
asmlinkage long sys_clock_gettime(clockid_t which_clock,
		struct timespec __user *tp);
asmlinkage long sys_clock_getres(clockid_t which_clock,
		struct timespec __user *tp);
asmlinkage long sys_clock_nanosleep(clockid_t which_clock, int flags,
		const struct timespec __user *rqtp,
		struct timespec __user *rmtp);

asmlinkage long sys_nice(int increment);
asmlinkage long sys_sched_setscheduler(pid_t pid, int policy,
		struct sched_param __user *param);
asmlinkage long sys_sched_setparam(pid_t pid,
		struct sched_param __user *param);
asmlinkage long sys_sched_getscheduler(pid_t pid);
asmlinkage long sys_sched_getparam(pid_t pid,
		struct sched_param __user *param);
asmlinkage long sys_sched_setaffinity(pid_t pid, unsigned int len,
		unsigned long __user *user_mask_ptr);
asmlinkage long sys_sched_getaffinity(pid_t pid, unsigned int len,
		unsigned long __user *user_mask_ptr);
asmlinkage long sys_sched_yield(void);
asmlinkage long sys_sched_get_priority_max(int policy);
asmlinkage long sys_sched_get_priority_min(int policy);
asmlinkage long sys_sched_rr_get_interval(pid_t pid,
		struct timespec __user *interval);
asmlinkage long sys_setpriority(int which, int who, int niceval);
asmlinkage long sys_getpriority(int which, int who);

asmlinkage long sys_shutdown(int, int);
asmlinkage long sys_reboot(int magic1, int magic2, unsigned int cmd,
		void __user *arg);
asmlinkage long sys_restart_syscall(void);
asmlinkage long sys_kexec_load(unsigned long entry, unsigned long nr_segments,
		struct kexec_segment __user *segments,
		unsigned long flags);

asmlinkage long sys_exit(int error_code);
asmlinkage long sys_exit_group(int error_code);
asmlinkage long sys_wait4(pid_t pid, int __user *stat_addr,
		int options, struct rusage __user *ru);
asmlinkage long sys_waitid(int which, pid_t pid,
		struct siginfo __user *infop,
		int options, struct rusage __user *ru);
asmlinkage long sys_waitpid(pid_t pid, int __user *stat_addr, int options);
asmlinkage long sys_set_tid_address(int __user *tidptr);
asmlinkage long sys_futex(u32 __user *uaddr, int op, u32 val,
		struct timespec __user *utime, u32 __user *uaddr2,
		u32 val3);

asmlinkage long sys_init_module(void __user *umod, unsigned long len,
		const char __user *uargs);
asmlinkage long sys_delete_module(const char __user *name_user,
		unsigned int flags);

asmlinkage long sys_rt_sigprocmask(int how, sigset_t __user *set,
		sigset_t __user *oset, size_t sigsetsize);
asmlinkage long sys_rt_sigpending(sigset_t __user *set, size_t sigsetsize);
asmlinkage long sys_rt_sigtimedwait(const sigset_t __user *uthese,
		siginfo_t __user *uinfo,
		const struct timespec __user *uts,
		size_t sigsetsize);
asmlinkage long sys_rt_tgsigqueueinfo(pid_t tgid, pid_t  pid, int sig,
		siginfo_t __user *uinfo);
asmlinkage long sys_kill(int pid, int sig);
asmlinkage long sys_tgkill(int tgid, int pid, int sig);
asmlinkage long sys_tkill(int pid, int sig);
asmlinkage long sys_rt_sigqueueinfo(int pid, int sig, siginfo_t __user *uinfo);
asmlinkage long sys_sgetmask(void);
asmlinkage long sys_ssetmask(int newmask);
asmlinkage long sys_signal(int sig, __sighandler_t handler);
asmlinkage long sys_pause(void);

asmlinkage long sys_sync(void);
asmlinkage long sys_fsync(unsigned int fd);
asmlinkage long sys_fdatasync(unsigned int fd);
asmlinkage long sys_bdflush(int func, long data);
asmlinkage long sys_mount(char __user *dev_name, char __user *dir_name,
		char __user *type, unsigned long flags,
		void __user *data);
asmlinkage long sys_umount(char __user *name, int flags);
asmlinkage long sys_oldumount(char __user *name);
asmlinkage long sys_truncate(const char __user *path, long length);
asmlinkage long sys_ftruncate(unsigned int fd, unsigned long length);
asmlinkage long sys_stat(const char __user *filename,
		struct __old_kernel_stat __user *statbuf);
asmlinkage long sys_statfs(const char __user * path,
		struct statfs __user *buf);
asmlinkage long sys_statfs64(const char __user *path, size_t sz,
		struct statfs64 __user *buf);
asmlinkage long sys_fstatfs(unsigned int fd, struct statfs __user *buf);
asmlinkage long sys_fstatfs64(unsigned int fd, size_t sz,
		struct statfs64 __user *buf);
asmlinkage long sys_lstat(const char __user *filename,
		struct __old_kernel_stat __user *statbuf);
asmlinkage long sys_fstat(unsigned int fd,
		struct __old_kernel_stat __user *statbuf);
asmlinkage long sys_newstat(const char __user *filename,
		struct stat __user *statbuf);
asmlinkage long sys_newlstat(const char __user *filename,
		struct stat __user *statbuf);
asmlinkage long sys_newfstat(unsigned int fd, struct stat __user *statbuf);
asmlinkage long sys_ustat(unsigned dev, struct ustat __user *ubuf);
#if BITS_PER_LONG == 32
asmlinkage long sys_stat64(const char __user *filename,
		struct stat64 __user *statbuf);
asmlinkage long sys_fstat64(unsigned long fd, struct stat64 __user *statbuf);
asmlinkage long sys_lstat64(const char __user *filename,
		struct stat64 __user *statbuf);
asmlinkage long sys_truncate64(const char __user *path, loff_t length);
asmlinkage long sys_ftruncate64(unsigned int fd, loff_t length);
#endif

asmlinkage long sys_setxattr(const char __user *path, const char __user *name,
		const void __user *value, size_t size, int flags);
asmlinkage long sys_lsetxattr(const char __user *path, const char __user *name,
		const void __user *value, size_t size, int flags);
asmlinkage long sys_fsetxattr(int fd, const char __user *name,
		const void __user *value, size_t size, int flags);
asmlinkage long sys_getxattr(const char __user *path, const char __user *name,
		void __user *value, size_t size);
asmlinkage long sys_lgetxattr(const char __user *path, const char __user *name,
		void __user *value, size_t size);
asmlinkage long sys_fgetxattr(int fd, const char __user *name,
		void __user *value, size_t size);
asmlinkage long sys_listxattr(const char __user *path, char __user *list,
		size_t size);
asmlinkage long sys_llistxattr(const char __user *path, char __user *list,
		size_t size);
asmlinkage long sys_flistxattr(int fd, char __user *list, size_t size);
asmlinkage long sys_removexattr(const char __user *path,
		const char __user *name);
asmlinkage long sys_lremovexattr(const char __user *path,
		const char __user *name);
asmlinkage long sys_fremovexattr(int fd, const char __user *name);

asmlinkage long sys_brk(unsigned long brk);
asmlinkage long sys_mprotect(unsigned long start, size_t len,
		unsigned long prot);
asmlinkage long sys_mremap(unsigned long addr,
		unsigned long old_len, unsigned long new_len,
		unsigned long flags, unsigned long new_addr);
asmlinkage long sys_remap_file_pages(unsigned long start, unsigned long size,
		unsigned long prot, unsigned long pgoff,
		unsigned long flags);
asmlinkage long sys_msync(unsigned long start, size_t len, int flags);
asmlinkage long sys_fadvise64(int fd, loff_t offset, size_t len, int advice);
asmlinkage long sys_fadvise64_64(int fd, loff_t offset, loff_t len, int advice);
asmlinkage long sys_munmap(unsigned long addr, size_t len);
asmlinkage long sys_mlock(unsigned long start, size_t len);
asmlinkage long sys_munlock(unsigned long start, size_t len);
asmlinkage long sys_mlockall(int flags);
asmlinkage long sys_munlockall(void);
asmlinkage long sys_madvise(unsigned long start, size_t len, int behavior);
asmlinkage long sys_mincore(unsigned long start, size_t len,
		unsigned char __user * vec);

asmlinkage long sys_pivot_root(const char __user *new_root,
		const char __user *put_old);
asmlinkage long sys_chroot(const char __user *filename);
asmlinkage long sys_mknod(const char __user *filename, int mode,
		unsigned dev);
asmlinkage long sys_link(const char __user *oldname,
		const char __user *newname);
asmlinkage long sys_symlink(const char __user *old, const char __user *new);
asmlinkage long sys_unlink(const char __user *pathname);
asmlinkage long sys_rename(const char __user *oldname,
		const char __user *newname);
asmlinkage long sys_chmod(const char __user *filename, mode_t mode);
asmlinkage long sys_fchmod(unsigned int fd, mode_t mode);

asmlinkage long sys_fcntl(unsigned int fd, unsigned int cmd, unsigned long arg);
#if BITS_PER_LONG == 32
asmlinkage long sys_fcntl64(unsigned int fd,
		unsigned int cmd, unsigned long arg);
#endif
asmlinkage long sys_pipe(int __user *fildes);
asmlinkage long sys_pipe2(int __user *fildes, int flags);
asmlinkage long sys_dup(unsigned int fildes);
asmlinkage long sys_dup2(unsigned int oldfd, unsigned int newfd);
asmlinkage long sys_dup3(unsigned int oldfd, unsigned int newfd, int flags);
asmlinkage long sys_ioperm(unsigned long from, unsigned long num, int on);
asmlinkage long sys_ioctl(unsigned int fd, unsigned int cmd,
		unsigned long arg);
asmlinkage long sys_flock(unsigned int fd, unsigned int cmd);
asmlinkage long sys_io_setup(unsigned nr_reqs, aio_context_t __user *ctx);
asmlinkage long sys_io_destroy(aio_context_t ctx);
asmlinkage long sys_io_getevents(aio_context_t ctx_id,
		long min_nr,
		long nr,
		struct io_event __user *events,
		struct timespec __user *timeout);
asmlinkage long sys_io_submit(aio_context_t, long,
		struct iocb __user * __user *);
asmlinkage long sys_io_cancel(aio_context_t ctx_id, struct iocb __user *iocb,
		struct io_event __user *result);
asmlinkage long sys_sendfile(int out_fd, int in_fd,
		off_t __user *offset, size_t count);
asmlinkage long sys_sendfile64(int out_fd, int in_fd,
		loff_t __user *offset, size_t count);
asmlinkage long sys_readlink(const char __user *path,
		char __user *buf, int bufsiz);
asmlinkage long sys_creat(const char __user *pathname, int mode);
asmlinkage long sys_open(const char __user *filename,
		int flags, int mode);
asmlinkage long sys_close(unsigned int fd);
asmlinkage long sys_access(const char __user *filename, int mode);
asmlinkage long sys_vhangup(void);
asmlinkage long sys_chown(const char __user *filename,
		uid_t user, gid_t group);
asmlinkage long sys_lchown(const char __user *filename,
		uid_t user, gid_t group);
asmlinkage long sys_fchown(unsigned int fd, uid_t user, gid_t group);
#ifdef CONFIG_UID16
asmlinkage long sys_chown16(const char __user *filename,
		old_uid_t user, old_gid_t group);
asmlinkage long sys_lchown16(const char __user *filename,
		old_uid_t user, old_gid_t group);
asmlinkage long sys_fchown16(unsigned int fd, old_uid_t user, old_gid_t group);
asmlinkage long sys_setregid16(old_gid_t rgid, old_gid_t egid);
asmlinkage long sys_setgid16(old_gid_t gid);
asmlinkage long sys_setreuid16(old_uid_t ruid, old_uid_t euid);
asmlinkage long sys_setuid16(old_uid_t uid);
asmlinkage long sys_setresuid16(old_uid_t ruid, old_uid_t euid, old_uid_t suid);
asmlinkage long sys_getresuid16(old_uid_t __user *ruid,
		old_uid_t __user *euid, old_uid_t __user *suid);
asmlinkage long sys_setresgid16(old_gid_t rgid, old_gid_t egid, old_gid_t sgid);
asmlinkage long sys_getresgid16(old_gid_t __user *rgid,
		old_gid_t __user *egid, old_gid_t __user *sgid);
asmlinkage long sys_setfsuid16(old_uid_t uid);
asmlinkage long sys_setfsgid16(old_gid_t gid);
asmlinkage long sys_getgroups16(int gidsetsize, old_gid_t __user *grouplist);
asmlinkage long sys_setgroups16(int gidsetsize, old_gid_t __user *grouplist);
asmlinkage long sys_getuid16(void);
asmlinkage long sys_geteuid16(void);
asmlinkage long sys_getgid16(void);
asmlinkage long sys_getegid16(void);
#endif

asmlinkage long sys_utime(char __user *filename,
		struct utimbuf __user *times);
asmlinkage long sys_utimes(char __user *filename,
		struct timeval __user *utimes);
asmlinkage long sys_lseek(unsigned int fd, off_t offset,
		unsigned int origin);
asmlinkage long sys_llseek(unsigned int fd, unsigned long offset_high,
		unsigned long offset_low, loff_t __user *result,
		unsigned int origin);
asmlinkage long sys_read(unsigned int fd, char __user *buf, size_t count);
asmlinkage long sys_readahead(int fd, loff_t offset, size_t count);
asmlinkage long sys_readv(unsigned long fd,
		const struct iovec __user *vec,
		unsigned long vlen);
asmlinkage long sys_write(unsigned int fd, const char __user *buf,
		size_t count);
asmlinkage long sys_writev(unsigned long fd,
		const struct iovec __user *vec,
		unsigned long vlen);
asmlinkage long sys_pread64(unsigned int fd, char __user *buf,
		size_t count, loff_t pos);
asmlinkage long sys_pwrite64(unsigned int fd, const char __user *buf,
		size_t count, loff_t pos);
asmlinkage long sys_preadv(unsigned long fd, const struct iovec __user *vec,
		unsigned long vlen, unsigned long pos_l, unsigned long pos_h);
asmlinkage long sys_pwritev(unsigned long fd, const struct iovec __user *vec,
		unsigned long vlen, unsigned long pos_l, unsigned long pos_h);
asmlinkage long sys_getcwd(char __user *buf, unsigned long size);
asmlinkage long sys_mkdir(const char __user *pathname, int mode);
asmlinkage long sys_chdir(const char __user *filename);
asmlinkage long sys_fchdir(unsigned int fd);
asmlinkage long sys_rmdir(const char __user *pathname);
asmlinkage long sys_lookup_dcookie(u64 cookie64, char __user *buf, size_t len);
asmlinkage long sys_quotactl(unsigned int cmd, const char __user *special,
		qid_t id, void __user *addr);
asmlinkage long sys_getdents(unsigned int fd,
		struct linux_dirent __user *dirent,
		unsigned int count);
asmlinkage long sys_getdents64(unsigned int fd,
		struct linux_dirent64 __user *dirent,
		unsigned int count);

asmlinkage long sys_setsockopt(int fd, int level, int optname,
		char __user *optval, int optlen);
asmlinkage long sys_getsockopt(int fd, int level, int optname,
		char __user *optval, int __user *optlen);
asmlinkage long sys_bind(int, struct sockaddr __user *, int);
asmlinkage long sys_connect(int, struct sockaddr __user *, int);
asmlinkage long sys_accept(int, struct sockaddr __user *, int __user *);
asmlinkage long sys_accept4(int, struct sockaddr __user *, int __user *, int);
asmlinkage long sys_getsockname(int, struct sockaddr __user *, int __user *);
asmlinkage long sys_getpeername(int, struct sockaddr __user *, int __user *);
asmlinkage long sys_send(int, void __user *, size_t, unsigned);
asmlinkage long sys_sendto(int, void __user *, size_t, unsigned,
		struct sockaddr __user *, int);
asmlinkage long sys_sendmsg(int fd, struct msghdr __user *msg, unsigned flags);
asmlinkage long sys_recv(int, void __user *, size_t, unsigned);
asmlinkage long sys_recvfrom(int, void __user *, size_t, unsigned,
		struct sockaddr __user *, int __user *);
asmlinkage long sys_recvmsg(int fd, struct msghdr __user *msg, unsigned flags);
asmlinkage long sys_recvmmsg(int fd, struct mmsghdr __user *msg,
		unsigned int vlen, unsigned flags,
		struct timespec __user *timeout);
asmlinkage long sys_socket(int, int, int);
asmlinkage long sys_socketpair(int, int, int, int __user *);
asmlinkage long sys_socketcall(int call, unsigned long __user *args);
asmlinkage long sys_listen(int, int);
asmlinkage long sys_poll(struct pollfd __user *ufds, unsigned int nfds,
		long timeout);
asmlinkage long sys_select(int n, fd_set __user *inp, fd_set __user *outp,
		fd_set __user *exp, struct timeval __user *tvp);
asmlinkage long sys_old_select(struct sel_arg_struct __user *arg);
asmlinkage long sys_epoll_create(int size);
asmlinkage long sys_epoll_create1(int flags);
asmlinkage long sys_epoll_ctl(int epfd, int op, int fd,
		struct epoll_event __user *event);
asmlinkage long sys_epoll_wait(int epfd, struct epoll_event __user *events,
		int maxevents, int timeout);
asmlinkage long sys_epoll_pwait(int epfd, struct epoll_event __user *events,
		int maxevents, int timeout,
		const sigset_t __user *sigmask,
		size_t sigsetsize);
asmlinkage long sys_gethostname(char __user *name, int len);
asmlinkage long sys_sethostname(char __user *name, int len);
asmlinkage long sys_setdomainname(char __user *name, int len);
asmlinkage long sys_newuname(struct new_utsname __user *name);
asmlinkage long sys_uname(struct old_utsname __user *);
asmlinkage long sys_olduname(struct oldold_utsname __user *);

asmlinkage long sys_getrlimit(unsigned int resource,
		struct rlimit __user *rlim);
#if defined(COMPAT_RLIM_OLD_INFINITY) || !(defined(CONFIG_IA64))
asmlinkage long sys_old_getrlimit(unsigned int resource, struct rlimit __user *rlim);
#endif
asmlinkage long sys_setrlimit(unsigned int resource,
		struct rlimit __user *rlim);
asmlinkage long sys_prlimit64(pid_t pid, unsigned int resource,
		const struct rlimit64 __user *new_rlim,
		struct rlimit64 __user *old_rlim);
asmlinkage long sys_getrusage(int who, struct rusage __user *ru);
asmlinkage long sys_umask(int mask);

asmlinkage long sys_msgget(key_t key, int msgflg);
asmlinkage long sys_msgsnd(int msqid, struct msgbuf __user *msgp,
		size_t msgsz, int msgflg);
asmlinkage long sys_msgrcv(int msqid, struct msgbuf __user *msgp,
		size_t msgsz, long msgtyp, int msgflg);
asmlinkage long sys_msgctl(int msqid, int cmd, struct msqid_ds __user *buf);

asmlinkage long sys_semget(key_t key, int nsems, int semflg);
asmlinkage long sys_semop(int semid, struct sembuf __user *sops,
		unsigned nsops);
asmlinkage long sys_semctl(int semid, int semnum, int cmd, union semun arg);
asmlinkage long sys_semtimedop(int semid, struct sembuf __user *sops,
		unsigned nsops,
		const struct timespec __user *timeout);
asmlinkage long sys_shmat(int shmid, char __user *shmaddr, int shmflg);
asmlinkage long sys_shmget(key_t key, size_t size, int flag);
asmlinkage long sys_shmdt(char __user *shmaddr);
asmlinkage long sys_shmctl(int shmid, int cmd, struct shmid_ds __user *buf);
asmlinkage long sys_ipc(unsigned int call, int first, unsigned long second,
		unsigned long third, void __user *ptr, long fifth);

asmlinkage long sys_mq_open(const char __user *name, int oflag, mode_t mode, struct mq_attr __user *attr);
asmlinkage long sys_mq_unlink(const char __user *name);
asmlinkage long sys_mq_timedsend(mqd_t mqdes, const char __user *msg_ptr, size_t msg_len, unsigned int msg_prio, const struct timespec __user *abs_timeout);
asmlinkage long sys_mq_timedreceive(mqd_t mqdes, char __user *msg_ptr, size_t msg_len, unsigned int __user *msg_prio, const struct timespec __user *abs_timeout);
asmlinkage long sys_mq_notify(mqd_t mqdes, const struct sigevent __user *notification);
asmlinkage long sys_mq_getsetattr(mqd_t mqdes, const struct mq_attr __user *mqstat, struct mq_attr __user *omqstat);

asmlinkage long sys_pciconfig_iobase(long which, unsigned long bus, unsigned long devfn);
asmlinkage long sys_pciconfig_read(unsigned long bus, unsigned long dfn,
		unsigned long off, unsigned long len,
		void __user *buf);
asmlinkage long sys_pciconfig_write(unsigned long bus, unsigned long dfn,
		unsigned long off, unsigned long len,
		void __user *buf);

asmlinkage long sys_prctl(int option, unsigned long arg2, unsigned long arg3,
		unsigned long arg4, unsigned long arg5);
asmlinkage long sys_swapon(const char __user *specialfile, int swap_flags);
asmlinkage long sys_swapoff(const char __user *specialfile);
asmlinkage long sys_sysctl(struct __sysctl_args __user *args);
asmlinkage long sys_sysinfo(struct sysinfo __user *info);
asmlinkage long sys_sysfs(int option,
		unsigned long arg1, unsigned long arg2);
asmlinkage long sys_nfsservctl(int cmd,
		struct nfsctl_arg __user *arg,
		void __user *res);
asmlinkage long sys_syslog(int type, char __user *buf, int len);
asmlinkage long sys_uselib(const char __user *library);
asmlinkage long sys_ni_syscall(void);
asmlinkage long sys_ptrace(long request, long pid, unsigned long addr,
		unsigned long data);

asmlinkage long sys_add_key(const char __user *_type,
		const char __user *_description,
		const void __user *_payload,
		size_t plen,
		key_serial_t destringid);

asmlinkage long sys_request_key(const char __user *_type,
		const char __user *_description,
		const char __user *_callout_info,
		key_serial_t destringid);

asmlinkage long sys_keyctl(int cmd, unsigned long arg2, unsigned long arg3,
		unsigned long arg4, unsigned long arg5);

asmlinkage long sys_ioprio_set(int which, int who, int ioprio);
asmlinkage long sys_ioprio_get(int which, int who);
asmlinkage long sys_set_mempolicy(int mode, unsigned long __user *nmask,
		unsigned long maxnode);
asmlinkage long sys_migrate_pages(pid_t pid, unsigned long maxnode,
		const unsigned long __user *from,
		const unsigned long __user *to);
asmlinkage long sys_move_pages(pid_t pid, unsigned long nr_pages,
		const void __user * __user *pages,
		const int __user *nodes,
		int __user *status,
		int flags);
asmlinkage long sys_mbind(unsigned long start, unsigned long len,
		unsigned long mode,
		unsigned long __user *nmask,
		unsigned long maxnode,
		unsigned flags);
asmlinkage long sys_get_mempolicy(int __user *policy,
		unsigned long __user *nmask,
		unsigned long maxnode,
		unsigned long addr, unsigned long flags);

asmlinkage long sys_inotify_init(void);
asmlinkage long sys_inotify_init1(int flags);
asmlinkage long sys_inotify_add_watch(int fd, const char __user *path,
		u32 mask);
asmlinkage long sys_inotify_rm_watch(int fd, __s32 wd);

asmlinkage long sys_spu_run(int fd, __u32 __user *unpc,
		__u32 __user *ustatus);
asmlinkage long sys_spu_create(const char __user *name,
		unsigned int flags, mode_t mode, int fd);

asmlinkage long sys_mknodat(int dfd, const char __user * filename, int mode,
		unsigned dev);
asmlinkage long sys_mkdirat(int dfd, const char __user * pathname, int mode);
asmlinkage long sys_unlinkat(int dfd, const char __user * pathname, int flag);
asmlinkage long sys_symlinkat(const char __user * oldname,
		int newdfd, const char __user * newname);
asmlinkage long sys_linkat(int olddfd, const char __user *oldname,
		int newdfd, const char __user *newname, int flags);
asmlinkage long sys_renameat(int olddfd, const char __user * oldname,
		int newdfd, const char __user * newname);
asmlinkage long sys_futimesat(int dfd, const char __user *filename,
		struct timeval __user *utimes);
asmlinkage long sys_faccessat(int dfd, const char __user *filename, int mode);
asmlinkage long sys_fchmodat(int dfd, const char __user * filename,
		mode_t mode);
asmlinkage long sys_fchownat(int dfd, const char __user *filename, uid_t user,
		gid_t group, int flag);
asmlinkage long sys_openat(int dfd, const char __user *filename, int flags,
		int mode);
asmlinkage long sys_newfstatat(int dfd, const char __user *filename,
		struct stat __user *statbuf, int flag);
asmlinkage long sys_fstatat64(int dfd, const char __user *filename,
		struct stat64 __user *statbuf, int flag);
asmlinkage long sys_readlinkat(int dfd, const char __user *path, char __user *buf,
		int bufsiz);
asmlinkage long sys_utimensat(int dfd, const char __user *filename,
		struct timespec __user *utimes, int flags);
asmlinkage long sys_unshare(unsigned long unshare_flags);

asmlinkage long sys_splice(int fd_in, loff_t __user *off_in,
		int fd_out, loff_t __user *off_out,
		size_t len, unsigned int flags);

asmlinkage long sys_vmsplice(int fd, const struct iovec __user *iov,
		unsigned long nr_segs, unsigned int flags);

asmlinkage long sys_tee(int fdin, int fdout, size_t len, unsigned int flags);

asmlinkage long sys_sync_file_range(int fd, loff_t offset, loff_t nbytes,
		unsigned int flags);
asmlinkage long sys_sync_file_range2(int fd, unsigned int flags,
		loff_t offset, loff_t nbytes);
asmlinkage long sys_get_robust_list(int pid,
		struct robust_list_head __user * __user *head_ptr,
		size_t __user *len_ptr);
asmlinkage long sys_set_robust_list(struct robust_list_head __user *head,
		size_t len);
asmlinkage long sys_getcpu(unsigned __user *cpu, unsigned __user *node, struct getcpu_cache __user *cache);
asmlinkage long sys_signalfd(int ufd, sigset_t __user *user_mask, size_t sizemask);
asmlinkage long sys_signalfd4(int ufd, sigset_t __user *user_mask, size_t sizemask, int flags);
asmlinkage long sys_timerfd_create(int clockid, int flags);
asmlinkage long sys_timerfd_settime(int ufd, int flags,
		const struct itimerspec __user *utmr,
		struct itimerspec __user *otmr);
asmlinkage long sys_timerfd_gettime(int ufd, struct itimerspec __user *otmr);
asmlinkage long sys_eventfd(unsigned int count);
asmlinkage long sys_eventfd2(unsigned int count, int flags);
asmlinkage long sys_fallocate(int fd, int mode, loff_t offset, loff_t len);
asmlinkage long sys_old_readdir(unsigned int, struct old_linux_dirent __user *, unsigned int);
asmlinkage long sys_pselect6(int, fd_set __user *, fd_set __user *,
		fd_set __user *, struct timespec __user *,
		void __user *);
asmlinkage long sys_ppoll(struct pollfd __user *, unsigned int,
		struct timespec __user *, const sigset_t __user *,
		size_t);
asmlinkage long sys_fanotify_init(unsigned int flags, unsigned int event_f_flags);
asmlinkage long sys_fanotify_mark(int fanotify_fd, unsigned int flags,
		u64 mask, int fd,
		const char  __user *pathname);

int kernel_execve(const char *filename, const char *const argv[], const char *const envp[]);


asmlinkage long sys_perf_event_open(
		struct perf_event_attr __user *attr_uptr,
		pid_t pid, int cpu, int group_fd, unsigned long flags);

asmlinkage long sys_mmap_pgoff(unsigned long addr, unsigned long len,
		unsigned long prot, unsigned long flags,
		unsigned long fd, unsigned long pgoff);
asmlinkage long sys_old_mmap(struct mmap_arg_struct __user *arg);

#endif



