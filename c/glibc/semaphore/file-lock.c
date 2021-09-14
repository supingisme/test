/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */


#include	"unpipc.h"

#define	LOCK_PATH	"pxsemlock"

sem_t	*locksem;
int		initflag;

void
my_lock(int fd)
{
	if (initflag == 0) {
		locksem = Sem_open(Px_ipc_name(LOCK_PATH), O_CREAT, FILE_MODE, 1);
		initflag = 1;
	}
	Sem_wait(locksem);
}

void
my_unlock(int fd)
{
	Sem_post(locksem);
}

