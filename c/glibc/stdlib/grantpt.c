/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/**
 *	int grantpt (int filedes) [Function]
 *	The grantpt function changes the ownership and access permission of the slave
 *	pseudo-terminal device corresponding to the master pseudo-terminal device associ
 *	ated with the fle descriptor fledes. The owner is set from the real user ID of the
 *	calling process (see Section 29.2 [The Persona of a Process], page 727), and the group
 *	is set to a special group (typically tty) or from the real group ID of the calling process.
 *	The access permission is set such that the fle is both readable and writable by the
 *	owner and only writable by the group.
 *	On some systems this function is implemented by invoking a special setuid root
 *	program (see Section 29.4 [How an Application Can Change Persona], page 728). As
 *	a consequence, installing a signal handler for the SIGCHLD signal (see Section 24.2.5
 *	[Job Control Signals], page 609) may interfere with a call to grantpt.
 *	The normal return value from grantpt is 0; a value of −1 is returned in case of failure.
 *	The following errno error conditions are defned for this function:
 *	EBADF The fledes argument is not a valid fle descriptor.
 *	EINVAL The fledes argument is not associated with a master pseudo-terminal
 *	device.
 *	EACCES The slave pseudo-terminal device corresponding to the master associated
 *	with fledes could not be accessed.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main()
{
	int fd = open("/dev/ptmx", 0x1111);
	grantpt(fileno(stdout));

	printf("%s\n", strerror(errno));
	perror("grantpt");

	return 0;
}
