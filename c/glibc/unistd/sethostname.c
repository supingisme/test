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
 *	int sethostname (const char *name, size t length) [Function]
 *	The sethostname function sets the host name of the system that calls it to name, a
 *	string with length length. Only privileged processes are permitted to do this.
 *	Usually sethostname gets called just once, at system boot time. Often, the program
 *	that calls it sets it to the value it fnds in the fle /etc/hostname.
 *	Be sure to set the host name to the full host name, not just the DNS hostname (see
 *	above).
 *	The return value is 0 on success and -1 on failure. The following errno error condition
 *	is defned for this function:
 *	EPERM This process cannot set the host name because it is not privileged.
 */

#include <stdio.h>
#include <unistd.h>

int main()
{
	//int sethostname (const char *name, size t length);
	sethostname("localhost", 10);

	return 0;
}
