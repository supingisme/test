/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	void * __builtin_return_address (unsigned int level) [Built-in Function]
 *	This function returns the return address of the current function, or of one of its callers.
 *	The level argument is number of frames to scan up the call stack. A value of 0 yields
 *	the return address of the current function, a value of 1 yields the return address of
 *	the caller of the current function, and so forth. When inlining the expected behavior
 *	is that the function will return the address of the function that will be returned to.
 *	To work around this behavior use the noinline function attribute.
 *	The level argument must be a constant integer.
 *	On some machines it may be impossible to determine the return address of any
 *	function other than the current one; in such cases, or when the top of the stack has
 *	been reached, this function will return 0 or a random value. In addition, __builtin_
 *	frame_address may be used to determine if the top of the stack has been reached.
 *	Additional post-processing of the returned value may be needed, see __builtin_
 *	extract_return_address.
 *	This function should only be used with a nonzero argument for debugging purposes.
 */

#include <stdio.h>

typedef void* (*fptr)(void);

fptr p = NULL, p2 = NULL;

void* f1()
{
	p2 = __builtin_return_address(0);
	p = __builtin_return_address(1);

	//p();

	//printf("f1: %p, %p\n", f1, p);

	return p;
}


int main()
{
	fptr pf = f1();

	printf("p=%p, p2=%p, f1=%p, main=%p\n", p, p2, f1(), main);

	return 0;
}
