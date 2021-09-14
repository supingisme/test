/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:09 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:30 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:07 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:46 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*	int inet_aton (const char *name, struct in addr *addr) [Function]
 *	This function converts the IPv4 Internet host address name from the standard
 *	numbers-and-dots notation into binary data and stores it in the struct in_addr
 *	that addr points to. inet_aton returns nonzero if the address is valid, zero if not.
 *
 *
 *	struct in_addr [Data Type]
 *	This data type is used in certain contexts to contain an IPv4 Internet host address.
 *	It has just one feld, named s_addr, which records the host address number as an
 *	uint32_t.
 *
 *	struct sockaddr_in [Data Type]
 *	This is the data type used to represent socket addresses in the Internet namespace.
 *	It has the following members:
 *	sa_family_t sin_family
 *	This identifes the address family or format of the socket address. You
 *	should store the value AF_INET in this member. See Section 16.3 [Socket
 *	Addresses], page 391.
 *	struct in_addr sin_addr
 *	This is the Internet address of the host machine. See Section 16.6.2 [Host
 *	Addresses], page 398, and Section 16.6.2.4 [Host Names], page 402, for
 *	how to get a value to store here.
 *	unsigned short int sin_port
 *	This is the port number. See Section 16.6.3 [Internet Ports], page 406.
 *	When you call bind or getsockname, you should specify sizeof (struct sockaddr_in)
 *	as the length parameter if you are using an IPv4 Internet namespace socket address.
 *
 */
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <stdint.h>

void errorHandling(const char* message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main()
{
    const char string[] = "192.168.8.54";
    struct sockaddr_in sockAddr;

	int ret;

    if(ret = inet_aton(string, &sockAddr.sin_addr)){
        printf("Network ordered integer address: %#x \n", sockAddr.sin_addr.s_addr);
    }
    else{
        errorHandling("inet_aton() error!");
    }

	uint32_t ip = sockAddr.sin_addr.s_addr;
	printf("Socket ip: %#x, ret = %d\n", ip, ret);
    return 0;
}
