/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */

/**
 *	NAME
 *	getuid, geteuid - get user identity
 *
 *	SYNOPSIS
 *	#include <unistd.h>
 *	#include <sys/types.h>
 *
 *	uid_t getuid(void);
 *	uid_t geteuid(void);
 *
 *	DESCRIPTION
 *	getuid() returns the real user ID of the calling process.
 *
 *	geteuid() returns the effective user ID of the calling process.
 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	uid_t uid = geteuid ();
	gid_t gid = getegid ();
	printf ("uid=%d gid=%d\n", (int) uid, (int) gid);
	return 0;
}
