/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:26 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:31 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:02 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:15 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:53 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:59 CST. */
/*
 *	ioctl函数是对设备驱动程序中对设备IO通道进行管理的函数。
 *	所谓对IO通道进行管理，就是对设备的一些特性进行控制，例如串口的传输波特率、马达的转速等等。
 *
 *	他的参数如下
 *	int ioctl(int fd, int cmd, ...);
 *
 *	其中fd为文件描述符，cmd是用户程序对设备的控制命令。
 *
 *	ioctl函数是文件结构中的一个属性分量，就是说如果你的驱动程序提供了对ioctl的支持，
 *	用户就能在用户程序中使用ioctl函数控制设备的IO通道。
 *
 *	13.17 Generic I/O Control operations
 *	The GNU system can handle most input/output operations on many diﬀerent devices and
 *	objects in terms of a few fle primitives - read, write and lseek. However, most devices
 *	also have a few peculiar operations which do not ft into this model. Such as:
 *	• Changing the character font used on a terminal.
 *	• Telling a magnetic tape system to rewind or fast forward. (Since they cannot move in
 *	byte increments, lseek is inapplicable).
 *	• Ejecting a disk from a drive.
 *	• Playing an audio track from a CD-ROM drive.
 *	• Maintaining routing tables for a network.
 *	Although some such objects such as sockets and terminals1 have special functions of
 *	their own, it would not be practical to create functions for all these cases.
 *	Instead these minor operations, known as IOCTLs, are assigned code numbers and multi
 *	plexed through the ioctl function, defned in sys/ioctl.h. The code numbers themselves
 *	are defned in many diﬀerent headers.
 *	int ioctl (int filedes, int command, . . .) [Function]
 *	The ioctl function performs the generic I/O operation command on fledes.
 *	A third argument is usually present, either a single number or a pointer to a structure.
 *	The meaning of this argument, the returned value, and any error codes depends upon
 *	the command used. Often −1 is returned for a failure.
 *	On some systems, IOCTLs used by diﬀerent devices share the same numbers. Thus,
 *	although use of an inappropriate IOCTL usually only produces an error, you should not
 *	attempt to use device-specifc IOCTLs on an unknown device.
 *	Most IOCTLs are OS-specifc and/or only used in special system utilities, and are
 *	thus beyond the scope of this document. For an example of the use of an IOCTL, see
 *	Section 16.9.8 [Out-of-Band Data], page 422.
 */

#include <sys/ioctl.h>

int ioctl(int fd, int cmd, ...);

//There is no standard for the header to include to define the function prototype for ioctl since it is not standardized by POSIX. Many systems define it in <unistd.h>, as we show, but traditional BSD systems define it in <sys/ioctl.h>.
//We can divide the requests related to networking into six categories:
//• Socket operations
//• File operations
//• Interface operations
//• ARP cache operations
//• Routing table operations
//• STREAMS system (Chapter 31(See 9.20))



