#include <string.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <net/if.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/sockios.h>
#include <linux/ethtool.h>
 

#ifndef _LINUX_ETHTOOL_H

#ifndef SIOCETHTOOL
#define SIOCETHTOOL     0x8946
#endif

/* hack, so we may include kernel's ethtool.h */
//typedef unsigned long long __u64;
typedef __uint32_t __u32;       /* ditto */
typedef __uint16_t __u16;       /* ditto */
typedef __uint8_t __u8;         /* ditto */

/* CMDs currently supported */
#define ETHTOOL_GSET        0x00000001 /* Get settings. */
#define ETHTOOL_SSET        0x00000002 /* Set settings. */

struct ethtool_cmd {
	__u32	cmd;
	__u32	supported;
	__u32	advertising;
	__u16	speed;
	__u8	duplex;
	__u8	port;
	__u8	phy_address;
	__u8	transceiver;
	__u8	autoneg;
	__u8	mdio_support; //
	__u32	maxtxpkt;//
	__u32	maxrxpkt;
	__u16	speed_hi;
	__u8	eth_tp_mdix;
	__u8	eth_tp_mdix_ctrl;
	__u32	lp_advertising;
	__u32	reserved[2];
};
#endif //_LINUX_ETHTOOL_H
 
 
 
/* The forced speed, 10Mb, 100Mb, gigabit, 2.5Gb, 10GbE. */
#define SPEED_10        10
#define SPEED_100       100
#define SPEED_1000      1000
#define SPEED_2500      2500
#define SPEED_10000     10000


int main(int argc, char *argp[])
{
    if(argc != 2)
    {
        fprintf(stdout, "parameter is erro . usage : getNet ethXX!\n");
        return 1;
    }
    char *devname;
    devname = argp[1] ; // 取得网卡名
 
    struct ifreq ifr, *ifrp;  // 接口请求结构
    int fd;  
 
    /* Setup our control structures. */
    memset(&ifr, 0, sizeof(ifr));
    strcpy(ifr.ifr_name, devname);
 
    /* Open control socket. */
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        perror("Cannot get control socket");
        return 70;
    }
    
    int err;
    struct ethtool_cmd ep;
 
    ep.cmd = ETHTOOL_GSET; 
    ifr.ifr_data = (caddr_t)&ep;  
    err = ioctl(fd, SIOCETHTOOL, &ifr); 
    if (err != 0) { // 如果出错退出; 
        printf(" ioctl is erro .\n");
        return -1;
    }
    
    printf("<<<%s>>> \n", devname);
    printf("supported           %d \n", ep.supported);
    printf("advertising         %d \n", ep.advertising);
    printf("speed               %d Mb \n", ep.speed);
    printf("duplex              %u \n", ep.duplex);
    printf("port                %u \n", ep.port);
    printf("phy_address         %u \n", ep.phy_address);
    printf("transceiver         %u \n", ep.transceiver);
    printf("autoneg             %u \n", ep.autoneg);
    printf("mdio_support        %u \n", ep.mdio_support);
    printf("maxtxpkt            %d \n", ep.maxtxpkt);
    printf("maxrxpkt            %d \n", ep.maxrxpkt);
    printf("speed_hi            %d \n", ep.speed_hi);
    printf("eth_tp_mdix         %u \n", ep.eth_tp_mdix);
    printf("eth_tp_mdix_ctrl    %u \n", ep.eth_tp_mdix_ctrl);
    printf("lp_advertising      %d \n", ep.lp_advertising);

 
    return 0; 
}

