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
//These two functions are the most general of all the I/O functions. Indeed, we could replace all calls to read, readv, recv, and recvfrom with calls to recvmsg. Similarly all calls to the various output functions could be replaced with calls to sendmsg.
//

#include <sys/socket.h>
ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
ssize_t sendmsg(int sockfd, struct msghdr *msg, int flags);
//Both return: number of bytes read or written if OK, –1 on error
//
//Both functions package most arguments into a msghdr structure.
struct msghdr {
	void *msg_name; /* protocol address */
	socklen_t msg_namelen; /* size of protocol address */
	struct iovec *msg_iov; /* scatter/gather array */
	int msg_iovlen; /* # elements in msg_iov */
	void *msg_control; /* ancillary data (cmsghdr struct) */
	socklen_t msg_controllen; /* length of ancillary data */
	int msg_flags; /* flags returned by recvmsg() */
};

//The msghdr structure that we show is the one specified in POSIX. Some systems still use an older msghdr structure that originated with 4.2BSD. This older structure does not have the msg_flags member, and the msg_control and msg_controllen members are named msg_accrights and msg_accrightslen. The newer form of the msghdr structure is often available using conditional compilation flags. The only form of ancillary data supported by the older structure is the passing of file descriptors (called access rights).
//The msg_name and msg_namelen members are used when the socket is not connected (e.g., an unconnected UDP socket). They are similar to the fifth and sixth arguments to recvfrom and sendto: msg_name points to a socket address structure in which the caller stores the destination's protocol address for sendmsg, or in which recvmsg stores the sender's protocol address. If a protocol address does not need to be specified (e.g., a TCP socket or a connected UDP socket), msg_name should be set to a null pointer. msg_namelen is a value for sendmsg, but a value-result for recvmsg.
//The msg_iov and msg_iovlen members specify the array of input or output buffers (the array of iovec structures), similar to the second and third arguments for readv or writev. The msg_control and msg_controllen members specify the location and size of the optional ancillary data. msg_controllen is a value-result argument for recvmsg. We will describe ancillary data in Section 14.6(See 9.3.6).
//With recvmsg and sendmsg, we must distinguish between two flag variables: the flags argument, which is passed by value, and the msg_flags member of the msghdr structure, which is passed by reference (since the address of the structure is passed to the function).
//• The msg_flags member is used only by recvmsg. When recvmsg is called, the flags argument is copied into the msg_flags member (p. 502 of TCPv2) and this value is used by the kernel to drive its receive processing. This value is then updated based on the result of recvmsg.
//• The msg_flags member is ignored by sendmsg because this function uses the flags argument to drive its output processing. This means if we want to set the MSG_DONTWAIT flag in a call to sendmsg, we set the flags argument to this value; setting the msg_flags member to this value has no effect.
//Figure 14.7 summarizes the flags that are examined by the kernel for both the input and output functions, as well as the msg_flags that might be returned by recvmsg. There is no column for sendmsg msg_flags because, as we mentioned, it is not used.
//
//
//MSG_BCAST
//This flag is relatively new, supported by at least BSD, and is returned if the datagram was received as a link-layer broadcast or with a destination IP address that is a broadcast address. This flag is a better way of determining if a UDP datagram was sent to a broadcast address, compared to the IP_RECVDSTADDR socket option.
//MSG_MCAST
//This flag is also a fairly recent addition, supported by at least BSD,
//MSG_BCAST
//This flag is relatively new, supported by at least BSD, and is returned if the datagram was received as a link-layer broadcast or with a destination IP address that is a broadcast address. This flag is a better way of determining if a UDP datagram was sent to a broadcast address, compared to the IP_RECVDSTADDR socket option.
//and is returned if the datagram was received as a link-layer multicast.
//MSG_TRUNC
//This flag is returned if the datagram was truncated; in other words, the kernel has more data to return than the process has allocated room for (the sum of all the iov_len members). We will discuss this more in Section 22.3(See 9.11.3).
//MSG_CTRUNC
//This flag is returned if the ancillary data was truncated; in other words, the kernel has more ancillary data to return than the process has allocated room for (msg_controllen).
//MSG_EOR
//This flag is cleared if the returned data does not end a logical record; the flag is turned on if the returned data ends a logical record. TCP does not use this flag since it is a byte-stream protocol.
//MSG_OOB
//This flag is never returned for TCP out-of-band data. This flag is returned by other protocol suites (e.g., the OSI protocols).
//MSG_NOTIFICATON
//This flag is returned for SCTP receivers to indicate that the message read is an event notification, not a data message.
//
