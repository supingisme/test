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
 *	pid_t tcgetpgrp (int filedes) [Function]
 *	This function returns the process group ID of the foreground process group associated
 *	with the terminal open on descriptor fledes.
 *	If there is no foreground process group, the return value is a number greater than 1
 *	that does not match the process group ID of any existing process group. This can
 *	happen if all of the processes in the job that was formerly the foreground job have
 *	terminated, and no other job has yet been moved into the foreground.
 *	In case of an error, a value of -1 is returned. The following errno error conditions
 *	are defned for this function:
 *	EBADF The fledes argument is not a valid fle descriptor.
 *	ENOSYS The system doesn’t support job control.
 *	ENOTTY The terminal fle associated with the fledes argument isn’t the controlling
 *	terminal of the calling process.
 *
 *
 *
 *	int tcsetpgrp (int filedes, pid t pgid) [Function]
 *	This function is used to set a terminal’s foreground process group ID. The argument
 *	fledes is a descriptor which specifes the terminal; pgid specifes the process group.
 *	The calling process must be a member of the same session as pgid and must have the
 *	same controlling terminal.
 *	For terminal access purposes, this function is treated as output. If it is called from a
 *	background process on its controlling terminal, normally all processes in the process
 *	group are sent a SIGTTOU signal. The exception is if the calling process itself is
 *
 *	ignoring or blocking SIGTTOU signals, in which case the operation is performed and
 *	no signal is sent.
 *	If successful, tcsetpgrp returns 0. A return value of -1 indicates an error. The
 *	following errno error conditions are defned for this function:
 *	EBADF The fledes argument is not a valid fle descriptor.
 *	EINVAL The pgid argument is not valid.
 *	ENOSYS The system doesn’t support job control.
 *	ENOTTY The fledes isn’t the controlling terminal of the calling process.
 *	EPERM The pgid isn’t a process group in the same session as the calling process.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	printf("tcgetpgrp = %d\n", pid=tcgetpgrp(fileno(stdin)));

	tcsetpgrp(fileno(stdin), pid);

	return 0;
}
