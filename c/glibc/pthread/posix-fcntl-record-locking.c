/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 24日 星期一 08:52:25 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */


#include	"unpipc.h"

void
my_lock(int fd)
{
	struct flock	lock;

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;				/* write lock entire file */

	Fcntl(fd, F_SETLKW, &lock);
}

void
my_unlock(int fd)
{
	struct flock	lock;

	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;				/* unlock entire file */

	Fcntl(fd, F_SETLK, &lock);
}

