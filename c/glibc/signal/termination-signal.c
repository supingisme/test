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
int SIGTERM [Macro]
The SIGTERM signal is a generic signal used to cause program termination. Unlike
SIGKILL, this signal can be blocked, handled, and ignored. It is the normal way to
politely ask a program to terminate.
The shell command kill generates SIGTERM by default.
int SIGINT [Macro]
The SIGINT (“program interrupt”) signal is sent when the user types the INTR charac
ter (normally C-c). See Section 17.4.9 [Special Characters], page 446, for information
about terminal driver support for C-c.
int SIGQUIT [Macro]
The SIGQUIT signal is similar to SIGINT, except that it’s controlled by a diﬀerent key—
the QUIT character, usually C-\—and produces a core dump when it terminates the
process, just like a program error signal. You can think of this as a program error
condition “detected” by the user.
See Section 24.2.1 [Program Error Signals], page 604, for information about core
dumps. See Section 17.4.9 [Special Characters], page 446, for information about
terminal driver support.
Certain kinds of cleanups are best omitted in handling SIGQUIT. For example, if the
program creates temporary fles, it should handle the other termination requests by
deleting the temporary fles. But it is better for SIGQUIT not to delete them, so that
the user can examine them in conjunction with the core dump.
 */

#include <signal.h>
#include <stdio.h>

/*sighandler_t SIG_ERR [Macro]
The value of this macro is used as the return value from signal to indicate an error.*/

int main()
{
	printf("SIGTERM = %d\n", SIGTERM);
	printf("SIGINT = %d\n", SIGINT);
	printf("SIGQUIT = %d\n", SIGQUIT);
	printf("SIGKILL = %d\n", SIGKILL);
	printf("SIGHUP = %d\n", SIGHUP);

	return 0;
}
