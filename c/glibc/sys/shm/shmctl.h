/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 04月 09日 星期二 08:56:44 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 20日 星期三 08:38:34 CST. */


#include <sys/ipc.h>
#include <sys/shm.h>

//shmctl provides a variety of operations on a shared memory segment.
int shmctl(int shmid, int cmd, struct shmid_ds *buf);


SYSCALL_DEFINE3(shmctl, int, shmid, int, cmd, struct shmid_ds __user *, buf)
{
	return ksys_shmctl(shmid, cmd, buf, IPC_64);
}

