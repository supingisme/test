// filename: getNet.c
// command sample: ./getNet eth0
// compile command: gcc -p -g  getNet.c && gcc -o getNet getNet.c
// https://blog.csdn.net/namesliu/article/details/5708172
// https://blog.csdn.net/namesliu/article/details/5708172
 
#include <string.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <linux/sockios.h>
#include <linux/ethtool.h>
#include <net/if.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
 
 
#ifndef SIOCETHTOOL
#define SIOCETHTOOL     0x8946
#endif
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif
 
/* CMDs currently supported */
#define ETHTOOL_GSET        0x00000001 /* Get settings. */
#define ETHTOOL_SSET        0x00000002 /* Set settings. */
 
/* hack, so we may include kernel's ethtool.h */
//typedef unsigned long long __u64;
typedef __uint32_t __u32;       /* ditto */
typedef __uint16_t __u16;       /* ditto */
typedef __uint8_t __u8;         /* ditto */
 
 
/* The forced speed, 10Mb, 100Mb, gigabit, 2.5Gb, 10GbE. */
#define SPEED_10        10
#define SPEED_100       100
#define SPEED_1000      1000
#define SPEED_2500      2500
#define SPEED_10000     10000

#ifndef _LINUX_ETHTOOL_H
/* This should work for both 32 and 64 bit userland. */
struct ethtool_cmd {
        __u32   cmd;
        __u32   supported;      /* Features this interface supports */
        __u32   advertising;    /* Features this interface advertises */
        __u16   speed;          /* The forced speed, 10Mb, 100Mb, gigabit */
        __u8    duplex;         /* Duplex, half or full */
        __u8    port;           /* Which connector port */
        __u8    phy_address;
        __u8    transceiver;    /* Which transceiver to use */
        __u8    autoneg;        /* Enable or disable autonegotiation */
        __u32   maxtxpkt;       /* Tx pkts before generating tx int */
        __u32   maxrxpkt;       /* Rx pkts before generating rx int */
        __u32   reserved[4];
};
#endif //_LINUX_ETHTOOL_H
//
//struct ethtool_cmd {
//	__u32	cmd;
//	__u32	supported;
//	__u32	advertising;
//	__u16	speed;
//	__u8	duplex;
//	__u8	port;
//	__u8	phy_address;
//	__u8	transceiver;
//	__u8	autoneg;
//	__u8	mdio_support; //
//	__u32	maxtxpkt;//
//	__u32	maxrxpkt;
//	__u16	speed_hi;
//	__u8	eth_tp_mdix;
//	__u8	eth_tp_mdix_ctrl;
//	__u32	lp_advertising;
//	__u32	reserved[2];
//};

int main(int argc, char *argp[])
{
    if(argc != 2)
    {
        fprintf(stdout, "parameter is erro . usage : getNet ethXX!\n");
        return 1;
    }
    char *devname;
    devname = argp[1] ; // ???????????????
    //devname = "eth0" ; // ???????????????
 
/* http://topic.csdn.net/u/20070104/12/e57086ff-1a48-477b-b672-91e4ba3b6da4.html
    ifreq???????????????/usr/include\net/if.h???????????????ip??????????????????????????????MTU?????????????????????
    ??????????????????????????????????????????????????????????????????????????????????????????IP???????????????????????????????????????MAC??????MTU?????????????????????
    ifreq?????????ifconf???????????????ifconf??????????????????????????????????????????????????????
*/
    struct ifreq ifr, *ifrp;  // ??????????????????
    int fd;   // to  access socket  ??????socket??????????????? ??????????????????fd
 
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
    //fprintf(stdout, "Settings for %s:\n", devname);
 
    ep.cmd = ETHTOOL_GSET; // ethtool-copy.h:380:#define ETHTOOL_GSET         0x00000001 /* Get settings. */
    ifr.ifr_data = (caddr_t)&ep;  //   caddr_t ???void????????????????????????????????????
    err = ioctl(fd, SIOCETHTOOL, &ifr);  //  int ioctl(int handle, int cmd,[int *argdx, int argcx]);
    if (err != 0) { // ??????????????????; 
        printf(" ioctl is erro .\n");
        return -1;
    }
 
    // ===========  ?????? ???????????????============
    fprintf(stdout, "%s Speed: ", devname );
    switch (ep.speed) {
    case SPEED_10:
        fprintf(stdout, "10Mb/s\n");
        break;
    case SPEED_100:
        fprintf(stdout, "100Mb/s\n");
        break;
    case SPEED_1000:
        fprintf(stdout, "1000Mb/s\n");
        break;
    case SPEED_2500:
        fprintf(stdout, "2500Mb/s\n");
        break;
    case SPEED_10000:
        fprintf(stdout, "10000Mb/s\n");
        break;
    default:
        fprintf(stdout, "Unknown! (%i)\n", ep.speed);
        break;
    };
 
    return 0; 
}

