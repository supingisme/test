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
///### structures returned with routing messages

struct if_msghdr { /* from <net/if.h> */
	u_short ifm_msglen; /* to skip over non-understood messages */
	u_char ifm_version; /* future binary compatibility */
	u_char ifm_type; /* message type */
	int ifm_addrs; /* like rtm_addrs */
	int ifm_flags; /* value of if_flags */
	u_short ifm_index; /* index for associated ifp */
	struct if_data ifm_data;/* statistics and other data about if */
};

struct ifa_msghdr { /* from <net/if.h> */
	u_short ifam_msglen; /* to skip over non-understood messages */
	u_char ifam_version; /* future binary compatibility */
	u_char ifam_type; /* message type */
	int ifam_addrs; /* like rtm_addrs */
	int ifam_flags; /* value of ifa_flags */
	u_short ifam_index; /* index for associated ifp */
	int ifam_metric; /* value of ifa_metric */
};
struct ifma_msghdr { /* from <net/if.h> */
	u_short ifmam_msglen; /* to skip over non-understood messages */
	u_char ifmam_version; /* future binary compatibility */
	u_char ifmam_type; /* message type */
	int ifmam_addrs; /* like rtm_addrs */
	int ifmam_flags; /* value of ifa_flags */
	u_short ifmam_index; /* index for associated ifp */
};
struct if_announcemsghdr { /* from <net/if.h> */
	u_short ifan_msglen; /* to skip over non-understood messages */
	u_char ifan_version; /* future binary compatibility */
	u_char ifan_type; /* message type */
	u_short ifan_index; /* index for associated ifp */
	char ifan_name[IFNAMSIZ]; /* if name, e.g. "en0" */
	u_short ifan_what; /* what type of announcement */
};
