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
/**
 *	密钥管理socket
 *	sockfd = socket(PF_KEY, SOCK_RAW, PF_KEY_V2);
 */
/**
 *	With the introduction of the security architecture for IP (IPsec, described in RFC 2401 [Kent and Atkinson 1998a]), a standard mechanism was needed to manage secret encryption and authorization keys. RFC 2367 [McDonald, Metz, and Phan 1998] introduces a generic key management API that can be used for IPsec and other network security services. Similar to routing sockets (Chapter 18(See 9.7)), this API creates a new protocol family, the PF_KEY domain. As with routing sockets, the only type of socket supported in the key domain is a raw socket.
 *	As described in Section 4.2(See 8.2.2), on most systems, AF_KEY would be defined to the same value as PF_KEY. However, RFC 2367 is quite specific that PF_KEY is the constant that must be used with key management sockets.
 *	Opening a raw key management socket requires privileges. On systems where privileges are segmented, there must be an individual privilege for opening key management sockets. On regular UNIX systems, opening a key management socket is limited to the superuser.
 *	IPsec provides security services to packets based on security associations, or SAs. An SA describes a combination of source and destination addresses (and optionally, transport protocol and ports), mechanism (e.g., authentication), and keying material. More than one SA (e.g., authentication and encryption) can apply to a single stream of traffic. The set of security associations stored for use on a system is called the security association database, or SADB.
 *	The SADB on a system may be used for more than just IPsec; for instance, OSPFv2, RIPv2, RSVP, and Mobile-IP may also have entries in the SADB. For this reason, PF_KEY sockets are not specific to IPsec.
 *	IPsec also requires a security policy database, or SPDB. The security policy database describes requirements for traffic; for example, traffic between host A and host B must be authorized using IPsec AH, and any that is not must be dropped. The SADB describes how to perform the required security steps, such as, if traffic between host A and host B is using IPsec AH, then the SADB contains the algorithm and key to use. Unfortunately, there is no standard mechanism to maintain the SPDB. PF_KEY allows maintenance of the SADB, but not the SPDB. KAME's IPsec implementation uses PF_KEY extensions for SPDB maintenance, but there is no standard for this.
 *	Three types of operations are supported on key management sockets:
 *	1. A process can send a message to the kernel and all other processes with open key management sockets by writing to a key management socket. This is how
 *	SADB entries are added and deleted, and how processes that do their own security like OSPFv2 can request a key from a key management daemon.
 *	2. A process can read a message from the kernel (or another process) on a key management socket. The kernel can use this facility to request that a key management daemon install a security association for a new TCP session that policy requires be protected.
 *	3. A process can send a dump request message to the kernel, and the kernel will reply with a dump of the current SADB. This is a debugging feature that may not be available on all systems.
 */

//Reading and Writing
//All messages on a key management socket have the same basic header, shown in Figure 19.1. Each message may be followed by various extensions, depending on what additional information is available or required. All the appropriate structures are defined by including <net/pfkeyv2.h>. Each message and extension is 64-bit-aligned and is a multiple of 64 bits in length. All length fields are in units of 64 bits, that is, a length of 1 means 8 bytes. Any extension that does not require enough data to be a multiple of 64 bits in length is padded to the next multiple of 64 bits. The value of this padding is not defined.
//Figure 19.1 Key management message header.
//


#include <net/pfkeyv2.h>

struct sadb_msg {
	u_int8_t sadb_msg_version; /* PF_KEY_V2 */
	u_int8_t sadb_msg_type; /* see Figure 19.2 */
	u_int8_t sadb_msg_errno; /* error indication */
	u_int8_t sadb_msg_satype; /* see Figure 19.3 */
	u_int16_t sadb_msg_len; /* length of header + extensions / 8 */
	u_int16_t sadb_msg_reserved; /* zero on transmit, ignored on receive */
	u_int32_t sadb_msg_seq; /* sequence number */
	u_int32_t sadb_msg_pid; /* process ID of source or dest */
};
