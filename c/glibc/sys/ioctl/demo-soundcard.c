/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:26 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:31 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:02 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:15 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
 *  测试物理连接是否正常
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/soundcard.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

#define BASE_VALUE 257

int main(int argc, char *argv[])
{
    int mixer_fd = 0;
    
    char *names[SOUND_MIXER_NRDEVICES] = SOUND_DEVICE_LABELS;
    
    int value, i;
    
    printf("usage: %s dev_no.[0..24] value[0..100]\n\n", argv[0]);
    
    printf("eg. %s 0 100 \n", argv[0]);
    printf("will change the volume to MAX volume. \n");
    printf("The dev_no. are as below\n");
    
    for(i=0;i<SOUND_MIXER_NRDEVICES; i++)
    {
        if(i%3==0)
            printf("\n");
        printf("%s:%d\t\t",names[i], i);
    }
    
    printf("\n\n");
    
    if(argc<3) exit(1);
    
    if((mixer_fd = open("/dev/mixer", O_RDWR)))
    {
        printf("Mix opened succ, working ...\n");
        
        value = BASE_VALUE*atoi(argv[2]);
        
        if(ioctl(mixer_fd, MIXER_WRITE(atoi(argv[1])), &value) == 0)
        {
            printf("successfully\n");
        }
        else
        {
            printf("not successfully\n");
        }
        printf("done\n");
    }
    else
    {
        printf("can't open /dev/mixer, error..\n");
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}