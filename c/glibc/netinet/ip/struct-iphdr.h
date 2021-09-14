/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 09:06:26 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 09:06:23 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 09:00:38 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 08:49:51 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 14日 星期四 08:40:03 CST. */
struct iphdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int ihl:4;
	unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	unsigned int version:4;
	unsigned int ihl:4;
#else
# error	"Please fix <bits/endian.h>"
#endif
	u_int8_t tos;
	u_int16_t tot_len;
	u_int16_t id;
	u_int16_t frag_off;
	u_int8_t ttl;
	u_int8_t protocol;
	u_int16_t check;
	u_int32_t saddr;
	u_int32_t daddr;
	/*The options start here. */
};

/**
 *	Rong Tao 2019.03.14
 *
 *	0      3 4     7 8            1314 1516                                   31
 *	+-------+-------+---------------+---+-------------------------------------+ ---
 *	|version| hdrLen|     DSCP      |ECN|           total length(in bytes)    |  ^
 *	+-------+-------+---------------+---+-+--+--+-----------------------------+  |
 *  |           identification          |0|DF|MF|  fragment offset            |  |
 *	+---------------+-------------------+-+--+--+-----------------------------+  |
 *	|time to live   | protocol          |        header checksum              | 20 bytes
 *	+---------------+-------------------+-------------------------------------+  |
 *	|                 32-bit source IPv4 address                              |  |
 *	+-------------------------------------------------------------------------+  |
 *	|                 32-bit destination IPv4 address                         |  ^
 *	+-------------------------------------------------------------------------+ ---
 *	|                       options(if any)                                   |
 *	+-------------------------------------------------------------------------+
 *	|                                                                         |
 *	|                         data                                            |
 *	+-------------------------------------------------------------------------+
 */

/**
 *	• The 4-bit version field is 4. This has been the version of IP in use since the early 1980s.
 *	• The header length field is the length of the entire IP header, including any options, in whole 32-bit words. The maximum value for this 4-bit field is 15 (0xf), giving a maximum IP header length of 60 bytes. Therefore, with the fixed portion of the header occupying 20 bytes, this allows for up to 40 bytes of options.
 *	• The 6-bit Differentiated Services Code Point (DSCP) field (RFC 2474 [Nichols et al. 1998]) and the 2-bit Explicit Congestion Notification (ECN) field (RFC 3168 [Ramakrishnan, Floyd, and Black 2001]) replace the historical 8-bit type-of-service (TOS) field, which was described in RFC 1349 [Almquist 1992]. We can set all 8 bits of this field with the IP_TOS socket option (Section 7.6(See 8.5.6)), although the kernel may overwrite any value we set to enforce Diffserv policy or implement ECN.
 *	• The 16-bit total length field is the total length in bytes of the IP datagram, including the IPv4 header. The amount of data in the datagram is this field minus 4 times the header length (recall that the header length is in units of whole 32-bit words, or 4 bytes). This field is required because some datalinks pad the frame to some minimum length (e.g., Ethernet) and it is possible for the size of a valid IP datagram to be less than the datalink minimum.
 *	• The 16-bit identification field is set to a different value for each IP datagram and enables fragmentation and reassembly (Section 2.11(See 7.2.11)). The value must be unique for the packet's source, destination, and protocol, for the length of time that the datagram could be in transit. If there is no chance that the packet will be fragmented, for instance, the DF bit is set, there is no need to set this field.
 *	• The DF (don't fragment) bit, the MF (more fragments) bit, and the 13-bit fragment offset field are also used with fragmentation and reassembly. The DF bit is also used with path MTU discovery (Section 2.11(See 7.2.11)).
 *	• The 8-bit time-to-live (TTL) field is set by the sender and then decremented by 1 each time a router forwards the datagram. The datagram is discarded by any router that decrements the value to 0. This limits the lifetime of any IP datagram to 255 hops. A common default for this field is 64, but we can query and change this default with the IP_TTL and IP_MULTICAST_TTL socket options (Section 7.6(See 8.5.6)).
 *	• The 8-bit protocol field specifies the next layer protocol contained in the IP datagram. Typical values are 1 (ICMPv4), 2 (IGMPv4), 6 (TCP), and 17 (UDP). These values are specified in the IANA's "Protocol Numbers" registry [IANA].
 *	• The 16-bit header checksum is calculated over just the IP header (including any options). The algorithm is the standard Internet checksum algorithm, a simple 16-bit one's-complement addition, which we show in Figure 28.15(See 9.17.5).
 *	• The source IPv4 address and the destination IPv4 address are both 32-bit fields.
 *	• We describe the options field in Section 27.2(See 9.16.2) and show an example of the IPv4 source route option in Section 27.3(See 9.16.3).
 *
 */
