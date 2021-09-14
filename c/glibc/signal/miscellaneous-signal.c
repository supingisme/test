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

24.2.7 Miscellaneous Signals
These signals are used for various other purposes. In general, they will not aﬀect your
program unless it explicitly uses them for something.
int SIGUSR1 [Macro]
int SIGUSR2 [Macro]
The SIGUSR1 and SIGUSR2 signals are set aside for you to use any way you want.
They’re useful for simple interprocess communication, if you write a signal handler
for them in the program that receives the signal.
There is an example showing the use of SIGUSR1 and SIGUSR2 in Section 24.6.2 [Sig
naling Another Process], page 630.
The default action is to terminate the process.
int SIGWINCH [Macro]
Window size change. This is generated on some systems (including GNU) when the
terminal driver’s record of the number of rows and columns on the screen is changed.
The default action is to ignore it.
If a program does full-screen display, it should handle SIGWINCH. When the signal
arrives, it should fetch the new screen size and reformat its display accordingly.

int SIGINFO [Macro]
Information request. In 4.4 BSD and the GNU system, this signal is sent to all the
processes in the foreground process group of the controlling terminal when the user
types the STATUS character in canonical mode; see Section 17.4.9.2 [Characters that
Cause Signals], page 448.
If the process is the leader of the process group, the default action is to print some
status information about the system and what the process is doing. Otherwise the
default is to do nothing.
 */

#include <signal.h>
#include <stdio.h>

int main()
{
	printf("SIGUSR1 = %d\n", SIGUSR1);
	printf("SIGUSR2 = %d\n", SIGUSR2);
	printf("SIGWINCH = %d\n", SIGWINCH);
	//printf("SIGINFO = %d\n", SIGINFO);

	return 0;
}
