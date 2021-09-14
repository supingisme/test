/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>   
#include <string.h>  
#include <errno.h>  
#include <time.h>  
 
#include <sys/types.h>  
#include <sys/socket.h>  
#include <sys/ioctl.h>  
                 
#include <netinet/in.h>   
#include <netinet/if_ether.h>  
#include <net/if.h>  
#include <net/if_arp.h>  
#include <arpa/inet.h>    
              
// struct ethhdr {
	// unsigned char	h_dest[ETH_ALEN];	/* destination eth addr	*/
	// unsigned char	h_source[ETH_ALEN];	/* source ether addr	*/
	// __be16		h_proto;		/* packet type ID field	*/
// } __attribute__((packed));
struct arpMsg {  
    struct ethhdr ethhdr;       /* Ethernet header */  
    u_short htype;              /* hardware type (must be ARPHRD_ETHER) */  
    u_short ptype;              /* protocol type (must be ETH_P_IP) */  
    u_char  hlen;               /* hardware address length (must be 6) */  
    u_char  plen;               /* protocol address length (must be 4) */  
    u_short operation;          /* ARP opcode */  
    u_char  sHaddr[6];          /* sender's hardware address */  
    u_char  sInaddr[4];         /* sender's IP address */  
    u_char  tHaddr[6];          /* target's hardware address */  
    u_char  tInaddr[4];         /* target's IP address */  
    u_char  pad[18];            /* pad for min. Ethernet payload (60 bytes) */  
};  
  
struct server_config_t {  
    u_int32_t server;       /* Our IP, in network order */  
    u_int32_t start;        /* Start address of leases, network order */  
    u_int32_t end;          /* End of leases, network order */  
    struct option_set *options; /* List of DHCP options loaded from the config file */  
    char *interface;        /* The name of the interface to use */  
    int ifindex;            /* Index number of the interface to use */  
    unsigned char arp[6];       /* Our arp address */  
    unsigned long lease;        /* lease time in seconds (host order) */  
    unsigned long max_leases;   /* maximum number of leases (including reserved address) */  
    char remaining;         /* should the lease file be interpreted as lease time remaining, or 
                     * as the time the lease expires */  
    unsigned long auto_time;    /* how long should udhcpd wait before writing a config file. 
                     * if this is zero, it will only write one on SIGUSR1 */  
    unsigned long decline_time;     /* how long an address is reserved if a client returns a 
                         * decline message */  
    unsigned long conflict_time;    /* how long an arp conflict offender is leased for */  
    unsigned long offer_time;   /* how long an offered address is reserved */  
    unsigned long min_lease;    /* minimum lease a client can request*/  
    char *lease_file;  
    char *pidfile;  
    char *notify_file;      /* What to run whenever leases are written */  
    u_int32_t siaddr;       /* next server bootp option */  
    char *sname;            /* bootp server name */  
    char *boot_file;        /* bootp boot file option */  
};  
         
#define MAC_BCAST_ADDR      (unsigned char *) "/xff/xff/xff/xff/xff/xff"  
#define ETH_INTERFACE       "eth0"  
              
struct server_config_t server_config;  
  

int read_interface(char *interface, int *ifindex, u_int32_t *addr, unsigned char *arp)  
{  
    int fd;  
    /*ifreq结构定义在/usr/include/net/if.h，用来配置ip地址，激活接口，配置MTU等接口信息的。 
    其中包含了一个接口的名字和具体内容——（是个共用体，有可能是IP地址，广播地址，子网掩码，MAC号，MTU或其他内容）。 
    ifreq包含在ifconf结构中。而ifconf结构通常是用来保存所有接口的信息的。 
    */  
    struct ifreq ifr;  
    struct sockaddr_in *our_ip;  
  
    memset(&ifr, 0, sizeof(struct ifreq));  
    /*建立一个socket函数，SOCK_RAW是为了获取第三个参数的IP包数据， 
     IPPROTO_RAW提供应用程序自行指定IP头部的功能。 
    */  
    if((fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) >= 0) 
    {  
        ifr.ifr_addr.sa_family = AF_INET;  
        /*将网卡类型赋值给ifr_name*/  
        strcpy(ifr.ifr_name, interface);  
  
        if (addr) 
        {  
            /*SIOCGIFADDR用于检索接口地址*/  
            if (ioctl(fd, SIOCGIFADDR, &ifr) == 0) 
            {  
                /*获取本机IP地址，addr是一个指向该地址的指针*/  
                our_ip = (struct sockaddr_in *) &ifr.ifr_addr;  
                *addr = our_ip->sin_addr.s_addr;  
                printf("%s (our ip) = %s\n", ifr.ifr_name, inet_ntoa(our_ip->sin_addr));  
            } 
            else 
            {  
                printf("SIOCGIFADDR failed, is the interface up and configured?: %s\n",  
                        strerror(errno));  
				
                return -1;  
            }  
        }  
  
        /*SIOCGIFINDEX用于检索接口索引*/  
        if (ioctl(fd, SIOCGIFINDEX, &ifr) == 0) 
        {  
            //printf("adapter index %d\n", ifr.ifr_ifindex);  
            /*指针ifindex 获取索引*/  
            *ifindex = ifr.ifr_ifindex; 
            //printf("SIOCGIFINDEX : %d\n", *ifindex);  
        } 
        else 
        {  
            printf("SIOCGIFINDEX failed!: %s\n", strerror(errno));  
            return -1;  
        }  
        /*SIOCGIFHWADDR用于检索硬件地址*/  
        if (ioctl(fd, SIOCGIFHWADDR, &ifr) == 0) 
        {  
            /*所获取的硬件地址复制到结构server_config的数组arp[6]参数中*/  
            memcpy(arp, ifr.ifr_hwaddr.sa_data, 6);  
            //printf("adapter hardware address %02x:%02x:%02x:%02x:%02x:%02x\n",  
               // arp[0], arp[1], arp[2], arp[3], arp[4], arp[5]);  
        } 
        else 
        {  
            printf("SIOCGIFHWADDR failed!: %s\n", strerror(errno));  
            return -1;  
        }  
    }  
    else 
    {  
        printf("socket failed!: %s\n", strerror(errno));  
        return -1;  
    }  
    close(fd);  
    return 0;  
}  
  
int check_ip(u_int32_t addr)  
{  
    struct in_addr temp;  
  
    if (arpping(addr, server_config.server, server_config.arp, ETH_INTERFACE) == 0)  
    {  
        temp.s_addr = addr;  
        printf("%s belongs to someone, reserving it for %ld seconds\n",  
            inet_ntoa(temp), server_config.conflict_time);  
        return 1;  
    }  
    else  
        return 0;  
} 

/*参数说明 目标IP地址，本机IP地址，本机mac地址，网卡类型*/  
int arpping(u_int32_t yiaddr, u_int32_t ip, unsigned char *mac, char *interface)  
{  
    int timeout = 2;  
    int optval = 1;  
    int s;                      /* socket */  
    int ret = 1;                 /* return value */  
    struct sockaddr addr;       /* for interface name */  
    struct arpMsg arp;  
    fd_set fdset;  
    struct timeval tm;  
    time_t prevTime;  
  
    /*socket发送一个arp包*/  
    if ((s = socket (PF_PACKET, SOCK_PACKET, htons(ETH_P_ARP))) == -1) 
    {  
        printf("Could not open raw socket\n");  
        return -1;  
    }  
      
    /*设置套接口类型为广播，把这个arp包是广播到这个局域网*/  
    if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1) 
    {  
        printf("Could not setsocketopt on raw socket\n");  
        close(s);  
        return -1;  
    }  
  
    /* 对arp设置，这里按照arp包的封装格式赋值即可，
       详见http://blog.csdn.net/wanxiao009/archive/2010/05/21/5613581.aspx */  
    memset(&arp, 0, sizeof(arp));  
    memcpy(arp.ethhdr.h_dest, MAC_BCAST_ADDR, 6);   /* MAC DA */  
    memcpy(arp.ethhdr.h_source, mac, 6);        /* MAC SA */  
    arp.ethhdr.h_proto = htons(ETH_P_ARP);      /* protocol type (Ethernet) */  
    arp.htype = htons(ARPHRD_ETHER);        /* hardware type */  
    arp.ptype = htons(ETH_P_IP);            /* protocol type (ARP message) */  
    arp.hlen = 6;                   /* hardware address length */  
    arp.plen = 4;                   /* protocol address length */  
    arp.operation = htons(ARPOP_REQUEST);       /* ARP op code */  
    *((u_int *) arp.sInaddr) = ip;          /* source IP address */  
    memcpy(arp.sHaddr, mac, 6);         /* source hardware address */  
    *((u_int *) arp.tInaddr) = yiaddr;      /* target IP address */  
  
    memset(&addr, 0, sizeof(addr));  
    strcpy(addr.sa_data, interface);  
    /*发送arp请求*/  
    if (sendto(s, &arp, sizeof(arp), 0, &addr, sizeof(addr)) < 0)  
        ret = 0;  
  
    /* 利用select函数进行多路等待*/  
    tm.tv_usec = 0;  
    time(&prevTime);  
    while (timeout > 0) 
    {  
        FD_ZERO(&fdset);  
        FD_SET(s, &fdset);  
        tm.tv_sec = timeout;  
        if (select(s + 1, &fdset, (fd_set *) NULL, (fd_set *) NULL, &tm) < 0) 
        {  
            printf("Error on ARPING request: %s\n", strerror(errno));  
            if (errno != EINTR) ret = 0;  
        } 
        else if (FD_ISSET(s, &fdset)) 
        {  
            printf("Success on ARPING request: %s\n", strerror(errno)); 
            if (recv(s, &arp, sizeof(arp), 0) < 0 )   
                ret = 0;  
            /*如果条件 
               htons(ARPOP_REPLY) 
               bcmp(arp.tHaddr, mac, 6) == 0 
               *((u_int *) arp.sInaddr) == yiaddr 三者都为真，
              则ARP应答有效,说明这个地址是已近存在的*/
			if((ntohs(arp.operation)) != 2)
			{
                printf("arp.operation = %d\n", ntohs(arp.operation));
				continue;
			}
            printf("Opcode:%d\n",ntohs(arp.operation));
            printf("target MAC:%02x:%02x:%02x:%02x:%02x:%02x\n", 
                    arp.tHaddr[0], arp.tHaddr[1], arp.tHaddr[2], arp.tHaddr[3], arp.tHaddr[4], arp.tHaddr[5]);
			 printf("target IP:%2d.%2d.%2d.%2d\n", 
                    arp.tInaddr[0], arp.tInaddr[1], arp.tInaddr[2], arp.tInaddr[3]);
			printf("source MAC:%02x:%02x:%02x:%02x:%02x:%02x\n", 
                    arp.sHaddr[0], arp.sHaddr[1], arp.sHaddr[2], arp.sHaddr[3], arp.sHaddr[4], arp.sHaddr[5]);
			printf("source IP:%2d.%2d.%2d.%2d\n", 
                    arp.sInaddr[0], arp.sInaddr[1], arp.sInaddr[2], arp.sInaddr[3]);
			sleep(1); 
        }  
        timeout -= time(NULL) - prevTime;  
        time(&prevTime);  
    }  
    close(s);  
    return ret;  
} 

int CHECK_IP()
{
    int u1,u2,u3,u4;
	char ip[16] = {0};

	u1 = 10;
	u2 = 170;
	for(u3=7;u3<17;u3++)
	{
		for(u4=169;u4<180;u4++)
		{
			memset(ip, 0, 16);
			sprintf(ip, "%d.%d.%d.%d", u1, u2, u3, u4);
            
			/*IP检测函数*/  
            if(check_ip(inet_addr(ip)) == 0)  
            {  
                printf("IP:%s can use\n", ip);   
            }  
            else  
            {  
                printf("IP:%s conflict\n", ip);  
            } 
		}
	}


	return 0;
}

int main(int argc, char *argv[])  
{    
    if(argc<2)
    {
        printf("usage: %s [ip string]\n", argv[0]);
        return -1;
    }
    
    /*读以太网接口函数，获取一些配置信息*/  
    if (read_interface(ETH_INTERFACE, &server_config.ifindex, &server_config.server, server_config.arp) < 0)  
    {  
        printf("read_interface error.\n"); 
        exit(0);  
    }  
      
    /*IP检测函数*/  
    if(check_ip(inet_addr(argv[1])) == 0)  
    {  
        printf("IP:%s can use\n", argv[1]);   
    }  
    else  
    {  
        printf("IP:%s conflict\n", argv[1]);  
    } 
      
    return 0;  
}  
