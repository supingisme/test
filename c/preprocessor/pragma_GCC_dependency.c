/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:40 CST. */
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
 *	C99 introduces the _Pragma operator. This feature addresses a major problem with
 *	‘#pragma’: being a directive, it cannot be produced as the result of macro expansion.
 *	_Pragma is an operator, much like sizeof or defined, and can be embedded in a macro.
 *	Its syntax is _Pragma (string-literal), where string-literal can be either a normal or
 *	wide-character string literal. It is destringized, by replacing all ‘\\’ with a single ‘\’ and all
 *	‘\"’ with a ‘"’. The result is then processed as if it had appeared as the right hand side of
 *	a ‘#pragma’ directive. For example,
 *	_Pragma ("GCC dependency \"parse.y\"")
 *	has the same eﬀect as #pragma GCC dependency "parse.y". The same eﬀect could be
 *	achieved using macros, for example
 *	#define DO_PRAGMA(x) _Pragma (#x)
 *	DO_PRAGMA (GCC dependency "parse.y")
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	#pragma GCC dependency "line.c"
	#pragma GCC dependency "RongTao.txt"
	return 0;
}
