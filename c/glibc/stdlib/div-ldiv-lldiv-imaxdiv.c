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
/*	int quot;	
 *	int rem;
 *
 *	20.2 Integer Division
 *	This section describes functions for performing integer division. These functions are redun
 *	dant when GNU CC is used, because in GNU C the ‘/’ operator always rounds towards
 *	zero. But in other C implementations, ‘/’ may round diﬀerently with negative arguments.
 *	div and ldiv are useful because they specify how to round the quotient: towards zero. The
 *	remainder has the same sign as the numerator.
 *	These functions are specifed to return a result r such that the value
 *	r.quot*denominator + r.rem equals numerator.
 *	To use these facilities, you should include the header fle ‘stdlib.h’ in your program.
 *	div_t [Data Type]
 *	This is a structure type used to hold the result returned by the div function. It has
 *	the following members:
 *	int quot The quotient from the division.
 *	int rem The remainder from the division.
 *
 *	div_t div (int numerator, int denominator) [Function]
 *	This function div computes the quotient and remainder from the division of numer
 *	ator by denominator, returning the result in a structure of type div_t.
 *	If the result cannot be represented (as in a division by zero), the behavior is undefned.
 *	Here is an example, albeit not a very useful one.
 *	div_t result;
 *	result = div (20, -6);
 *	Now result.quot is -3 and result.rem is 2.
 *	ldiv_t [Data Type]
 *	This is a structure type used to hold the result returned by the ldiv function. It has
 *	the following members:
 *	long int quot
 *	The quotient from the division.
 *	long int rem
 *	The remainder from the division.
 *	(This is identical to div_t except that the components are of type long int rather
 *	than int.)
 *	ldiv_t ldiv (long int numerator, long int denominator) [Function]
 *	The ldiv function is similar to div, except that the arguments are of type long int
 *	and the result is returned as a structure of type ldiv_t.
 *	lldiv_t [Data Type]
 *	This is a structure type used to hold the result returned by the lldiv function. It
 *	has the following members:
 *	long long int quot
 *	The quotient from the division.
 *	long long int rem
 *	The remainder from the division.
 *	(This is identical to div_t except that the components are of type long long int
 *	rather than int.)
 *	lldiv_t lldiv (long long int numerator, long long int denominator) [Function]
 *	The lldiv function is like the div function, but the arguments are of type long long
 *	int and the result is returned as a structure of type lldiv_t.
 *	The lldiv function was added in ISO C99.
 *	imaxdiv_t [Data Type]
 *	This is a structure type used to hold the result returned by the imaxdiv function. It
 *	has the following members:
 *	intmax_t quot
 *	The quotient from the division.
 *	intmax_t rem
 *	The remainder from the division.
 *
 *	(This is identical to div_t except that the components are of type intmax_t rather
 *	than int.)
 *	See Section 20.1 [Integers], page 509 for a description of the intmax_t type.
 *	imaxdiv_t imaxdiv (intmax t numerator, intmax t denominator) [Function]
 *	The imaxdiv function is like the div function, but the arguments are of type intmax_t
 *	and the result is returned as a structure of type imaxdiv_t.
 *	See Section 20.1 [Integers], page 509 for a description of the intmax_t type.
 *	The imaxdiv function was added in ISO C99.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	div_t result = div(23, 7);

	printf("quot:%d, rem:%d\n", result.quot, result.rem);

	return 0;
}
