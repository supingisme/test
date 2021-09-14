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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/**
 *	17.8.1 Allocating Pseudo-Terminals
 *	This subsection describes functions for allocating a pseudo-terminal, and for making this
 *	pseudo-terminal available for actual use. These functions are declared in the header fle
 *	‘stdlib.h’.
 *
 *	int getpt (void) [Function]
 *	The getpt function returns a new fle descriptor for the next available master pseudo
 *	terminal. The normal return value from getpt is a non-negative integer fle descriptor.
 *	In the case of an error, a value of −1 is returned instead. The following errno
 *	conditions are defned for this function:
 *	ENOENT There are no free master pseudo-terminals available.
 *	This function is a GNU extension.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	getpt();

	perror("getpt");

	return 0;
}
