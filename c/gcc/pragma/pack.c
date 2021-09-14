/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.54.8 Structure-Packing Pragmas
 *	For compatibility with Microsoft Windows compilers, GCC supports a set of #pragma direc
 *	tives which change the maximum alignment of members of structures (other than zero-width
 *	bitfelds), unions, and classes subsequently defned. The n value below always is required
 *	to be a small power of two and specifes the new alignment in bytes.
 *
 *
 *	1. #pragma pack(n) simply sets the new alignment.
 *	2. #pragma pack() sets the alignment to the one that was in eﬀect when compilation
 *	started (see also command line option ‘-fpack-struct[=<n>]’ see Section 3.18 [Code
 *	Gen Options], page 256).
 *	3. #pragma pack(push[,n]) pushes the current alignment setting on an internal stack
 *	and then optionally sets the new alignment.
 *	4. #pragma pack(pop) restores the alignment setting to the one saved at the top of the
 *	internal stack (and removes that stack entry). Note that #pragma pack([n]) does not
 *	inﬂuence this internal stack; thus it is possible to have #pragma pack(push) followed
 *	by multiple #pragma pack(n) instances and fnalized by a single #pragma pack(pop).
 *	Some targets, e.g. i386 and powerpc, support the ms_struct #pragma which lays out a
 *	structure as the documented __attribute__ ((ms_struct)).
 *	1. #pragma ms_struct on turns on the layout for structures declared.
 *	2. #pragma ms_struct off turns oﬀ the layout for structures declared.
 *	3. #pragma ms_struct reset goes back to the default layout.
 */

#include <stdio.h>

#pragma pack(1)
struct A{
	int a;
	char b;
	double c;
};


int main()
{
	printf("%d\n", sizeof(struct A));

	return 0;
}
