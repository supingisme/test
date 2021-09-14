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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	6.26 Case Ranges
 *	You can specify a range of consecutive values in a single case label, like this:
 *	case low ... high:
 *	This has the same eﬀect as the proper number of individual case labels, one for each integer
 *	value from low to high, inclusive.
 *	This feature is especially useful for ranges of ASCII character codes:
 *	case ’A’ ... ’Z’:
 *	Be careful: Write spaces around the ..., for otherwise it may be parsed wrong when you
 *	use it with integer values. For example, write this:
 *	case 1 ... 5:
 *	rather than this:
 *	case 1...5:
 */

#include <stdio.h>

int main(int argc, char *argv[] )
{
	char ch = argv[1][0];

	switch(ch)
	{
		case 'a'...'z':
			printf("a-z\n");
			break;
		case '0'...'9':
			printf("0-9\n");
			break;
		default:
			break;
	}
}
