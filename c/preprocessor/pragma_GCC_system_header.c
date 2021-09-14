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
 *	There is also a directive, #pragma GCC system_header, which tells GCC to consider the
 *	rest of the current include fle a system header, no matter where it was found. Code that
 *	comes before the ‘#pragma’ in the fle will not be aﬀected. #pragma GCC system_header
 *	has no eﬀect in the primary source fle.
 *	On very old systems, some of the pre-defned system header directories get even more
 *	special treatment. GNU C++ considers code in headers found in those directories to be
 *	surrounded by an extern "C" block. There is no way to request this behavior with a
 *	‘#pragma’, or from the command line.
 */

//高速gcc下面的头文件是系统中的头文件，不管找不找得到
#pragma GCC system_header
#include <stdio.h>
#include <stdlib.h>

int main()
{
//#pragma GCC system_header
	printf("Hello\n");
	//fun();
	return 0;
}
