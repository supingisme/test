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
#include <net/if.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>



int main(int argc, char *argv[])
{
	char *ifname, *ifactualname;

	struct ifreq ifr;

	if(argc != 2)
	{
		printf("Usage: %s [ifname]\n", argv[0]);
		return -1;
	}

	ifname = strdup(argv[1]);
	printf("Requested interface name: %s\n", ifname);

	memset(&ifr, 0, sizeof(ifr));

	(void)strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name));

	int sockfd = socket(AF_LOCAL, SOCK_DGRAM, 0);

	//if(ioctl(sockfd, SIOCIFCREATE2, &ifr) != 0)
	//if(ioctl(sockfd, SIOCIFDESTROY, &ifr) != 0)
	if(ioctl(sockfd, SIOCADDRT, &ifr) != 0)
	//if(ioctl(sockfd, 1, &ifr) != 0)
	{
		perror("ioctl");
	}

	ifname = strdup(ifr.ifr_name);
	if(ifname == NULL)
	{
		printf("NULL pointer error\n");
	}

	return 0;
}
