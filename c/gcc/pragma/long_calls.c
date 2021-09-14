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
 *	6.54.1 ARM Pragmas
 *	The ARM target defnes pragmas for controlling the default addition of long_call and
 *	short_call attributes to functions. See Section 6.29 [Function Attributes], page 301, for
 *	information about the eﬀects of these attributes.
 *	long_calls
 *	Set all subsequent functions to have the long_call attribute.
 *	no_long_calls
 *	Set all subsequent functions to have the short_call attribute.
 *	long_calls_off
 *	Do not aﬀect the long_call or short_call attributes of subsequent functions.
 */

#include <stdio.h>


int main()
{
	#pragma long_calls
	
#pragma adf asdqwer 

	return 0;
}
