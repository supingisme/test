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
 *	3.2.5.2 Advantages of alloca
 *	Here are the reasons why alloca may be preferable to malloc:
 *	• Using alloca wastes very little space and is very fast. (It is open-coded by the GNU
 *	C compiler.)
 */

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //alloca(siez_t)


int
open2 (char *str1, char *str2, int flags, int mode)
{
	char *name = (char *) alloca (strlen (str1) + strlen (str2) + 1);
	stpcpy (stpcpy (name, str1), str2);
	return open (name, flags, mode);
}

int
open3 (char *str1, char *str2, int flags, int mode)
{
	char *name = (char *) malloc (strlen (str1) + strlen (str2) + 1);
	int desc;
	if (name == 0)
		//fatal ("virtual memory exceeded");
		perror("virtual memory exceeded.");
	stpcpy (stpcpy (name, str1), str2);
	desc = open (name, flags, mode);
	free (name);
	return desc;
}

int main()
{
	char *str = alloca(256);


	return 0;
}
