/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:09 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/*	13.6 Fast Scatter-Gather I/O
 *	Some applications may need to read or write data to multiple buﬀers, which are separated
 *	in memory. Although this can be done easily enough with multiple calls to read and write,
 *	it is inefcient because there is overhead associated with each kernel call.
 *	Instead, many platforms provide special high-speed primitives to perform these scatter
 *	gather operations in a single kernel call. The GNU C library will provide an emulation
 *	on any system that lacks these primitives, so they are not a portability threat. They are
 *	defned in sys/uio.h.
 *	These functions are controlled with arrays of iovec structures, which describe the loca
 *	tion and size of each buﬀer.
 *
 *	struct iovec [Data Type]
 *	The iovec structure describes a buﬀer. It contains two felds:
 *	void *iov_base
 *	Contains the address of a buﬀer.
 *	size_t iov_len
 *	Contains the length of the buﬀer.
 *	ssize_t readv (int filedes, const struct iovec *vector, int count) [Function]
 *	The readv function reads data from fledes and scatters it into the buﬀers described
 *	in vector, which is taken to be count structures long. As each buﬀer is flled, data is
 *	sent to the next.
 *	Note that readv is not guaranteed to fll all the buﬀers. It may stop at any point, for
 *	the same reasons read would.
 *	The return value is a count of bytes (not buﬀers) read, 0 indicating end-of-fle, or −1
 *	indicating an error. The possible errors are the same as in read.
 *	ssize_t writev (int filedes, const struct iovec *vector, int count) [Function]
 *	The writev function gathers data from the buﬀers described in vector, which is taken
 *	to be count structures long, and writes them to filedes. As each buﬀer is written,
 *	it moves on to the next.
 *	Like readv, writev may stop midstream under the same conditions write would.
 *	The return value is a count of bytes written, or −1 indicating an error. The possible
 *	errors are the same as in write.
 *	Note that if the buﬀers are small (under about 1kB), high-level streams may be easier to
 *	use than these functions. However, readv and writev are more efcient when the individual
 *	buﬀers themselves (as opposed to the total output), are large. In that case, a high-level
 *	stream would not be able to cache the data eﬀectively.
 *
 *	struct iovec
 *	{
 *		void *iov_base;		//buffer的起始地址
 *		size_t	iov_len;	//buffer的大小
 *	}
 *
 *	 *	readv和writev类似于read和write，不过readv和writev允许单个系统调用读入
 *	 *	到或写出自一个或多个缓冲区。
 *	 *	这些操作分别为分散读 和 集中写 ，因为来自读操作的输入数据被分散
 *	 *	到多个应用缓冲区中，而来自多个应用缓冲区的输入数据则集中提供给单个写操作。
 */
#include <sys/uio.h>

