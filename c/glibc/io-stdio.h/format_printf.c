/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*	‘%d’, ‘%i’ Print an integer as a signed decimal number. See Section 12.12.4 [Integer
 *	Conversions], page 248, for details. ‘%d’ and ‘%i’ are synonymous for output,
 *	but are diﬀerent when used with scanf for input (see Section 12.14.3 [Table of
 *	Input Conversions], page 268).
 *	‘%o’ Print an integer as an unsigned octal number. See Section 12.12.4 [Integer
 *	Conversions], page 248, for details.
 *	‘%u’ Print an integer as an unsigned decimal number. See Section 12.12.4 [Integer
 *	Conversions], page 248, for details.
 *	‘%x’, ‘%X’ Print an integer as an unsigned hexadecimal number. ‘%x’ uses lower-case letters
 *	and ‘%X’ uses upper-case. See Section 12.12.4 [Integer Conversions], page 248,
 *	for details.
 *	‘%f’ Print a ﬂoating-point number in normal (fxed-point) notation. See
 *	Section 12.12.5 [Floating-Point Conversions], page 250, for details.
 *	‘%e’, ‘%E’ Print a ﬂoating-point number in exponential notation. ‘%e’ uses lower-case let
 *	ters and ‘%E’ uses upper-case. See Section 12.12.5 [Floating-Point Conversions],
 *	page 250, for details.
 *	‘%g’, ‘%G’ Print a ﬂoating-point number in either normal or exponential notation, which
 *	ever is more appropriate for its magnitude. ‘%g’ uses lower-case letters and ‘%G’
 *	uses upper-case. See Section 12.12.5 [Floating-Point Conversions], page 250, for
 *	details.
 *	‘%a’, ‘%A’ Print a ﬂoating-point number in a hexadecimal fractional notation which the
 *	exponent to base 2 represented in decimal digits. ‘%a’ uses lower-case letters
 *	and ‘%A’ uses upper-case. See Section 12.12.5 [Floating-Point Conversions],
 *	page 250, for details.
 *
 *	‘%c’ Print a single character. See Section 12.12.6 [Other Output Conversions],
 *	page 252.
 *	‘%C’ This is an alias for ‘%lc’ which is supported for compatibility with the Unix
 *	standard.
 *	‘%s’ Print a string. See Section 12.12.6 [Other Output Conversions], page 252.
 *	‘%S’ This is an alias for ‘%ls’ which is supported for compatibility with the Unix
 *	standard.
 *	‘%p’ Print the value of a pointer. See Section 12.12.6 [Other Output Conversions],
 *	page 252.
 *	‘%n’ Get the number of characters printed so far. See Section 12.12.6 [Other Output
 *	Conversions], page 252. Note that this conversion specifcation never produces
 *	any output.
 *	‘%m’ Print the string corresponding to the value of errno. (This is a GNU extension.)
 *	See Section 12.12.6 [Other Output Conversions], page 252.
 *	‘%%’ Print a literal ‘%’ character. See Section 12.12.6 [Other Output Conversions],
 *	page 252.
 */
#include <stdio.h>
#include <errno.h>

int main()
{
	printf("%m, %m, %m, %m, %m, %m\n", errno, 1,12,23,4,45);

	printf("|%13.4a|%13.4f|%13.4e|%13.4g|\n", 1.1, 1.1, 1.1, 1.1);

	return 0;
}
