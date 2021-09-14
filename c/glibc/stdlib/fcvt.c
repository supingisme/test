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
/*
 *	Old-fashioned System V number-to-string functions
 *
 *	char * ecvt (double value, int ndigit, int *decpt, int *neg) [Function]
 *	The function ecvt converts the ﬂoating-point number value to a string with at most
 *	ndigit decimal digits. The returned string contains no decimal point or sign. The
 *	frst digit of the string is non-zero (unless value is actually zero) and the last digit is
 *	rounded to nearest. *decpt is set to the index in the string of the frst digit after the
 *	decimal point. *neg is set to a nonzero value if value is negative, zero otherwise.
 *	If ndigit decimal digits would exceed the precision of a double it is reduced to a
 *	system-specifc value.
 *	The returned string is statically allocated and overwritten by each call to ecvt.
 *	If value is zero, it is implementation defned whether *decpt is 0 or 1.
 *	For example: ecvt (12.3, 5, &d, &n) returns "12300" and sets d to 2 and n to 0.
 *
 *
 *	char * fcvt (double value, int ndigit, int *decpt, int *neg) [Function]
 *	The function fcvt is like ecvt, but ndigit specifes the number of digits after the
 *	decimal point. If ndigit is less than zero, value is rounded to the ndigit + 1’th place
 *	to the left of the decimal point. For example, if ndigit is -1, value will be rounded to
 *	the nearest 10. If ndigit is negative and larger than the number of digits to the left
 *	of the decimal point in value, value will be rounded to one signifcant digit.If ndigit decimal digits would exceed the precision of a double it is reduced to a
 *	system-specifc value.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int d, n;
	char *s = fcvt(-12312.11300, 11, &d, &n);

	/**
	 *	d是小数点前面的位数
	 *	n负数的话n为非零
	 */

	printf("s = %s, d = %d, n = %d\n",s,  d, n);



	return 0;
}
