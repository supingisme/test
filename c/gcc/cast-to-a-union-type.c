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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	6.27 Cast to a Union Type
 *	A cast to union type is similar to other casts, except that the type specifed is a union type.
 *	You can specify the type either with union tag or with a typedef name. A cast to union
 *	is actually a constructor though, not a cast, and hence does not yield an lvalue like normal
 *	casts. (See Section 6.24 [Compound Literals], page 298.)
 *	The types that may be cast to the union type are those of the members of the union.
 *	Thus, given the following union and variables:
 *	union foo { int i; double d; };
 *	int x;
 *	double y;
 *	both x and y can be cast to type union foo.
 *	Using the cast as the right-hand side of an assignment to a variable of union type is
 *	equivalent to storing in a member of the union:
 *	union foo u;
 *	u = (union foo) x ≡ u.i = x
 *	u = (union foo) y ≡ u.d = y
 *	You can also use the union cast as a function argument:
 *	void hack (union foo);
 *	hack ((union foo) x);
 */


#include <stdio.h>
#include <stdint.h>

union endian_s{
	uint16_t i16;
	uint8_t i8;
};

static union {
	    char            c[4];
		    unsigned long   mylong;
}endian_test = {{'l', '?', '?', 'b'}};
#define ENDIANER ((char )endian_test.mylong)

int main()
{
	union endian_s t;
	t.i8 = 1;

	printf("%d\n", t.i16>>8);
}	
