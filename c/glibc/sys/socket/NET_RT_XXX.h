/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:29 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:32 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:03 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:16 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */

#include <sys/socket.h>

/**
 *	1. NET_RT_DUMP returns the routing table for the address family specified by name [3]. If this address family is 0, the routing tables for all address families are returned.
 *	The routing table is returned as a variable number of RTM_GET messages, with each message followed by up to four socket address structures: the destination, gateway, network mask, and cloning mask of the routing table entry. We showed one of these messages on the right side of Figure 18.5(See9.7.3) and our code in Figure 18.7(See 9.7.3) parsed one of these messages. All that changes with this sysctl operation is that one or more of these messages are returned by the kernel.
 *	2. NET_RT_FLAGS returns the routing table for the address family specified by name [3], but only the routing table entries with an RTF_xxx flag value that contains the flag specified by name [5]. All ARP cache entries in the routing table have the RTF_LLINFO flag bit set.
 *	The information is returned in the same format as the previous item.
 *	3. NET_RT_IFLIST returns information on all configured interfaces. If name [5] is nonzero, it is an interface index number, and only information on that interface is returned. (We will say more about interface indexes in Section 18.6(See 9.7.6).) All the addresses assigned to each interface are also returned, and if name [3] is nonzero, only addresses for that address family are returned.
 *	For each interface, one RTM_IFINFO message is returned, followed by one RTM_NEWADDR message for each address assigned to the interface. The RTM_IFINFO message is followed by one datalink socket address structure, and each RTM_NEWADDR message is followed by up to three socket address structures: the interface address, the network mask, and the broadcast address. These two messages are shown in Figure 18.14.
 */

#define NET_RT_DUMP
#define NET_RT_FLAGS
#define NET_RT_IFLIST



