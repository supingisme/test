/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:36 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:37 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:08 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:20 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/*
 *	29.12.3 Logging In and Out
 *	These functions, derived from BSD, are available in the separate ‘libutil’ library, and
 *	declared in ‘utmp.h’.
 *	Note that the ut_user member of struct utmp is called ut_name in BSD. Therefore,
 *	ut_name is defned as an alias for ut_user in ‘utmp.h’.
 *	int login_tty (int filedes) [Function]
 *	This function makes fledes the controlling terminal of the current process, redirects
 *	standard input, standard output and standard error output to this terminal, and
 *	closes fledes.
 *	This function returns 0 on successful completion, and -1 on error.
 */

#include <stdio.h>
#include <utmp.h>
#include <errno.h>

//$ gcc login_tty.c -lutil 

int main()
{
	FILE *fp = fopen("login_tty.c", "r");

	int ret = login_tty(fileno(fp));

	printf("ret = %d\n", ret);
	perror("login_tty.");

	return 0;
}
