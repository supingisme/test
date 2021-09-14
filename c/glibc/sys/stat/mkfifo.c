/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:30 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*	int mkfifo (const char *filename, mode t mode) [Function]
 *	The mkfifo function makes a FIFO special fle with name flename. The mode argu
 *	ment is used to set the fle’s permissions; see Section 14.9.7 [Assigning File Permis
 *	sions], page 372.
 *	The normal, successful return value from mkfifo is 0. In the case of an error, -1
 *	is returned. In addition to the usual fle name errors (see Section 11.2.3 [File Name
 *	Errors], page 224), the following errno error conditions are defned for this function:
 *	EEXIST The named fle already exists.
 *	ENOSPC The directory or fle system cannot be extended.
 *	EROFS The directory that would contain the fle resides on a read-only fle system.
 *
 *
 *	15.3 FIFO Special Files
 *	A FIFO special fle is similar to a pipe, except that it is created in a diﬀerent way. Instead
 *	of being an anonymous communications channel, a FIFO special fle is entered into the fle
 *	system by calling mkfifo.
 *	Once you have created a FIFO special fle in this way, any process can open it for reading
 *	or writing, in the same way as an ordinary fle. However, it has to be open at both ends
 *	simultaneously before you can proceed to do any input or output operations on it. Opening
 *	a FIFO for reading normally blocks until some other process opens the same FIFO for
 *	writing, and vice versa.
 *	The mkfifo function is declared in the header fle ‘sys/stat.h’.
 *
 */
#include <sys/stat.h>
#include <sys/types.h>

int mkfifo (const char *filename, mode_t mode);

int main()
{
	//有名管道
	int fd = mkfifo("mkfifotmp", 1);

	return 0;
}
