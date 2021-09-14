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
/*	char * tempnam (const char *dir, const char *prefix) [Function]
 *	This function generates a unique temporary fle name. If prefx is not a null pointer,
 *	up to fve characters of this string are used as a prefx for the fle name. The return
 *	value is a string newly allocated with malloc, so you should release its storage with
 *	free when it is no longer needed.
 *	Because the string is dynamically allocated this function is reentrant.
 *	The directory prefx for the temporary fle name is determined by testing each of the
 *	following in sequence. The directory must exist and be writable.
 *	• The environment variable TMPDIR, if it is defned. For security reasons this only
 *	happens if the program is not SUID or SGID enabled.
 *	• The dir argument, if it is not a null pointer.
 *	• The value of the P_tmpdir macro.
 *	• The directory ‘/tmp’.
 *	This function is defned for SVID compatibility.
 *	Warning: Between the time the pathname is constructed and the fle is created an
 *	other process might have created a fle with the same name using tempnam, leading to
 *	a possible security hole. The implementation generates names which can hardly be
 *	predicted, but when opening the fle you should use the O_EXCL ﬂag. Using tmpfile
 *	or mkstemp is a safe way to avoid this problem.
 */
#include <stdio.h>
#include <malloc.h>

int main()
{
	char *filename;

	filename = tempnam("/home/RongTao", "123");

	printf("%s\n", filename);

	

	free(filename);
	return 0;
}
