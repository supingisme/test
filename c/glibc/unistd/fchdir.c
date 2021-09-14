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
int fchdir (int filedes) [Function]
This function is used to set the process’s working directory to directory associated
with the fle descriptor fledes.
The normal, successful return value from fchdir is 0. A value of -1 is returned to
indicate an error. The following errno error conditions are defned for this function:

EACCES Read permission is denied for the directory named by dirname.
EBADF The fledes argument is not a valid fle descriptor.
ENOTDIR The fle descriptor fledes is not associated with a directory.
EINTR The function call was interrupt by a signal.
EIO An I/O error occurred.


*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("/home/RongTao", O_RDONLY);
    
    fchdir(fd);
    
    printf("%s\n", (char *)getcwd(NULL, 100));
    
    close(fd);
    
    return 0;
}