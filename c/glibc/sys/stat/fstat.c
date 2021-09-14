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
/*	14.9.2 Reading the Attributes of a File

int fstat (int filedes, struct stat *buf) [Function]
The fstat function is like stat, except that it takes an open fle descriptor as an
argument instead of a fle name. See Chapter 13 [Low-Level Input/Output], page 296.
Like stat, fstat returns 0 on success and -1 on failure. The following errno error
conditions are defned for fstat:
EBADF The fledes argument is not a valid fle descriptor.
When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is in fact
fstat64 since the LFS interface transparently replaces the normal implementation.
int fstat64 (int filedes, struct stat64 *buf) [Function]
This function is similar to fstat but is able to work on large fles on 32-bit platforms.
For large fles the fle descriptor fledes should be obtained by open64 or creat64.
The buf pointer points to a variable of type struct stat64 which is able to represent
the larger values.
When the sources are compiled with _FILE_OFFSET_BITS == 64 this function is avail
able under the name fstat and so transparently replaces the interface for small fles
on 32-bit machines.

 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	struct stat buf;
    
    int fp = open("/home/RongTao/", O_RDONLY);
	fstat(fp, &buf);	

	printf("mode:%d\n", buf.st_mode);
	printf("ino:%d\n", buf.st_ino);

	return 0;
}
