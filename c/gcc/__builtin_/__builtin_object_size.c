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
 *	size_t __builtin_object_size (void * ptr, int type) [Built-in Function]
 *	is a built-in construct that returns a constant number of bytes from ptr to the end of
 *	the object ptr pointer points to (if known at compile time). __builtin_object_size
 *	never evaluates its arguments for side-eﬀects. If there are any side-eﬀects in them,
 *	it returns (size_t) -1 for type 0 or 1 and (size_t) 0 for type 2 or 3. If there are
 *	multiple objects ptr can point to and all of them are known at compile time, the
 *	returned number is the maximum of remaining byte counts in those objects if type
 *	& 2 is 0 and minimum if nonzero. If it is not possible to determine which objects ptr
 *	points to at compile time, __builtin_object_size should return (size_t) -1 for
 *	type 0 or 1 and (size_t) 0 for type 2 or 3.
 *	type is an integer constant from 0 to 3. If the least signifcant bit is clear, objects are
 *	whole variables, if it is set, a closest surrounding subobject is considered the object a
 *	pointer points to. The second bit determines if maximum or minimum of remaining
 *	bytes is computed.
 */

#include <stdio.h>
#include <assert.h>

int main()
{

	struct V { 
		char buf1[10]; 
		int b; 
		char buf2[10]; 
	} var;
	
	char *p = &var.buf1[1], *q = &var.b;
	char *r = NULL;
	/* Here the object p points to is var. */
	//assert (__builtin_object_size (p, 0) == sizeof (var) - 1);
	/* The subobject p points to is var.buf1. */
	//assert (__builtin_object_size (p, 1) == sizeof (var.buf1) - 1);
	/* The object q points to is var. */
	//assert (__builtin_object_size (q, 0)
	//	== (char *) (&var + 1) - (char *) &var.b);
	/* The subobject q points to is var.b. */
	//assert (__builtin_object_size (q, 1) == sizeof (var.b));

	printf("%d\n", __builtin_object_size (p, 0));
	printf("%d\n", __builtin_object_size (p, 1));
	printf("%d\n", __builtin_object_size (p, 2));
	printf("%d\n", __builtin_object_size (p, 3));
	printf("%d\n", __builtin_object_size (q, 0));
	printf("%d\n", __builtin_object_size (q, 1));
	printf("%d\n", __builtin_object_size (q, 2));
	printf("%d\n", __builtin_object_size (q, 3));
	printf("%d\n", __builtin_object_size (r, 0));



	char b[10];
	char *c = &b[5];
	
	printf("%d\n", __builtin_object_size(b, 0));
	printf("%d\n", __builtin_object_size(b, 1));
	printf("%d\n", __builtin_object_size(b, 2));
	printf("%d\n", __builtin_object_size(b, 3));
	printf("%d\n", __builtin_object_size(c, 0));
	













}
