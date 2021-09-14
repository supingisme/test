/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 10:11:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	char * ctermid (char *string) [Function]
 *	The ctermid function returns a string containing the fle name of the controlling
 *	terminal for the current process. If string is not a null pointer, it should be an
 *	array that can hold at least L_ctermid characters; the string is returned in this
 *	array. Otherwise, a pointer to a string in a static area is returned, which might get
 *	overwritten on subsequent calls to this function.
 *	An empty string is returned if the fle name cannot be determined for any reason.
 *	Even if a fle name is returned, access to the fle it represents is not guaranteed.
 *
 *
 *	int L_ctermid [Macro]
 *	The value of this macro is an integer constant expression that represents the size of
 *	a string large enough to hold the fle name returned by ctermid.
 */

#include <stdio.h>
//char * ctermid (char *string)

int main()
{
	char str[256];

	printf("%s\n", ctermid(str));

	printf("str = %s\n", str);

	return 0;
}
