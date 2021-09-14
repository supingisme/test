/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:07 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *
 */

#include <stdio.h>

/*
#define sin(x) \
	({ double __value, __arg = (x); \
	 asm ("fsinx %1,%0": "=f" (__value): "f" (__arg)); \
	 __value; })
*/
int f1 asm ("myfoo") = 2;

int foo ()
{
	int x = 42;
	int *y = &x;
	int result;
	/*
	asm ("magic stuff accessing an 'int' pointed to by '%1'"
			"=&d" (r) : "a" (y), "m" (*y));
			*/
	/*
	asm ("movl %0,r9\n\tmovl %1,r10\n\tcall _foo"
			: "g" (from), "g" (to)
			: "r9", "r10");*/


	printf("f1 = %d\n", f1);

	//sin(1);

	//asm ("foo" : "=t" (a) : "f" (b));

	return result;
}

int main()
{
	printf("foo = %d\n", foo());
}
