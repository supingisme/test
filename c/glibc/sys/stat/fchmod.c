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
/*
int fchmod (int filedes, int mode) [Function]
This is like chmod, except that it changes the permissions of the currently open fle
given by fledes.
The return value from fchmod is 0 on success and -1 on failure. The following errno
error codes are defned for this function:
EBADF The fledes argument is not a valid fle descriptor.
EINVAL The fledes argument corresponds to a pipe or socket, or something else
that doesn’t really have access permissions.
EPERM This process does not have permission to change the access permissions
of this fle. Only the fle’s owner (as judged by the eﬀective user ID of
the process) or a privileged user can change them.
EROFS The fle resides on a read-only fle system.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	//mkdir("rong.out", 0777);
    
    int fd = open(argv[1], O_RDONLY);
    
	fchmod(fd, 04244);

	return 0;
}
