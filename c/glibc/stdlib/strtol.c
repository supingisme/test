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
 *	long int strtol (const char *restrict string, char **restrict tailptr,
 *	int base)
 *
 *	unsigned long int strtoul (const char *retrict string, char
 *	**restrict tailptr, int base)
 *
 *	long long int strtoll (const char *restrict string, char **restrict
 *	tailptr, int base)
 *
 *	long long int strtoq (const char *restrict string, char **restrict
 *	tailptr, int base)
 *
 *	unsigned long long int strtoull (const char *restrict string, char
 *	**restrict tailptr, int base)
 *
 *	unsigned long long int strtouq (const char *restrict string, char
 *	**restrict tailptr, int base)
 *
 *	q
 *	intmax_t strtoimax (const char *restrict string, char **restrict
 *	tailptr, int base)
 *
 *	uintmax_t strtoumax (const char *restrict string, char **restrict
 *	tailptr, int base)
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *ret;

	long int li = strtol("123abc", &ret, 10);


	printf("%d, %s\n", li, ret);

	return 0;
}
