/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:17 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
#include <stdio.h>
#include <malloc.h>

#include <sys/socket.h>

#include <net/if.h>
#include <net/route.h>

#include <linux/rtnetlink.h>
#include <linux/netlink.h>

#include <asm/types.h>

/* sizeof(struct sockaddr_in6) * 8 = 192 */
#define BUFLEN	(sizeof(struct rt_msghdr) + 512) 

#define SEQ	9999

#define RTAX_MAX 256

int main(int argc, char *argv[])
{
	int sockfd;
	char *buf;
	pid_t pid;

	ssize_t n;

	struct rt_msghdr *rtm;
	struct sockaddr *sa, *rti_info[RTAX_MAX];
	struct sockaddr_in *sin;

	if(argc != 2)
	{
		fprintf(stderr, "usage: %s [ip]\n", argv[0]);
		exit(1);
	}

	sockfd = socket(AF_ROUTE, SOCK_RAW, 0);

	buf = malloc(sizeof(char)*BUFLEN);

	rtm = (struct rt_msghdr *) buf;
	rtm->rtm_msglen = sizeof(struct rt_msghdr) + sizeof(struct sockaddr_in);
	rtm->rtm_version = RTM_VERSION;
	rtm->rtm_type = RTM_GET;
	rtm->rtm_addrs = RTA_DST;
	rtm->rtm_pid = pid = getpid();
	rtm->rtm_seq = SEQ;

	sin = (struct sockaddr_in *) (rtm + 1);
	sin->sin_len = sizeof(struct sockaddr_in);
	sin->sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &sin->sin_addr);

	write(sockfd, rtm, rtm->rtm_msglen);

	do {
		n = Read(sockfd, rtm, BUFLEN);
	} while (rtm->rtm_type != RTM_GET || rtm->rtm_seq != SEQ ||
			 rtm->rtm_pid != pid);
/* end getrt1 */

/* include getrt2 */
	rtm = (struct rt_msghdr *) buf;
	sa = (struct sockaddr *) (rtm + 1);
	get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
	if ( (sa = rti_info[RTAX_DST]) != NULL)
		printf("dest: %s\n", Sock_ntop_host(sa, sa->sa_len));

	if ( (sa = rti_info[RTAX_GATEWAY]) != NULL)
		printf("gateway: %s\n", Sock_ntop_host(sa, sa->sa_len));

	if ( (sa = rti_info[RTAX_NETMASK]) != NULL)
		printf("netmask: %s\n", Sock_masktop(sa, sa->sa_len));

	if ( (sa = rti_info[RTAX_GENMASK]) != NULL)
		printf("genmask: %s\n", Sock_masktop(sa, sa->sa_len));

	exit(0);

	return 0;
}


