/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 06月 17日 星期一 08:09:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 17日 星期一 08:09:11 CST. */

#include <fcntl.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *	CD-ROM: 只读光盘。飞利浦和SONY开发和发行。
 */

int main (int argc, char* argv[])
{
	/* Open a file descriptor to the device specified on the command line. */
	int fd = open (argv[1], O_RDONLY);
	/* Eject the CD-ROM. */
	ioctl (fd, CDROMEJECT);
	/* Close the file descriptor. */
	close (fd);
	return 0;
}
