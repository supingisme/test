/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 10月 09日 星期三 08:20:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define a1

#define fun() fun()
int fun(){}

#include <libgen.h>
#define log_vcm_err(fmt, ...) \
	vfprintf(stdout, fmt, __VA_ARGS__)
#define log_vcm_succ(fmt, ...)\
	vfprintf(stdout, "\033[1;32m[success] \033[0m"fmt, __VA_ARGS__)

#define _m_1
#define _m_2

#if defined(_m_1) \
	|| defined(_m_2)
 #pragma message("define 1 2 ")
#endif

int main()
{
#ifdef fun
	printf("fun\n");
#endif

	log_vcm_err("adsfadfadf%s\n","hello");
	log_vcm_succ("adsfadfadf\n");

#ifdef OS_LINUX
	printf("OS_LINUX");
#endif

	return 0;
}
