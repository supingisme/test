/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
 *	pid_t wait (int *status-ptr) [Function]
 *	This is a simplifed version of waitpid, and is used to wait until any one child process
 *	terminates. The call:
 *	wait (&status)
 *	is exactly equivalent to:
 *	waitpid (-1, &status, 0)
 *	This function is a cancellation point in multi-threaded programs. This is a problem
 *	if the thread allocates some resources (like memory, fle descriptors, semaphores or
 *	whatever) at the time wait is called. If the thread gets canceled these resources stay
 *	allocated until the program ends. To avoid this calls to wait should be protected
 *	using cancellation handlers.
 */

#include <sys/wait.h>
//pid_t wait (int *status-ptr);

#include <signal.h>
#include <stdio.h>
#include <errno.h>

#include <stdlib.h>

void sig_handler(int signo)
{
	pid_t pid;
	int stat;

	pid = wait(&stat);
	printf("child %d ternimated\n", pid);
	return;
}

void main()
{
	signal(SIGINT, sig_handler);

	while(1){sleep(1);};

	return;
}
