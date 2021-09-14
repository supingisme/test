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
/*
 *	char * getenv (const char *name) [Function]
 *	This function returns a string that is the value of the environment variable name. You
 *	must not modify this string. In some non-Unix systems not using the GNU library,
 *	it might be overwritten by subsequent calls to getenv (but not by any other library
 *	function). If the environment variable name is not defned, the value is a null pointer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
	char *env = getenv("OLDPWD");

	printf("env = %s\n", env);
	free(env);
	char *listenq = getenv("LISTENQ");
	printf("listenq = %s\n", listenq);

	//free(env);

	return 0;
}
