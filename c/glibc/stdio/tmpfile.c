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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 10:11:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*	FILE * tmpfile (void) [Function]
 *	This function creates a temporary binary fle for update mode, as if by calling fopen
 *	with mode "wb+". The fle is deleted automatically when it is closed or when the
 *	program terminates. (On some other ISO C systems the fle may fail to be deleted if
 *	the program terminates abnormally).
 *	This function is reentrant.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
	//mkdir("mkdir.out", 00);

	//if(0 != access("mkadfdir.out", F_OK))
	//{
	//	perror("access");
	//	printf("%s\n", strerror(errno));
	//}
	//
	
	FILE *fp = tmpfile();

	fprintf(fp, "RongTaoasdfadfadsfasdf\n");

	//while(1);
	//fclose(fp);

	return 0;
}
