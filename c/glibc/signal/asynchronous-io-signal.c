/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:22 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:29 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:00 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:13 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
/*

int SIGIO [Macro]
This signal is sent when a fle descriptor is ready to perform input or output.
On most operating systems, terminals and sockets are the only kinds of fles that can
generate SIGIO; other kinds, including ordinary fles, never generate SIGIO even if
you ask them to.
In the GNU system SIGIO will always be generated properly if you successfully set
asynchronous mode with fcntl.
int SIGURG [Macro]
This signal is sent when “urgent” or out-of-band data arrives on a socket. See
Section 16.9.8 [Out-of-Band Data], page 422.
int SIGPOLL [Macro]
This is a System V signal name, more or less similar to SIGIO. It is defned only for
compatibility.


 */

#include <signal.h>
#include <stdio.h>

int main()
{
	printf("SIGIO = %d\n", SIGIO);
	printf("SIGURG = %d\n", SIGURG);
	printf("SIGPOLL = %d\n", SIGPOLL);

	return 0;
}
