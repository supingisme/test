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
double log (double x) [Function]
float logf (ﬂoat x) [Function]
long double logl (long double x) [Function]
These functions compute the natural logarithm of x. exp (log (x)) equals x, exactly
in mathematics and approximately in C.
If x is negative, log signals a domain error. If x is zero, it returns negative infnity;
if x is too close to zero, it may signal overﬂow.
double log10 (double x) [Function]
float log10f (ﬂoat x) [Function]
long double log10l (long double x) [Function]
These functions return the base-10 logarithm of x. log10 (x) equals log (x) / log
(10).
double log2 (double x) [Function]
float log2f (ﬂoat x) [Function]
long double log2l (long double x) [Function]
These functions return the base-2 logarithm of x. log2 (x) equals log (x) / log
(2).
double logb (double x) [Function]
float logbf (ﬂoat x) [Function]
long double logbl (long double x) [Function]
These functions extract the exponent of x and return it as a ﬂoating-point value. If
FLT_RADIX is two, logb is equal to floor (log2 (x)), except it’s probably faster.
If x is de-normalized, logb returns the exponent x would have if it were normalized.
If x is infnity (positive or negative), logb returns 1. If x is zero, logb returns 1.
It does not signal.
int ilogb (double x) [Function]
int ilogbf (ﬂoat x) [Function]
int ilogbl (long double x) [Function]
These functions are equivalent to the corresponding logb functions except that they
return signed integer values.
*/