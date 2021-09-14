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
 *	int atexit (void (*function) (void)) [Function]
 *	The atexit function registers the function function to be called at normal program
 *	termination. The function is called with no arguments.
 *	The return value from atexit is zero on success and nonzero if the function cannot
 *	be registered.
 *
 *
 *	int on_exit (void (*function)(int status, void *arg), void *arg) [Function]
 *	This function is a somewhat more powerful variant of atexit. It accepts two argu
 *	ments, a function function and an arbitrary pointer arg. At normal program termi
 *	nation, the function is called with two arguments: the status value passed to exit,
 *	and the arg.
 *	This function is included in the GNU C library only for compatibility for SunOS, and
 *	may not be supported by other implementations.
 */
//CAS
#include <stdio.h>
#include <stdlib.h>
void
bye (int status, void *arg)
{
	puts ("Goodbye, cruel world....");
}
int
main (void)
{
	on_exit (bye, NULL);
	exit (EXIT_SUCCESS);
}
