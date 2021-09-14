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
 *  检测接口的inet_addr, netmask, broad_addr
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

static void usage()
{
    printf("usage: ipconfig interface\n");
    exit(1);
}


int main(int argc, char *argv[])
{
    struct sockaddr_in *addr;
    struct ifreq ifr;
    char *name, *address;
    int sockfd;
    
    if(argc < 2)
    {
        usage();
    }
    else 
    {   
        name = argv[1];
    }
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    strncpy(ifr.ifr_name, name, strlen(name)+1);
    
    if(ioctl(sockfd, SIOCGIFADDR, &ifr) < 0)
    {
        perror("ioctl error");
        exit(0);
    }
    addr = (struct sockaddr_in*)&(ifr.ifr_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet addr: %s\n", address);

    if(ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1)
    {
        perror("ioctl error");
        exit(0);
    }
    addr = (struct sockaddr_in*)&(ifr.ifr_broadaddr);
    address = inet_ntoa(addr->sin_addr);
    printf("broad addr: %s\n", address);
    
    if(ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1)
    {
        perror("ioctl error");
        exit(0);
    }
    addr = (struct sockaddr_in*)&(ifr.ifr_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet mask: %s\n", address);
    
}