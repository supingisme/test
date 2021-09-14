/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */


#include <unistd.h>

//change root directory
int chroot(const char *path);


SYSCALL_DEFINE1(chroot, const char __user *, filename)
{
	return ksys_chroot(filename);
}

