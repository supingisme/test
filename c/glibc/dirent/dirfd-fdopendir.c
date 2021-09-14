/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:10 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:23 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*
DIR * fdopendir (int fd) [Function]
The fdopendir function works just like opendir but instead of taking a fle name
and opening a fle descriptor for the directory the caller is required to provide a
fle descriptor. This fle descriptor is then used in subsequent uses of the returned
directory stream object.
The caller must make sure the fle descriptor is associated with a directory and it
allows reading.
If the fdopendir call returns successfully the fle descriptor is now under the control
of the system. It can be used in the same way the descriptor implicitly created by
opendir can be used but the program must not close the descriptor.
In case the function is unsuccessful it returns a null pointer and the fle descriptor
remains to be usable by the program. The following errno error conditions are defned
for this function:
EBADF The fle descriptor is not valid.
ENOTDIR The fle descriptor is not associated with a directory.
EINVAL The descriptor does not allow reading the directory content.
ENOMEM Not enough memory available.
In some situations it can be desirable to get hold of the fle descriptor which is created
by the opendir call. For instance, to switch the current working directory to the directory
just read the fchdir function could be used. Historically the DIR type was exposed and
programs could access the felds. This does not happen in the GNU C library. Instead a
separate function is provided to allow access.
int dirfd (DIR *dirstream) [Function]
The function dirfd returns the fle descriptor associated with the directory stream
dirstream. This descriptor can be used until the directory is closed with closedir.
If the directory stream implementation is not using fle descriptors the return value
is -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    DIR *dir = opendir("/home/RongTao/test");
    struct dirent *diren;
    
    while(diren = readdir(dir))
    {
        printf("%s, %d, %d\n", diren->d_name, diren->d_fileno, diren->d_type);
    }
    
    closedir(dir);
    
    int fd = open("/home/RongTao/test", O_RDONLY);
    
    dir = fdopendir(fd);
    
    while(diren = readdir(dir))
    {
        printf("%s, %d, %d\n", diren->d_name, diren->d_fileno, diren->d_type);
    }
    
    closedir(dir);
    
    return 0;
}