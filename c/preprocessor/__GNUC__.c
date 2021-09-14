/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
/*
 *	__GNUC__
 *	__GNUC_MINOR__
 *	__GNUC_PATCHLEVEL__
 *	These macros are defned by all GNU compilers that use the C preproces
 *	sor: C, C++, Objective-C and Fortran. Their values are the major version,
 *	minor version, and patch level of the compiler, as integer constants. For ex
 *	ample, GCC 3.2.1 will defne __GNUC__ to 3, __GNUC_MINOR__ to 2, and __
 *	GNUC_PATCHLEVEL__ to 1. These macros are also defned if you invoke the
 *	preprocessor directly.
 *	__GNUC_PATCHLEVEL__ is new to GCC 3.0; it is also present in the widely-used
 *	development snapshots leading up to 3.0 (which identify themselves as GCC
 *	2.96 or 2.97, depending on which snapshot you have).
 *	If all you need to know is whether or not your program is being compiled by
 *	GCC, or a non-GCC compiler that claims to accept the GNU C dialects, you
 *	can simply test __GNUC__. If you need to write code which depends on a specifc
 *	version, you must be more careful. Each time the minor version is increased,
 *	the patch level is reset to zero; each time the major version is increased (which
 *	happens rarely), the minor version and patch level are reset. If you wish to use
 *	the predefned macros directly in the conditional, you will need to write it like
 *	this:
 * / * Test for GCC > 3.2.0 
#if __GNUC__ > 3 || \
	(__GNUC__ == 3 && (__GNUC_MINOR__ > 2 || \
					   (__GNUC_MINOR__ == 2 && \
						__GNUC_PATCHLEVEL__ > 0))
	 Another approach is to use the predefned macros to calculate a single number,
	 then compare that against a threshold:
#define GCC_VERSION (__GNUC__ * 10000 \
	+ __GNUC_MINOR__ * 100 \
	+ __GNUC_PATCHLEVEL__)
	 ...
 */

/* Test for GCC > 3.2.0 */
/*
#if __GNUC__ > 3 || \
	(__GNUC__ == 3 && (__GNUC_MINOR__ > 2 || \
					   (__GNUC_MINOR__ == 2 && \
						__GNUC_PATCHLEVEL__ > 0))
*/
#define GCC_VERSION() (__GNUC__ * 10000 \
	+ __GNUC_MINOR__ * 100 \
	+ __GNUC_PATCHLEVEL__)


#include <stdio.h>

int main()
{
	printf("%d\n", GCC_VERSION());
}
