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
 *	long int atol (const char *string) [Function]
 *	This function is similar to the strtol function with a base argument of 10, except
 *	that it need not detect overﬂow errors. The atol function is provided mostly for
 *	compatibility with existing code; using strtol is more robust.
 *	int atoi (const char *string) [Function]
 *	This function is like atol, except that it returns an int. The atoi function is also
 *	considered obsolete; use strtol instead.
 *	long long int atoll (const char *string) [Function]
 *	This function is similar to atol, except it returns a long long int.
 *	The atoll function was introduced in ISO C99. It too is obsolete (despite having
 *	just been added); use strtoll instead.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Usage: ./%s [digit-string]\n", argv[0]);
		exit(1);
	}
	printf("%d\n", atoi(argv[1]));
	printf("%d\n", atol(argv[1]));
	printf("%d\n", atoll(argv[1]));


	return 0;
}
