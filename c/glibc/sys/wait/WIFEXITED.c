/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/*
 *	26.7 Process Completion Status
 *	If the exit status value (see Section 25.6 [Program Termination], page 684) of the child
 *	process is zero, then the status value reported by waitpid or wait is also zero. You can
 *	test for other kinds of information encoded in the returned status value using the following
 *	macros. These macros are defned in the header fle ‘sys/wait.h’.
 *
 *	int WIFEXITED (int status) [Macro]
 *	This macro returns a nonzero value if the child process terminated normally with
 *	exit or _exit.
 *	int WEXITSTATUS (int status) [Macro]
 *	If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit
 *	status value from the child process. See Section 25.6.2 [Exit Status], page 684.
 *	int WIFSIGNALED (int status) [Macro]
 *	This macro returns a nonzero value if the child process terminated because it received
 *	a signal that was not handled. See Chapter 24 [Signal Handling], page 602.
 *	int WTERMSIG (int status) [Macro]
 *	If WIFSIGNALED is true of status, this macro returns the signal number of the signal
 *	that terminated the child process.
 *	int WCOREDUMP (int status) [Macro]
 *	This macro returns a nonzero value if the child process terminated and produced a
 *	core dump.
 *	int WIFSTOPPED (int status) [Macro]
 *	This macro returns a nonzero value if the child process is stopped.
 *	int WSTOPSIG (int status) [Macro]
 *	If WIFSTOPPED is true of status, this macro returns the signal number of the signal
 *	that caused the child process to stop.
 */

#include <sys/wait.h>

//int WIFEXITED (int status);
//int WEXITSTATUS (int status);
//int WIFSIGNALED (int status);
//int WTERMSIG (int status);
//int WCOREDUMP (int status);
//int WIFSTOPPED (int status);
//int WSTOPSIG (int status)


