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
/*
 *	Portability Note: On System V derived systems, the fle returned by the ptsname and
 *	ptsname_r functions may be STREAMS-based, and therefore require additional processing
 *	after opening before it actually behaves as a pseudo terminal.
 *	Typical usage of these functions is illustrated by the following example:
 */

#include <stdio.h>
#include <stdlib.h>
#include <pty.h>
#include <fcntl.h>

int open_pty_pair (int *amaster, int *aslave)
{
	int master, slave;
	char *name;
	master = getpt ();
	if (master < 0)
		return 0;
	if (grantpt (master) < 0 || unlockpt (master) < 0)
		goto close_master;
	name = ptsname (master);
	if (name == NULL)
		goto close_master;
	slave = open (name, O_RDWR);
	if (slave == -1)
		goto close_master;
	if (isastream (slave))
	{
		if (ioctl (slave, I_PUSH, "ptem") < 0
				|| ioctl (slave, I_PUSH, "ldterm") < 0)
			goto close_slave;
	}
	*amaster = master;
	*aslave = slave;
	return 1;
close_slave:
	close (slave);
close_master:
	close (master);
	return 0;
}

int main()
{
	return 0;
}
