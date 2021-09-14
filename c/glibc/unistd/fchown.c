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
/*	int fchown (int filedes, int owner, int group) [Function]

This is like chown, except that it changes the owner of the open fle with descriptor
fledes.
The return value from fchown is 0 on success and -1 on failure. The following errno
error codes are defned for this function:
EBADF The fledes argument is not a valid fle descriptor.
EINVAL The fledes argument corresponds to a pipe or socket, not an ordinary
fle.
EPERM This process lacks permission to make the requested change. For details
see chmod above.
EROFS The fle resides on a read-only fle system.

 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> /*S_IRUSR*/

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    
	fchown(fd, S_ISUID, S_ISGID);

    close(fd);
    
	return 0;
}
