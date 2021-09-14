/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:42 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:40 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:52:45 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>

//#define _FORMAT(fun, a, b) __attribute__((__format__ (printf, a, b)))

char *Strjoint(char *dst, const char *fmt, ...) __attribute__((__format__ (printf, 2, 3)));

char *Strjoint(char *dst, const char *fmt, ...)
{
	if(dst == NULL || fmt == NULL)
		return NULL;

	va_list args;
	va_start(args, fmt);

	vsprintf(dst, fmt, args);

	va_end(args);

	return (char*)dst;
}


int main(int argc, char *argv[])
{
	char cmd[256];
	memset(cmd, 0, 256);

	Strjoint(cmd, "rongtao: %d", 123);

	printf("cmd: %s\n", cmd);

	return 0;
}
