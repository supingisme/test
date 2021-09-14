/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:28 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
 *	int getpriority (int class, int id) [Function]
 *	Return the nice value of a set of processes; class and id specify which ones (see below).
 *	If the processes specifed do not all have the same nice value, this returns the lowest
 *	value that any of them has.
 *	On success, the return value is 0. Otherwise, it is -1 and ERRNO is set accordingly.
 *	The errno values specifc to this function are:
 *	ESRCH The combination of class and id does not match any existing process.
 *	EINVAL The value of class is not valid.
 *	If the return value is -1, it could indicate failure, or it could be the nice value. The
 *	only way to make certain is to set errno = 0 before calling getpriority, then use
 *	errno != 0 afterward as the criterion for failure.
 *
 *
 *	int setpriority (int class, int id, int niceval) [Function]
 *	Set the nice value of a set of processes to niceval; class and id specify which ones (see
 *	below).
 *	The return value is 0 on success, and -1 on failure. The following errno error condi
 *	tion are possible for this function:
 *	ESRCH The combination of class and id does not match any existing process.
 *	EINVAL The value of class is not valid.
 *	EPERM The call would set the nice value of a process which is owned by a diﬀerent
 *	user than the calling process (i.e., the target process’ real or eﬀective uid
 *	does not match the calling process’ eﬀective uid) and the calling process
 *	does not have CAP_SYS_NICE permission.
 *	EACCES The call would lower the process’ nice value and the process does not
 *	have CAP_SYS_NICE permission.
 *
 */
#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	printf("%d\n", getpriority(1, 1));

	perror("getpriority() error");


	printf("%d\n", setpriority(1, 1, 1));
	 
	perror("setpriority() error");

	return 0;
}
