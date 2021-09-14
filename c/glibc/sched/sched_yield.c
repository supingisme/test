/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:21 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*
 *	int sched_yield (void) [Function]
 *	This function voluntarily gives up the process’ claim on the CPU.
 *	Technically, sched_yield causes the calling process to be made immediately ready
 *	to run (as opposed to running, which is what it was before). This means that if it has
 *
 *	absolute priority higher than 0, it gets pushed onto the tail of the queue of processes
 *	that share its absolute priority and are ready to run, and it will run again when its
 *	turn next arrives. If its absolute priority is 0, it is more complicated, but still has the
 *	eﬀect of yielding the CPU to other processes.
 *	If there are no other processes that share the calling process’ absolute priority, this
 *	function doesn’t have any eﬀect.
 *	To the extent that the containing program is oblivious to what other processes in the
 *	system are doing and how fast it executes, this function appears as a no-op.
 *	The return value is 0 on success and in the pathological case that it fails, the return
 *	value is -1 and errno is set accordingly. There is nothing specifc that can go wrong
 *	with this function, so there are no specifc errno values.
 */
#include <sched.h>
#include <errno.h>
#include <stdio.h>

/*
 *	放弃CPU，优先级置于最低，让一个新的线程运行
 */
int sched_yield (void);

int main()
{
	int ret = sched_yield();

	perror("sched_yield: ");

	printf("ret = %d\n", ret);

	return 0;
}
