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
/*	char * tmpnam (char *result) [Function]
 *	This function constructs and returns a valid fle name that does not refer to any
 *	existing fle. If the result argument is a null pointer, the return value is a pointer to
 *	an internal static string, which might be modifed by subsequent calls and therefore
 *	makes this function non-reentrant. Otherwise, the result argument should be a pointer
 *	to an array of at least L_tmpnam characters, and the result is written into that array.
 *	It is possible for tmpnam to fail if you call it too many times without removing
 *	previously-created fles. This is because the limited length of the temporary fle names
 *	gives room for only a fnite number of diﬀerent names. If tmpnam fails it returns a
 *	null pointer.
 *	Warning: Between the time the pathname is constructed and the fle is created an
 *	other process might have created a fle with the same name using tmpnam, leading to
 *	a possible security hole. The implementation generates names which can hardly be
 *	predicted, but when opening the fle you should use the O_EXCL ﬂag. Using tmpfile
 *	or mkstemp is a safe way to avoid this problem.
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	char *filename = malloc(sizeof(256));

	printf("%s\n", tmpnam(filename));

	printf("%s\n", tmpnam(NULL));

	printf("%s\n", tmpnam_r(NULL));

	return 0;
}
