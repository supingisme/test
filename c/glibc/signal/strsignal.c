/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*
char * strsignal (int signum) [Function]
This function returns a pointer to a statically-allocated string containing a message
describing the signal signum. You should not modify the contents of this string; and,
since it can be rewritten on subsequent calls, you should save a copy of it if you need
to reference it later.
This function is a GNU extension, declared in the header fle ‘string.h’.


 */

#include <signal.h>
#include <stdio.h>
#include <string.h>

int main()
{
	printf("SIGXCPU = %d, %s\n", SIGXCPU, strsignal(SIGXCPU));
	printf("SIGFPE = %d, %s\n", SIGFPE, strsignal(SIGFPE));
	printf("SIGSEGV = %d, %s\n", SIGSEGV, strsignal(SIGSEGV));
	printf("SIGTRAP = %d, %s\n", SIGTRAP, strsignal(SIGTRAP));


	return 0;
}
