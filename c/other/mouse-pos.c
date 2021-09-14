/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:38 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:38 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:22 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:58 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <sys/time.h>
#include <fcntl.h>

int main()
{
    int fd, retval;
    char buf[6];
    fd_set readfds;
    struct timeval tv;
    
    if((fd = open("/dev/input/mice", O_RDONLY))<0)
    {
        printf("error\n");
        exit(1);
    }
    else 
    {
        printf("succ\n");
    }
    
    while(1)
    {
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);
        
        retval = select(fd+1, &readfds, NULL, NULL, &tv);
        
        if(retval==0)
        {
            printf("timeout\n");
        }
        if(FD_ISSET(fd, &readfds))
        {
            if(read(fd, buf, 6))
            {
                continue;
            }
            printf("%d: (%d, %d, %d)\n", buf[0], buf[1], buf[2], buf[3]);
        }
    }
    close(fd);
    
    return 0;
    
}
