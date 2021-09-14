/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:07 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.47 Using vector instructions through built-in functions
 *	On some targets, the instruction set contains SIMD vector instructions that operate on
 *	multiple values contained in one large register at the same time. For example, on the i386
 *	the MMX, 3DNow! and SSE extensions can be used this way.
 *	The frst step in using these extensions is to provide the necessary data types. This should
 *	be done using an appropriate typedef:
 *	typedef int v4si __attribute__ ((vector_size (16)));
 *	The int type specifes the base type, while the attribute specifes the vector size for the
 *	variable, measured in bytes. For example, the declaration above causes the compiler to set
 *	the mode for the v4si type to be 16 bytes wide and divided into int sized units. For a
 *	32-bit int this means a vector of 4 units of 4 bytes, and the corresponding mode of foo will
 *	be V4SI.
 */

typedef int v4si __attribute__ ((vector_size (16)));

v4si a, b, c;

/*
v4si f (v4si a, v4si b, v4si c)
{
	v4si tmp = __builtin_addv4si (a, b);
	return (v4si)__builtin_mulv4si (tmp, c);
}
*/

int main()
{

}
