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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:11 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:56 CST. */
//We will encounter datalink socket address structures as return values contained in some of the messages returned on a routing socket. Figure 18.1 shows the definition of the structure, which is defined by including <net/if_dl.h>.
//
//### Datalink Socket Address Structure

#include <net/if_dl.h>

struct sockaddr_dl {
	uint8_t sdl_len;
	sa_family_t sdl_family; /* AF_LINK */
	uint16_t sdl_index; /* system assigned index, if > 0 */
	uint8_t sdl_type; /* IFT_ETHER, etc. from <net/if_types.h> */
	uint8_t sdl_nlen; /* name length, starting in sdl_data[0] */
	uint8_t sdl_alen; /* link-layer address length */
	uint8_t sdl_slen; /* link-layer selector length */
	char sdl_data[12]; /* minimum work area, can be larger;
						  contains i/f name and link-layer address */
};

#define LLADDR(s) ((caddr_t)((s)->sdl_data + (s)->sdl_nlen))
