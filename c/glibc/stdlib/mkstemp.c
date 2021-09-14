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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:48:14 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*	int mkstemp (char *template) [Function]
 *	The mkstemp function generates a unique fle name just as mktemp does, but it
 *	also opens the fle for you with open (see Section 13.1 [Opening and Closing Files],
 *	page 296). If successful, it modifes template in place and returns a fle descriptor for
 *	that fle open for reading and writing. If mkstemp cannot create a uniquely-named
 *	fle, it returns -1. If template does not end with ‘XXXXXX’, mkstemp returns -1 and
 *	does not modify template.
 *	The fle is opened using mode 0600. If the fle is meant to be used by other users this
 *	mode must be changed explicitly.
 *	
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>

int mkstemp (char *template);


int main()
{
					 ///home/rongtao/test/c/glibc/stdlib
	//char file[256] = {"/home/rongtao/test/c/glibc/stdlib/"};;
	char file[256] = {"XXXX.out"};

	printf("file: %s\n", file);
	int ret = mkstemp(file);

	printf("file: %s, ret = %d\n", file, ret);



	return 0;
}
