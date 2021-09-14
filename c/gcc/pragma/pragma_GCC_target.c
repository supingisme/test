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
 *	#pragma GCC target ("string"...)
 *	This pragma allows you to set target specifc options for functions defned later
 *	in the source fle. One or more strings can be specifed. Each function that
 *	is defned after this point will be as if attribute((target("STRING"))) was
 *	specifed for that function. The parenthesis around the options is optional. See
 *	Section 6.29 [Function Attributes], page 301, for more information about the
 *	target attribute and the attribute syntax.
 *	The ‘#pragma GCC target’ pragma is not implemented in GCC versions earlier
 *	than 4.4, and is currently only implemented for the 386 and x86 64 backends.
 */

#include <stdio.h>

#pragma GCC target("STRING")
int fun()
{
#ifdef STRING
	printf("fun\n");
#endif
}

int main()
{
	//#pragma GCC target("STRING")

	fun();

	#ifdef STRING
	printf("adf\n");
#endif

	return 0;
}	
