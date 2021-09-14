/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 09日 星期二 08:56:44 CST. */


#include <sys/shm.h>

/* Data structure describing a shared memory segment.  */
struct shmid_ds // -> bits/shm.h
{
	struct ipc_perm shm_perm;		/* operation permission struct */
	size_t shm_segsz;			/* size of segment in bytes */
	__time_t shm_atime;			/* time of last shmat() */
#ifndef __x86_64__
	unsigned long int __unused1;
#endif
	__time_t shm_dtime;			/* time of last shmdt() */
#ifndef __x86_64__
	unsigned long int __unused2;
#endif
	__time_t shm_ctime;			/* time of last change by shmctl() */
#ifndef __x86_64__
	unsigned long int __unused3;
#endif
	__pid_t shm_cpid;			/* pid of creator */
	__pid_t shm_lpid;			/* pid of last shmop */
	shmatt_t shm_nattch;		/* number of current attaches */
	__syscall_ulong_t __unused4;
	__syscall_ulong_t __unused5;
};
