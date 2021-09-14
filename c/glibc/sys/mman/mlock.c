/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:27 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:31 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:15 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void demo1()
{
	const int alloc_size = 32 * 1024 * 1024;
	char* memory = malloc (alloc_size);
	mlock (memory, alloc_size);
	size_t i;
	size_t page_size = getpagesize ();
	for (i = 0; i < alloc_size; i += page_size)
		memory[i] = 0;
}

int main()
{
	demo1();

	int *a = malloc(10);
	printf("%p, %p\n", a, a+10);

	a[9] = 20;

	/**
	 *	The mlock family of system calls allows a program 
	 *	to lock some or all of its address space into
	 *	physical memory. This prevents Linux from paging 
	 *	this memory to swap space, even if the
	 *	program hasn't accessed it for a while.
	 * 禁止系统将该内存分页至swap交换空间
	 */
	mlock(a+10, 10);

	realloc(a, 20);

	a[18] = 11;
	a[10] = 10;
	a[2]  = 12;

	printf("a[10] = %d\n", a[10]);

	return 0;
}



