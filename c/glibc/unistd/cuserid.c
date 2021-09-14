/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:34 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:35 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:07 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:19 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:56 CST. */
/*
 *	char * cuserid (char *string) [Function]
 *	The cuserid function returns a pointer to a string containing a user name associated
 *	with the eﬀective ID of the process. If string is not a null pointer, it should be
 *	an array that can hold at least L_cuserid characters; the string is returned in this
 *	array. Otherwise, a pointer to a string in a static area is returned. This string is
 *	statically allocated and might be overwritten on subsequent calls to this function or
 *	to getlogin.
 *	The use of this function is deprecated since it is marked to be withdrawn in XPG4.2
 *	and has already been removed from newer revisions of POSIX.1.
 */

#include <stdio.h>
#include <unistd.h>


int main()
{
	char username[1024];

	//char 

	printf("cuserid: %s\n", cuserid(NULL));
}
