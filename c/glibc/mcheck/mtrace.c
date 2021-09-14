/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 06月 20日 星期四 08:25:12 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 20日 星期四 08:25:06 CST. */
#include <stdio.h>
#include <mcheck.h>
#include <malloc.h>

/**
 * 定位内存泄漏，
 *	Usage:
 *
 *	[rongtao@localhost mcheck]$ ls
 *	a.out  man-mtrace.txt  mtrace.c
 *	[rongtao@localhost mcheck]$ export MALLOC_TRACE=$PWD/trace.log
 *	[rongtao@localhost mcheck]$ echo $MALLOC_TRACE
 *  /home/rongtao/test/c/glibc/mcheck/trace.log
 *	[rongtao@localhost mcheck]$ ./a.out 
 *	[rongtao@localhost mcheck]$ ls
 *	a.out  man-mtrace.txt  mtrace.c  trace.log
 *	[rongtao@localhost mcheck]$ more trace.log 
 *	= Start
 *	@ ./a.out:[0x400624] + 0x1547460 0x64
 *	@ ./a.out:[0x400634] - 0x1547460
 *	@ ./a.out:[0x40063e] + 0x15474d0 0x3e8
 *	= End
 *	[rongtao@localhost mcheck]$ 
 */

int main()
{
	mtrace();

	char *p = malloc(100);

	free(p);

	p = malloc(1000);

	muntrace();

	return 0;
}	
