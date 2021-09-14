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
 *  检测接口的物理连接是否正常
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

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;


#include <linux/ethtool.h>
#include <linux/sockios.h>


static void usage()
{
    printf("usage: ipconfig interface\n");
    exit(1);
}

int detect_mii(int skfd, char *ifname)
{
    struct ifreq ifr;
    u16 *data, mii_val;
    unsigned phy_id;
    
    /*get the vitals from the interface*/
    strncpy(ifr.ifr_name, ifname, strlen(ifname)+1);
    
    if(ioctl(skfd, SIOCGMIIPHY, &ifr) < 0)
    {
        printf("SIOCGMIIPHY on %s failed\n", ifname);
        (void )close(skfd);
        return 2;
    }
    
    data = (u16*)(&ifr.ifr_data);
    phy_id = data[0];
    data[1] = 1;
    
    if(ioctl(skfd, SIOCGMIIREG, &ifr) < 0)
    {
        printf("SIOCGMIIREG on %s failed\n", ifname);
        //(void )close(skfd);
        return 2;
    }
    
    mii_val = data[3];
    
    return (((mii_val & 0x0016) == 0x0004)?0:1);
}

int detect_ethtool(int skfd, char *ifname)
{
    struct ifreq ifr;
    struct ethtool_value edata;
    
    memset(&ifr, 0, sizeof(ifr));
    
    edata.cmd = ETHTOOL_GLINK;
    
    strncpy(ifr.ifr_name, ifname, strlen(ifname)+1);
    ifr.ifr_data = (char*)&edata;
    
    if(ioctl(skfd, SIOCETHTOOL, &ifr) < 0)
    {
        printf("SIOCETHTOOL on %s failed: %s\n", strerror(errno));
        //(void )close(skfd);
        return 2;
    }
    
    return (edata.data?0:1);
}

int main(int argc, char *argv[])
{
    int skfd = -1;
    char *ifname;
    
    int retval;
    
    if(argv[1])
    {
        ifname = argv[1];
    }
    else
    {
        usage();
        exit(0);
    }
    
    /*open a socket*/
    skfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    retval = detect_ethtool(skfd, ifname);
    if(retval == 2)
    {
        retval = detect_mii(skfd, ifname);
    }
    close(skfd);
    
    if(retval == 2)
        printf("could not determine status\n");
    if(retval == 1)
        printf("link down\n");
    if(retval == 0)
        printf("link up\n");
    
    
    return retval;
}