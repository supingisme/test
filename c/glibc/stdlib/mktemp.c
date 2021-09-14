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
/*	char * mktemp (char *template) [Function]
 *	The mktemp function generates a unique fle name by modifying template as described
 *	above. If successful, it returns template as modifed. If mktemp cannot fnd a unique
 *	fle name, it makes template an empty string and returns that. If template does not
 *	end with ‘XXXXXX’, mktemp returns a null pointer.
 *	Warning: Between the time the pathname is constructed and the fle is created an
 *	other process might have created a fle with the same name using mktemp, leading to
 *	a possible security hole. The implementation generates names which can hardly be
 *	predicted, but when opening the fle you should use the O_EXCL ﬂag. Using mkstemp
 *	is a safe way to avoid this problem.
 *
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *template = malloc(256);

	sprintf(template, "temp");
	
	template = tempnam("/home/RongTao/", "123");

	printf("\033[1;31;44m%s\033[m\n", mktemp(template));

	return 0;
}
