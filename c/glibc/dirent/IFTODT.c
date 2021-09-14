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
void seekdir (DIR *dirstream, long int pos) [Function]
The seekdir function sets the fle position of the directory stream dirstream to pos.
The value pos must be the result of a previous call to telldir on this particular
stream; closing and reopening the directory can invalidate values returned by telldir.

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
        printf("%3d:%s, %d, %d\n", 
            telldir(dir), diren->d_name, diren->d_fileno, diren->d_type);
    }

    seekdir(dir, 32);
    
    while(diren = readdir(dir))
    {
        printf("%3d:%s, %d, %m\n", 
            telldir(dir), diren->d_name, diren->d_fileno, DTTOIF(diren->d_type));
    }
    
    closedir(dir);
    
    return 0;
}