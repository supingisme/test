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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/sockios.h>


#define LINKTEST_GLINK  0x0000000a

struct linktest_value{
    unsigned int cmd;
    unsigned int data;
};

static void usage(char *pname)
{
    fprintf(stderr, "usage: %s <device>\n", pname);
    exit(0);
}

static int linktest(const char *devname)
{
    struct ifreq ifr;
    struct linktest_value edata;
    
    int fd;
    
    /*setup our control structures*/
    memset(&ifr, 0, sizeof(ifr));
    
    strcpy(ifr.ifr_name, devname);
    
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(fd < 0)  return -ECOMM;
    
    errno = 0;
    edata.cmd = LINKTEST_GLINK;
    ifr.ifr_data = (caddr_t )&edata;
    
    if(!ioctl(fd, SIOCETHTOOL, &ifr))
    {
        if(edata.data)
        {
            fprintf(stdout, "link detected on %s\n", devname);
            return 0;
        }
        else
        {
            errno = ENONET;
        }
    }
    perror("linktest");
    return errno;
}

int main(int argc ,char*argv[])
{
    if(argc != 2)
    {
        usage(argv[0]);
    }
    return linktest(argv[1]);
}

























