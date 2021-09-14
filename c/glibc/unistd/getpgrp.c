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
 *	pid_t getpgrp (void) [POSIX.1 Function]
 *	The POSIX.1 defnition of getpgrp returns the process group ID of the calling process.
 *	pid_t getpgrp (pid t pid) [BSD Function]
 *	The BSD defnition of getpgrp returns the process group ID of the process pid. You
 *	can supply a value of 0 for the pid argument to get information about the calling
 *	process.
 *	int getpgid (pid t pid) [System V Function]
 *	getpgid is the same as the BSD function getpgrp. It returns the process group ID of
 *	the process pid. You can supply a value of 0 for the pid argument to get information
 *	about the calling process.
 *	In case of error -1 is returned and errno is set. The following errno error conditions
 *	are defned for this function:
 *	ESRCH There is no process with the given process ID pid. The calling process
 *	and the process specifed by pid are in diﬀerent sessions, and the imple
 *	mentation doesn’t allow to access the process group ID of the process
 *	with ID pid from the calling process.
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("getpgrp = %d, %d\n", getpgrp(), getpgrp());

	return 0;
}
