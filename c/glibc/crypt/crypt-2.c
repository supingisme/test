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
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

/* -lcrypt */	
int
main(void)
{
	/*	pass				result			pssswd		salt
	 *	rtfxImas03U32		rtfxImas03U32	"rong "		"rt"
	 */

	/* Hashed form of "GNU libc manual". */
	const char *const pass = "rtfxImas03U32";
	char *result;
	int ok;
	/* Read in the user’s password and encrypt it,
	 * passing the expected password in as the salt. */
	result = crypt(getpass("Password:"), "rt");
	puts(result);
	
	/* Test the result. */
	ok = strcmp (result, pass) == 0;
	puts(ok ? "Access granted." : "Access denied.");
	return ok ? 0 : 1;
}
