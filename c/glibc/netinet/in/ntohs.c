/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:18 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:27 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 11日 星期一 08:57:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:57:39 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:52:32 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
/**
 *	htonl
 *
 *	Otherwise, you have to convert the values explicitly. Use htons and ntohs to convert
 *	values for the sin_port member. Use htonl and ntohl to convert IPv4 addresses for
 *	the sin_addr member. (Remember, struct in_addr is equivalent to uint32_t.) These
 *	functions are declared in ‘netinet/in.h’.
 *	uint16_t htons (uint16 t hostshort) [Function]
 *	This function converts the uint16_t integer hostshort from host byte order to network
 *	byte order.
 *	uint16_t ntohs (uint16 t netshort) [Function]
 *	This function converts the uint16_t integer netshort from network byte order to host
 *	byte order.
 *	uint32_t htonl (uint32 t hostlong) [Function]
 *	This function converts the uint32_t integer hostlong from host byte order to network
 *	byte order.
 *	This is used for IPv4 Internet addresses.
 *	uint32_t ntohl (uint32 t netlong) [Function]
 *	This function converts the uint32_t integer netlong from network byte order to host
 *	byte order.
 *	This is used for IPv4 Internet addresses.
 */
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct msg_s{
	uint8_t type;
	uint16_t code;
	uint32_t len;
}Msg;

static union endian_test{
	uint8_t u8[2];
	uint16_t u16;
}endian_u = {
	.u16 = 0x0102,
};

int main()
{
	printf("endian: %#04x:%d,%d\n", endian_u.u16, endian_u.u8[0], endian_u.u8[1]);

	printf("%d, %d, %d, %d, %d, %d\n", 
			htonl(12), 
			ntohl(201326592), 
			ntohl(201326591),
			ntohl(-245),
			htons(12),
			htons(-245));
	
	return 1;
}
