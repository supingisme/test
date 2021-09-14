/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*
 *	long int syscall (long int sysno, ...) [Function]
 *	syscall performs a generic system call.
 *	sysno is the system call number. Each kind of system call is identifed by a number.
 *	Macros for all the possible system call numbers are defned in ‘sys/syscall.h’
 *	The remaining arguments are the arguments for the system call, in order, and their
 *	meanings depend on the kind of system call. Each kind of system call has a defnite
 *	number of arguments, from zero to fve. If you code more arguments than the system
 *	call takes, the extra ones to the right are ignored.
 *	The return value is the return value from the system call, unless the system call failed.
 *	In that case, syscall returns -1 and sets errno to an error code that the system call
 *	returned. Note that system calls do not return -1 when they succeed.
 *	If you specify an invalid sysno, syscall returns -1 with errno = ENOSYS.
 *	Example:
 *	#include <unistd.h>
 *	#include <sys/syscall.h>
 *	#include <errno.h>
 *	...
 *	int rc;
 *	rc = syscall(SYS_chmod, "/etc/passwd", 0444);
 *	if (rc == -1)
 *	fprintf(stderr, "chmod failed, errno = %d\n", errno);
 *	This, if all the compatibility stars are aligned, is equivalent to the following preferable
 *	code:
 *	#include <sys/types.h>
 *	#include <sys/stat.h>
 *	#include <errno.h>
 *
 *	...
 *	int rc;
 *	rc = chmod("/etc/passwd", 0444);
 *	if (rc == -1)
 *	fprintf(stderr, "chmod failed, errno = %d\n", errno);
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

int main()
{
	syscall(SYS_chmod, "-x", "a.out");


	return 0;
}
