/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:39 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:23 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:59 CST. */

#include <malloc.h>
#include <string.h>
#include <stdio.h>

static char static1[] = "hello";
static char static2[] = "world";

typedef void *fptr(char *s);

extern void cb(char *s);


int fun(const char *str1, const char *str2)
{
	memcpy(static1, str1, strlen(str1)+1);
	memcpy(static2, str2, strlen(str2)+1);

	printf("%s %s\n", static1, static2);

	fptr fp = cb;
	fp(static1);
}
