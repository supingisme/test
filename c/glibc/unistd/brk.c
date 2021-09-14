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
#include <unistd.h>
#include <stdio.h>

int main()
{
	int *p;


	printf("1\n");
	//用来改变程序间断点的位置
	brk(p);

	printf("2\n");

	return 0;
}

/*
 *int brk (void *addr) [Function]
 brk sets the high end of the calling process’ data segment to addr.
 The address of the end of a segment is defned to be the address of the last byte in
 the segment plus 1.
 The function has no eﬀect if addr is lower than the low end of the data segment.
 (This is considered success, by the way).
 The function fails if it would cause the data segment to overlap another segment or
 exceed the process’ data storage limit (see Section 22.2 [Limiting Resource Usage],
 page 575).
 The function is named for a common historical case where data storage and the stack
 are in the same segment. Data storage allocation grows upward from the bottom of
 the segment while the stack grows downward toward it from the top of the segment
 and the curtain between them is called the break.
 The return value is zero on success. On failure, the return value is -1 and errno is
 set accordingly. The following errno values are specifc to this function:
 ENOMEM The request would cause the data segment to overlap another segment or
 exceed the process’ data storage limit.

 void *sbrk (ptrdiﬀ t delta) [Function]
 This function is the same as brk except that you specify the new end of the data
 segment as an oﬀset delta from the current end and on success the return value is the
 address of the resulting end of the data segment instead of zero.
 This means you can use ‘sbrk(0)’ to fnd out what the current end of the data
 segment is.
 */
