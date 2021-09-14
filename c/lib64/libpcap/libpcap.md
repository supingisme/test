 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 08:39:22 CST. 
'libpcap': Packet Capture Library


The packet capture library, libpcap, provides implementation-independent access to the underlying packet capture facility provided by the OS. Currently, it supports only the reading of packets (although adding a few lines of code to the library lets one write datalink packets too on some systems). See the next section for a description of another library that supports not only writing datalink packets, but also constructing arbitrary packets.
Support currently exists for BPF under Berkeley-derived kernels, DLPI under HP-UX and Solaris 2.x, NIT under SunOS 4.1.x, the Linux SOCK_PACKET and PF_PACKET sockets, and a few other operating systems. This library is used by tcpdump. About 25 functions comprise the library, but rather than just describe the functions, we will show the actual use of the common functions in a complete example in a later section. All the library functions begin with the pcap_ prefix. The pcap man page describes these functions in more detail.
The library is publicly available from http://www.tcpdump.org/.
