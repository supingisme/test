BSD Packet Filter (BPF)

是一个过滤机制，它用于过滤送往特定地点比如用户空间的数据包，他被设计成一种类似汇编语言的语言，
可以称之为伪汇编码。
虽然被设计用来过滤数据包，但是这种设计方式更适合于操作硬件，特别是用来编写需要写少量固定序列的
硬件驱动程序。
不管用于什么，BPF的设计师优秀的，时状态机实现控制逻辑的完美实例。
BPF实际上是一组基于状态机的匹配过滤序列，用于简单的数据包模式匹配。


4.4BSD and many other Berkeley-derived implementations support BPF, the BSD packet filter. The implementation of BPF is described in Chapter 31 of TCPv2. The history of BPF, a description of the BPF pseudomachine, and a comparison with the SunOS 4.1.x NIT packet filter is provided in [McCanne and Jacobson 1993].
Each datalink driver calls BPF right before a packet is transmitted and right after a packet is received, as shown in Figure 29.1.


###Three techniques are used by BPF to reduce its overhead:

• The BPF filtering is within the kernel, which minimizes the amount of data copied from BPF to the application. This copy, from kernel space to user space, is expensive. If every packet was copied, BPF could have trouble keeping up with fast datalinks.
• Only a portion of each packet is passed by BPF to the application. This is called the snapshot length, or snaplen. Most applications need only the packet headers, not the packet data. This also reduces the amount of data copied by BPF to the application. tcpdump, for example, defaults this value to 96, which allows room for a 14-byte Ethernet header, a 40-byte IPv6 header, a 20-byte TCP header, and 22 bytes of data. But, to print additional information for other protocols (e.g., DNS and NFS) requires the user to increase this value when tcpdump is run.
• BPF buffers the data destined for an application and this buffer is copied to the application only when the buffer is full, or when the read timeout expires. This timeout value can be specified by the application. tcpdump, for example, sets the timeout to 1000 ms, while the RARP daemon sets it to 0 (since there are few RARP packets, and the RARP server needs to send a response as soon as it receives the request). The purpose of the buffering is to reduce the number of system calls. The same number of packets are still copied between BPF and the application, but each system call has an overhead, and reducing the number of system calls always reduces the overhead. (Figure 3.1 of APUE compares the overhead of the read system call, for example, when reading a given file in different chunk sizes varying between 1 byte and 131,072 bytes.)



