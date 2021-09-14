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
/*
 *	用来获取IP地址和掩码信息的
 */
//126:struct ifreq
//127-  {
//128-# define IFHWADDRLEN	6
//129-# define IFNAMSIZ	IF_NAMESIZE
//130-    union
//131-      {
//132-	char ifrn_name[IFNAMSIZ];	/* Interface name, e.g. "en0".  */
//133-      } ifr_ifrn;
//134-
//135-    union
//136-      {
//137-	struct sockaddr ifru_addr;
//138-	struct sockaddr ifru_dstaddr;
//139-	struct sockaddr ifru_broadaddr;
//140-	struct sockaddr ifru_netmask;
//141-	struct sockaddr ifru_hwaddr;
//142-	short int ifru_flags;
//143-	int ifru_ivalue;
//144-	int ifru_mtu;
//145-	struct ifmap ifru_map;
//146-	char ifru_slave[IFNAMSIZ];	/* Just fits the size */
//147-	char ifru_newname[IFNAMSIZ];
//148-	__caddr_t ifru_data;
//149-      } ifr_ifru;
//150-  };



