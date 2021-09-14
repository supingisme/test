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
 *	20.4 Floating-Point Number Classifcation Functions
 *	ISO C99 defnes macros that let you determine what sort of ﬂoating-point number a variable
 *	holds.
 *	int fpclassify (ﬂoat-type x) [Macro]
 *	This is a generic macro which works on all ﬂoating-point types and which returns a
 *	value of type int. The possible values are:
 *	FP_NAN The ﬂoating-point number x is “Not a Number” (see Section 20.5.2 [In
 *	fnity and NaN], page 515)
 *	FP_INFINITE
 *	The value of x is either plus or minus infnity (see Section 20.5.2 [Infnity
 *	and NaN], page 515)
 *
 *	FP_ZERO The value of x is zero. In ﬂoating-point formats like IEEE 754, where
 *	zero can be signed, this value is also returned if x is negative zero.
 *	FP_SUBNORMAL
 *	Numbers whose absolute value is too small to be represented in the
 *	normal format are represented in an alternate, denormalized format (see
 *	Section A.5.3.1 [Floating Point Representation Concepts], page 809).
 *	This format is less precise but can represent values closer to zero.
 *	fpclassify returns this value for values of x in this alternate format.
 *	FP_NORMAL
 *	This value is returned for all other values of x. It indicates that there is
 *	nothing special about the number.
 *
 *	fpclassify is most useful if more than one property of a number must be tested. There
 *	are more specifc macros which only test one property at a time. Generally these macros
 *	execute faster than fpclassify, since there is special hardware support for them. You
 *	should therefore use the specifc macros whenever possible.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


#define _print_(val) printf("%10s:%d\n", #val, val)


int main()
{
	float f;

	int i, tt;
	for(i=-5;i<5;i++)
	{
		f = 1.0/i;
		tt = fpclassify(f);
		printf("%d\n", tt);
	}

	_print_(FP_NAN);
	_print_(FP_INFINITE);
	_print_(FP_ZERO);
	_print_(FP_SUBNORMAL);
	_print_(FP_NORMAL);

	return 0;
}
