/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:39 CST. */
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
 *	__DATE__ This macro expands to a string constant that describes the date on which the
 *	preprocessor is being run. The string constant contains eleven characters and
 *	looks like "Feb 12 1996". If the day of the month is less than 10, it is padded
 *	with a space on the left.
 *	If GCC cannot determine the current date, it will emit a warning message (once
 *	per compilation) and __DATE__ will expand to "??? ?? ????".
 */
#include <stdio.h>

int main()
{
	printf("%s: %s\n", __DATE__, __TIME__);
}
