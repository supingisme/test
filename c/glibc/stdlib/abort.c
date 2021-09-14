/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	void abort (void) [Function]
 *	The abort function causes abnormal program termination. This does not execute
 *	cleanup functions registered with atexit or on_exit.
 *	This function actually terminates the process by raising a SIGABRT signal, and your
 *	program can include a handler to intercept this signal; see Chapter 24 [Signal Han
 *	dling], page 602.
 *
 *	You can abort your program using the abort function. The prototype for this function is
 *	in ‘stdlib.h’.
 */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int i)
{
	printf("handler: hello world\n");
	exit(EXIT_FAILURE);
}

int main()
{
	signal(SIGABRT, handler);

	abort();

	return 0;
}
