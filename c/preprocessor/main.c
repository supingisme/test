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
 *	C preprocessors vary in some details. This manual discusses the GNU C preprocessor,
 *	which provides a small superset of the features of ISO Standard C. In its default mode,
 *	the GNU C preprocessor does not do a few things required by the standard. These are
 *	features which are rarely, if ever, used, and may cause surprising changes to the meaning of
 *	a program which does not expect them. To get strict ISO Standard C, you should use the
 *	‘-std=c90’ or ‘-std=c99’ options, depending on which version of the standard you want.
 *	To get all the mandatory diagnostics, you must also use ‘-pedantic’. See Chapter 12
 *	[Invocation], page 55
 */

#include <stdio.h>
#include "hdr.h"

int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\n", i);
	}
}
