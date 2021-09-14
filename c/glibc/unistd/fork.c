/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/**
 *	fork()
 *		是UNIX派生信新进程的唯一方法
 *
 *	pid_t fork(void);
 *		fork返回两次，可以通过调用getppid()取得父进程ID
 *
 *
 *
 *	pid_t fork (void) [Function]
 *	The fork function creates a new process.
 *	If the operation is successful, there are then both parent and child processes and both
 *	see fork return, but with diﬀerent values: it returns a value of 0 in the child process
 *	and returns the child’s process ID in the parent process.
 *	If process creation failed, fork returns a value of -1 in the parent process. The
 *	following errno error conditions are defned for fork:
 *	EAGAIN There aren’t enough system resources to create another process, or the
 *	user already has too many processes running. This means exceeding
 *	the RLIMIT_NPROC resource limit, which can usually be increased; see
 *	Section 22.2 [Limiting Resource Usage], page 575.
 *	ENOMEM The process requires more space than the system can supply.
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("1: %d\n", fork());
		
	printf("2: %d\n", getppid());

	while(1);
	return 1;
}
