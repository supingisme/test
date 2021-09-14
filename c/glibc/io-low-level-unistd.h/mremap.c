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
/*	void * mremap (void *address, size t length, size t new_length, int [Function]
 *	flag)
 *	This function can be used to change the size of an existing memory area. address
 *	and length must cover a region entirely mapped in the same mmap statement. A new
 *	mapping with the same characteristics will be returned with the length new length.
 *	One option is possible, MREMAP_MAYMOVE. If it is given in ﬂags, the system may remove
 *	the existing mapping and create a new one of the desired length in another location.
 *	The address of the resulting mapping is returned, or −1. Possible error codes include:
 *	EFAULT There is no existing mapping in at least part of the original region, or the
 *	region covers two or more distinct mappings.
 *	EINVAL The address given is misaligned or inappropriate.
 *	EAGAIN The region has pages locked, and if extended it would exceed the process’s
 *	resource limit for locked pages. See Section 22.2 [Limiting Resource Us
 *	age], page 575.
 *	ENOMEM The region is private writable, and insufcient virtual memory is available
 *	to extend it. Also, this error will occur if MREMAP_MAYMOVE is not given
 *	and the extension would collide with another mapped region.
 */
#include <sys/mman.h>

int *mremap(void *addr, size_t length, size_t new_length, int flag);
