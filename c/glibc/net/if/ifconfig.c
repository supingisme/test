/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:16 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:26 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:56 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:10 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:55 CST. */
/*
 *	简单实现ifconfig功能
 */

#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>



int demo1(int argc, char *argv[])
{
	int inet_sock;
	struct ifreq ifr;

	inet_sock = socket(AF_INET, SOCK_DGRAM, 0);

	strcpy(ifr.ifr_name, argv[1]);

	if(ioctl(inet_sock, SIOCGIFHWADDR, &ifr) < 0)
	{
		perror("ioctl");
	}
	printf("%s\n", inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr));

    printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                (unsigned char)ifr.ifr_hwaddr.sa_data[0], 
                (unsigned char)ifr.ifr_hwaddr.sa_data[1], 
                (unsigned char)ifr.ifr_hwaddr.sa_data[2], 
                (unsigned char)ifr.ifr_hwaddr.sa_data[3], 
                (unsigned char)ifr.ifr_hwaddr.sa_data[4], 
                (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
    
	return 0;
}


#define MAX_INTERFACE 16

void port_status(unsigned int flags);

int set_if_flags(char *pif_name, int sock, int status, int set)
{
    struct ifreq ifr;
    
    int ret = 0;
    
    strncpy(ifr.ifr_name, pif_name, strlen(pif_name)+1);
    
    ret = ioctl(sock, SIOCGIFFLAGS, &ifr);
    
    if(ret) return -1;
    
    if(set)
    {
        ifr.ifr_flags |= status;
    }
    else
    {
        ifr.ifr_flags &= ~status;
    }
    
    ret = ioctl(sock, SIOCGIFFLAGS, &ifr);
    
    if(ret) return -1;
    
    return 0;
}

int get_if_info(int fd)
{
    struct ifreq buf[MAX_INTERFACE];
    struct ifconf ifc;
    int ret =0;
    int if_num = 0;
    
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;
    
    ret = ioctl(fd, SIOCGIFCONF, (char*)&ifc);
    
    if(ret)
    {
        printf("get if config info failed\n");
        return -1;
    }
    
    if_num = ifc.ifc_len/sizeof(struct ifreq);
    printf("interface num is interface = %d\n", if_num);
    
    while(if_num-- >0)
    {
        printf("net device: %s\n", buf[if_num].ifr_name);
        ret = ioctl(fd, SIOCGIFFLAGS, (char*)&buf[if_num]);
        if(ret) continue;
        
        port_status(buf[if_num].ifr_flags);
        
        ret = ioctl(fd, SIOCGIFADDR, (char*)&buf[if_num]);
        if(ret) continue;
        
        printf("IP Address: %s\n", inet_ntoa(((struct sockaddr_in*)(&buf[if_num].ifr_addr))->sin_addr));
        
        ret = ioctl(fd, SIOCGIFHWADDR, (char*)&buf[if_num]);
        if(ret) continue;
        
        printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[0], 
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[1], 
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[2], 
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[3], 
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[4], 
                (unsigned char)buf[if_num].ifr_hwaddr.sa_data[5]);
    }
    
}

void port_status(unsigned int flags)
{
    if(flags & IFF_UP)
    {
        printf("is IFF_UP\n");
    }
    if(flags & IFF_BROADCAST)
    {
        printf("is IFF_BROADCAST\n");
    }
    if(flags & IFF_LOOPBACK)
    {
        printf("is IFF_LOOPBACK\n");
    }
    if(flags & IFF_POINTOPOINT)
    {
        printf("is IFF_POINTTOPOINT\n");
    }
    if(flags & IFF_RUNNING)
    {
        printf("is IFF_RUNNING\n");
    }
    if(flags & IFF_PROMISC)
    {
        printf("is IFF_PROMISC\n");
    }
}


int demo2()
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(fd > 0)
    {
        get_if_info(fd);
        close(fd);
    }
    
    return 0;
}

int main(int argc, char *argv[])
{
	demo1(argc, argv);
    demo2();
    
	return 0;
}





















