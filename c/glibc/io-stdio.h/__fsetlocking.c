/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:13 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:55 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:48 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*	int __fsetlocking (FILE *stream, int type) [Function]
 *	The __fsetlocking function can be used to select whether the stream operations will
 *	implicitly acquire the locking object of the stream stream. By default this is done but
 *	it can be disabled and reinstated using this function. There are three values defned
 *	for the type parameter.
 *	FSETLOCKING_INTERNAL
 *	The stream stream will from now on use the default internal locking.
 *	Every stream operation with exception of the _unlocked variants will
 *	implicitly lock the stream.
 *
 *	FSETLOCKING_BYCALLER
 *	After the __fsetlocking function returns the user is responsible for lock
 *	ing the stream. None of the stream operations will implicitly do this
 *	anymore until the state is set back to FSETLOCKING_INTERNAL.
 *	FSETLOCKING_QUERY
 *	__fsetlocking only queries the current locking state of the stream. The
 *	return value will be FSETLOCKING_INTERNAL or FSETLOCKING_BYCALLER
 *	depending on the state.
 *	The return value of __fsetlocking is either FSETLOCKING_INTERNAL or
 *	FSETLOCKING_BYCALLER depending on the state of the stream before the call.
 *	This function and the values for the type parameter are declared in ‘stdio_ext.h’.
 *	This function is especially useful when program code has to be used which is written
 *	without knowledge about the _unlocked functions (or if the programmer was too lazy to
 *	use them).
 */
#include <stdio.h>

int main()
{
	FILE *fp = fopen("rong.out", "w");

	__fsetlocking(fp, 1);

	return 0;
}
