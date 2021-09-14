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
 *	6.54.12 Push/Pop Macro Pragmas
 *	For compatibility with Microsoft Windows compilers, GCC supports ‘#pragma
 *	push_macro("macro_name")’ and ‘#pragma pop_macro("macro_name")’.
 *	#pragma push_macro("macro_name")
 *	This pragma saves the value of the macro named as macro name to the top of
 *	the stack for this macro.
 *
 *	#pragma pop_macro("macro_name")
 *	This pragma sets the value of the macro named as macro name to the value
 *	on top of the stack for this macro. If the stack for macro name is empty, the
 *	value of the macro remains unchanged.
 *	For example:
 *	#define X 1
 *	#pragma push_macro("X")
 *	#undef X
 *	#define X -1
 *	#pragma pop_macro("X")
 *	int x [X];
 *	In this example, the defnition of X as 1 is saved by #pragma push_macro and restored
 *	by #pragma pop_macro.
 */


#include <stdio.h>


#define X 1
#pragma push_macro("X")
#undef X
#define X -1
#pragma pop_macro("X")
//int x [X];


int main()
{
	printf("%d\n", X);
		
	return 0;
}
