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
 *	pid_t setsid (void) [Function]
 *	The setsid function creates a new session. The calling process becomes the session
 *	leader, and is put in a new process group whose process group ID is the same as the
 *	process ID of that process. There are initially no other processes in the new process
 *	group, and no other process groups in the new session.
 *	This function also makes the calling process have no controlling terminal.
 *	The setsid function returns the new process group ID of the calling process if suc
 *	cessful. A return value of -1 indicates an error. The following errno error conditions
 *	are defned for this function:
 *	EPERM The calling process is already a process group leader, or there is already
 *	another process group around that has the same process group ID.
 *
 *	pid_t getsid (pid t pid) [Function]
 *	The getsid function returns the process group ID of the session leader of the specifed
 *	process. If a pid is 0, the process group ID of the session leader of the current process
 *	is returned.
 *	In case of error -1 is returned and errno is set. The following errno error conditions
 *	are defned for this function:
 *	ESRCH There is no process with the given process ID pid.
 *	EPERM The calling process and the process specifed by pid are in diﬀerent ses
 *	sions, and the implementation doesn’t allow to access the process group
 *	ID of the session leader of the process with ID pid from the calling process.
 *
 */
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	printf("setsid = %d\n", setsid());
	printf("getsid = %d\n", getsid(getpid()));
	//perror("setsid");

	return 0;
}
