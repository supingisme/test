/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:14 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:25 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 09:07:09 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*
 *	int signbit (ﬂoat-type x) [Function]
 *	signbit is a generic macro which can work on all ﬂoating-point types. It returns a
 *	nonzero value if the value of x has its sign bit set.
 *	This is not the same as x < 0.0, because IEEE 754 ﬂoating point allows zero to
 *	be signed. The comparison -0.0 < 0.0 is false, but signbit (-0.0) will return a
 *	nonzero value.
 */

#include <stdio.h>
#include <math.h>

int main()
{
	float a = -12;
	int b = signbit(a);

	printf("a = %f, b = %d\n", a, b);

	a = 1;
	b = signbit(a);
	printf("%f:%d\n", a, b);

	return 0;
}
