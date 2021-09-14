/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	FLT_ROUNDS
 *	This value characterizes the rounding mode for ﬂoating point addition. The
 *	following values indicate standard rounding modes:
 *	-1 The mode is indeterminable.
 *	0 Rounding is towards zero.
 *	1 Rounding is to the nearest number.
 *	2 Rounding is towards positive infnity.
 *	3 Rounding is towards negative infnity.
 *	Any other value represents a machine-dependent nonstandard rounding mode.
 *	On most machines, the value is 1, in accordance with the IEEE standard for
 *	ﬂoating point.
 *	Here is a table showing how certain values round for each possible value of
 *	FLT_ROUNDS, if the other aspects of the representation match the IEEE single
 *	precision standard.
 *	0 1 2 3
 *	1.00000003 1.0 1.0 1.00000012 1.0
 *	1.00000007 1.0 1.00000012 1.00000012 1.0
 *	-1.00000003 -1.0 -1.0 -1.0 -1.00000012
 *	-1.00000007 -1.0 -1.00000012 -1.0 -1.00000012
 *	FLT_RADIX
 *	This is the value of the base, or radix, of the exponent representation. This is
 *	guaranteed to be a constant expression, unlike the other macros described in
 *	this section. The value is 2 on all machines we know of except the IBM 360
 *	and derivatives.
 *	FLT_MANT_DIG
 *	This is the number of base-FLT_RADIX digits in the ﬂoating point mantissa
 *	for the float data type. The following expression yields 1.0 (even though
 *	mathematically it should not) due to the limited number of mantissa digits:
 *	float radix = FLT_RADIX;
 *	1.0f + 1.0f / radix / radix / ... / radix
 *	where radix appears FLT_MANT_DIG times.
 *	DBL_MANT_DIG
 *	LDBL_MANT_DIG
 *	This is the number of base-FLT_RADIX digits in the ﬂoating point mantissa for
 *	the data types double and long double, respectively.
 *
 *	FLT_DIG
 *	This is the number of decimal digits of precision for the float data type.
 *	Technically, if p and b are the precision and base (respectively) for the rep
 *	resentation, then the decimal precision q is the maximum number of decimal
 *	digits such that any ﬂoating point number with q base 10 digits can be rounded
 *	to a ﬂoating point number with p base b digits and back again, without change
 *	to the q decimal digits.
 *	The value of this macro is supposed to be at least 6, to satisfy ISO C.
 *	DBL_DIG
 *	LDBL_DIG
 *	These are similar to FLT_DIG, but for the data types double and long double,
 *	respectively. The values of these macros are supposed to be at least 10.
 *	FLT_MIN_EXP
 *	This is the smallest possible exponent value for type float. More precisely,
 *	is the minimum negative integer such that the value FLT_RADIX raised to this
 *	power minus 1 can be represented as a normalized ﬂoating point number of
 *	type float.
 *	DBL_MIN_EXP
 *	LDBL_MIN_EXP
 *	These are similar to FLT_MIN_EXP, but for the data types double and long
 *	double, respectively.
 *	FLT_MIN_10_EXP
 *	This is the minimum negative integer such that 10 raised to this power minus 1
 *	can be represented as a normalized ﬂoating point number of type float. This
 *	is supposed to be -37 or even less.
 *	DBL_MIN_10_EXP
 *	LDBL_MIN_10_EXP
 *	These are similar to FLT_MIN_10_EXP, but for the data types double and long
 *	double, respectively.
 *	FLT_MAX_EXP
 *	This is the largest possible exponent value for type float. More precisely, this
 *	is the maximum positive integer such that value FLT_RADIX raised to this power
 *	minus 1 can be represented as a ﬂoating point number of type float.
 *	DBL_MAX_EXP
*	LDBL_MAX_EXP
*	These are similar to FLT_MAX_EXP, but for the data types double and long
*	double, respectively.
*	FLT_MAX_10_EXP
*	This is the maximum positive integer such that 10 raised to this power minus 1
*	can be represented as a normalized ﬂoating point number of type float. This
*	is supposed to be at least 37.
*
*	DBL_MAX_10_EXP
*	LDBL_MAX_10_EXP
*	These are similar to FLT_MAX_10_EXP, but for the data types double and long
*	double, respectively.
*	FLT_MAX
*	The value of this macro is the maximum number representable in type float.
*	It is supposed to be at least 1E+37. The value has type float.
*	The smallest representable number is - FLT_MAX.
*	DBL_MAX
*	LDBL_MAX
*	These are similar to FLT_MAX, but for the data types double and long double,
	*	respectively. The type of the macro’s value is the same as the type it describes.
	*	FLT_MIN
	*	The value of this macro is the minimum normalized positive ﬂoating point
	*	number that is representable in type float. It is supposed to be no more than
	*	1E-37.
	*	DBL_MIN
	*	LDBL_MIN
	*	These are similar to FLT_MIN, but for the data types double and long double,
	*	respectively. The type of the macro’s value is the same as the type it describes.
	*	FLT_EPSILON
	*	This is the minimum positive ﬂoating point number of type float such that
	*	1.0 + FLT_EPSILON != 1.0 is true. It’s supposed to be no greater than 1E-5.
	*	DBL_EPSILON
	*	LDBL_EPSILON
	*	These are similar to FLT_EPSILON, but for the data types double and long
	*	double, respectively. The type of the macro’s value is the same as the type it
	*	describes. The values are not supposed to be greater than 1E-9.
 */
