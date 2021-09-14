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

int SIGCHLD [Macro]
This signal is sent to a parent process whenever one of its child processes terminates
or stops.
The default action for this signal is to ignore it. If you establish a handler for this
signal while there are child processes that have terminated but not reported their
status via wait or waitpid (see Section 26.6 [Process Completion], page 693), whether
your new handler applies to those processes or not depends on the particular operating
system.
int SIGCLD [Macro]
This is an obsolete name for SIGCHLD.
int SIGCONT [Macro]
You can send a SIGCONT signal to a process to make it continue. This signal is
special—it always makes the process continue if it is stopped, before the signal is
delivered. The default behavior is to do nothing else. You cannot block this signal.
You can set a handler, but SIGCONT always makes the process continue regardless.
Most programs have no reason to handle SIGCONT; they simply resume execution
without realizing they were ever stopped. You can use a handler for SIGCONT to make
a program do something special when it is stopped and continued—for example, to
reprint a prompt when it is suspended while waiting for input.
int SIGSTOP [Macro]
The SIGSTOP signal stops the process. It cannot be handled, ignored, or blocked.
int SIGTSTP [Macro]
The SIGTSTP signal is an interactive stop signal. Unlike SIGSTOP, this signal can be
handled and ignored.
Your program should handle this signal if you have a special need to leave fles or
system tables in a secure state when a process is stopped. For example, programs
that turn oﬀ echoing should handle SIGTSTP so they can turn echoing back on before
stopping.
This signal is generated when the user types the SUSP character (normally C-z). For
more information about terminal driver support, see Section 17.4.9 [Special Charac
ters], page 446.
int SIGTTIN [Macro]
A process cannot read from the user’s terminal while it is running as a background
job. When any process in a background job tries to read from the terminal, all of the
processes in the job are sent a SIGTTIN signal. The default action for this signal is
to stop the process. For more information about how this interacts with the terminal
driver, see Section 27.4 [Access to the Controlling Terminal], page 700.
int SIGTTOU [Macro]
This is similar to SIGTTIN, but is generated when a process in a background job
attempts to write to the terminal or set its modes. Again, the default action is to
stop the process. SIGTTOU is only generated for an attempt to write to the terminal
if the TOSTOP output mode is set; see Section 17.4.5 [Output Modes], page 440.

 */

#include <signal.h>
#include <stdio.h>

int main()
{
	printf("SIGCHLD = %d\n", SIGCHLD);
	printf("SIGCLD = %d\n", SIGCLD);
	printf("SIGCONT = %d\n", SIGCONT);
	printf("SIGSTOP = %d\n", SIGSTOP);
	printf("SIGTSTP = %d\n", SIGTSTP);
	printf("SIGTTIN = %d\n", SIGTTIN);
	printf("SIGTTOU = %d\n", SIGTTOU);

	return 0;
}
