 Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 08:34:53 CST. 
SOCK_PACKET

The three common methods to access the datalink layer under Unix are the BSD Packet Filter (BPF), the SVR4 Datalink Provider Interface (DLPI), and the Linux SOCK_PACKET interface. We present an overview of these three, but then describe libpcap, the publicly available packet capture library. This library works with all three and using this library makes our programs independent of the actual datalink access provided by the OS. We describe this library by developing a program that sends DNS queries to a name server (we build our own UDP datagrams and write them to a raw socket) and reading the reply using libpcap to determine if the name server enables UDP checksums.

There are two methods of receiving packets from the datalink layer under Linux. The original method, which is more widely available but less flexible, is to create a socket of type SOCK_PACKET. The newer method, which introduces more filtering and performance features, is to create a socket of family PF_PACKET. To do either, we must have sufficient privileges (similar to creating a raw socket), and the third argument to socket must be a nonzero value specifying the Ethernet frame type. When using PF_PACKET sockets, the second argument to socket can be SOCK_DGRAM, for "cooked" packets with the link-layer header removed, or SOCK_RAW, for the complete link-layer packet. SOCK_PACKET sockets only return the complete link layer packet. For example, to receive all frames from the datalink, we write

```c
fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL)); /* newer systems*/
or
fd = socket(AF_INET, SOCK_PACKET, htons(ETH_P_ALL)); /* older systems*/
```

This would return frames for all protocols that the datalink receives.
If we wanted only IPv4 frames, the call would be

fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP)); /* newer systems */
or
fd = socket(AF_INET, SOCK_PACKET, htons(ETH_P_IP)); /* older systems */





