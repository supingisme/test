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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.48 Oﬀsetof
 *	GCC implements for both C and C++ a syntactic extension to implement the offsetof
 *	macro.
 *	primary:
 *	"__builtin_offsetof" "(" typename "," offsetof_member_designator ")"
 *	offsetof_member_designator:
 *	identifier
 *	| offsetof_member_designator "." identifier
 *	| offsetof_member_designator "[" expr "]"
 *	This extension is sufcient such that
 *	#define offsetof(type, member) __builtin_offsetof (type, member)
 *	is a suitable defnition of the offsetof macro. In C++, type may be dependent. In either
 *	case, member may consist of a single identifer, or a sequence of member accesses and array
 *	references.
 */

#include <stdio.h>

#define offsetof(type, member) __builtin_offsetof(type, member)

struct A{
	int a;
	int b;
};

int main()
{
	printf("%d\n", offsetof(struct A, b));

	return 0;
}
