/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
 *	int tolower (int c) [Function]
 *	If c is an upper-case letter, tolower returns the corresponding lower-case letter. If c
 *	is not an upper-case letter, c is returned unchanged.
 *	int toupper (int c) [Function]
 *	If c is a lower-case letter, toupper returns the corresponding upper-case letter. Oth
 *	erwise c is returned unchanged.
 *	int toascii (int c) [Function]
 *	This function converts c to a 7-bit unsigned char value that fts into the US/UK
 *	ASCII character set, by clearing the high-order bits. This function is a BSD extension
 *	and is also an SVID extension.
 *	int _tolower (int c) [Function]
 *	This is identical to tolower, and is provided for compatibility with the SVID. See
 *	Section 1.2.4 [SVID (The System V Interface Description)], page 3.
 *	int _toupper (int c) [Function]
 *	This is identical to toupper, and is provided for compatibility with the SVID.
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	printf("%c\n", argv[1][0]);
	char ch = argv[1][0];

	printf("tolower: %c\n", tolower(ch));
	printf("toupper: %c\n", toupper(ch));
	printf("toascii: %c\n", toascii(ch));
	printf("_tolower: %c\n", _tolower(ch));
	printf("_toupper: %c\n", _toupper(ch));


	return 0;
}
