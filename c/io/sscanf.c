/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:37 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:21 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:57 CST. */
/**
 *	sscanf
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a, b;

	char str[256];

	if(argc == 3)
	{
		sscanf(argv[1], "%d.%d\n", &a, &b);
		printf("%d, %d\n", a, b);	

		sscanf(argv[2], "%s\n%d\n", str, &b);
		printf("%s, %d\n", str, b);
	}
}
