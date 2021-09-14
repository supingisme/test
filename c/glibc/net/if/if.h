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


struct ifconf {
	int ifc_len; /* size of buffer, value-result */
	union {
		caddr_t ifcu_buf; /* input from user -> kernel */
		struct ifreq *ifcu_req; /* return from kernel -> user */
	} ifc_ifcu;
};
#define ifc_buf ifc_ifcu.ifcu_buf /* buffer address */
#define ifc_req ifc_ifcu.ifcu_req /* array of structures returned */
#define IFNAMSIZ 16
struct ifreq {
	char ifr_name[IFNAMSIZ]; /* interface name, e.g., "le0" */
	union {
		struct sockaddr ifru_addr;
		struct sockaddr ifru_dstaddr;
		struct sockaddr ifru_broadaddr;
		short ifru_flags;
		int ifru_metric;
		caddr_t ifru_data;
	} ifr_ifru;
};
#define ifr_addr ifr_ifru.ifru_addr /* address */
#define ifr_dstaddr ifr_ifru.ifru_dstaddr /* other end of point-to-point link */
#define ifr_broadaddr ifr_ifru.ifru_broadaddr /* broadcast address */
#define ifr_flags ifr_ifru.ifru_flags /* flags */
#define ifr_metric ifr_ifru.ifru_metric /* metric */
#define ifr_data ifr_ifru.ifru_data /* for use by interface */

/**
 *
 */
#include <net/if.h>
struct if_nameindex {
	unsigned int if_index; /* 1, 2, ... */
	char *if_name; /* null-terminated name: "le0", ... */
};

unsigned int if_nametoindex (const char *ifname);
//Returns: positive interface index if OK, 0 on error

char *if_indextoname (unsigned int ifindex, char *ifname);
//Returns: pointer to interface name if OK, NULL on error

struct if_nameindex *if_nameindex (void);
//Returns: non-null pointer if OK, NULL on error

void if_freenameindex(struct if_nameindex *ptr);
