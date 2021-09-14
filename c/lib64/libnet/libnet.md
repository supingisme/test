 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 08:39:07 CST. 
'libnet': Packet Creation and Injection Library

libnet provides an interface to craft and inject arbitrary packets into the network. It provides both raw socket and datalink access modes in an implementation-independent manner.
The library hides many of the details of crafting the IP and UDP or TCP headers, and provides simple and portable access to writing datalink and raw packets. As with libpcap, the library is made up of quite a number of functions. We will show how to use a small group of the functions for accessing raw sockets in the example in the following section, as well as the code required to use raw sockets directly for comparison. All the library functions begin with the libnet_ prefix; the libnet man page and online manual describe these functions in more detail.
The library is publicly available from http://www.packetfactory.net/libnet/. The online manual is http://www.packetfactory.net/libnet/manual/. As of this writing, the only manual available is for the deprecated version 1.0; the supported version 1.1 has a significantly different API. This example uses the 1.1 API.


