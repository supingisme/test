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
 *	aligned (alignment)
 *	This attribute specifes a minimum alignment for the variable or structure feld,
 *	measured in bytes. For example, the declaration:
 *	int x __attribute__ ((aligned (16))) = 0;
 *	causes the compiler to allocate the global variable x on a 16-byte boundary. On
 *	a 68040, this could be used in conjunction with an asm expression to access the
 *	move16 instruction which requires 16-byte aligned operands.
 *	You can also specify the alignment of structure felds. For example, to create a
 *	double-word aligned int pair, you could write:
 *	struct foo { int x[2] __attribute__ ((aligned (8))); };
 *	This is an alternative to creating a union with a double member that forces
 *	the union to be double-word aligned.
 *	As in the preceding examples, you can explicitly specify the alignment (in bytes)
 *	that you wish the compiler to use for a given variable or structure feld. Al
 *	ternatively, you can leave out the alignment factor and just ask the compiler
 *	to align a variable or feld to the default alignment for the target architecture
 *	you are compiling for. The default alignment is sufcient for all scalar types,
 *	but may not be enough for all vector types on a target which supports vector
 *	operations. The default alignment is fxed for a particular target ABI.
 *	Gcc also provides a target specifc macro __BIGGEST_ALIGNMENT__, which is
 *	the largest alignment ever used for any data type on the target machine you
 *	are compiling for. For example, you could write:
 *	short array[3] __attribute__ ((aligned (__BIGGEST_ALIGNMENT__)));
 *	The compiler automatically sets the alignment for the declared variable or feld
 *	to __BIGGEST_ALIGNMENT__. Doing this can often make copy operations more
 *	efcient, because the compiler can use whatever instructions copy the biggest
 *	chunks of memory when performing copies to or from the variables or felds that
 *	you have aligned this way. Note that the value of __BIGGEST_ALIGNMENT__ may
 *	change depending on command line options.
 *	When used on a struct, or struct member, the aligned attribute can only
 *	increase the alignment; in order to decrease it, the packed attribute must be
 *	specifed as well. When used as part of a typedef, the aligned attribute can
 *	both increase and decrease alignment, and specifying the packed attribute will
 *	generate a warning.
 *	Note that the eﬀectiveness of aligned attributes may be limited by inherent
 *	limitations in your linker. On many systems, the linker is only able to arrange
 *	for variables to be aligned up to a certain maximum alignment. (For some
 *	linkers, the maximum supported alignment may be very very small.) If your
 *	linker is only able to align variables up to a maximum of 8 byte alignment, then
 *	specifying aligned(16) in an __attribute__ will still only provide you with
 *	8 byte alignment. See your linker documentation for further information.
 *	The aligned attribute can also be used for functions (see Section 6.29 [Function
 *	Attributes], page 301.)
 */

#include <stdio.h>

struct A{
	double a;
	char b;
	double c;
	int d;
}__attribute__((packed));//这里用aligned(1)好像没有啊

struct B{
	int a:1;
	int b:1;
	int c:1;
	int d:1;
	int e:1;
}__attribute__((packed));

int main()
{
	printf("%d, %d\n", sizeof(struct A), sizeof(struct B));
}












