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
/*	int msync (void *address, size t length, int flags) [Function]
 *	When using shared mappings, the kernel can write the fle at any time before the
 *	mapping is removed. To be certain data has actually been written to the fle and will
 *	be accessible to non-memory-mapped I/O, it is necessary to use this function.
 *	It operates on the region address to (address + length). It may be used on part of
 *	a mapping or multiple mappings, however the region given should not contain any
 *	unmapped space.
 *	ﬂags can contain some options:
 *	MS_SYNC
 *	This ﬂag makes sure the data is actually written to disk. Normally msync
 *	only makes sure that accesses to a fle with conventional I/O reﬂect the
 *	recent changes.
 *	MS_ASYNC
 *	This tells msync to begin the synchronization, but not to wait for it to
 *	complete.
 *	msync returns 0 for success and −1 for error. Errors include:
 *	EINVAL An invalid region was given, or the ﬂags were invalid.
 *	EFAULT There is no existing mapping in at least part of the given region.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int msync(void *addr, size_t length, int flags);

int main()
{
	

	return 0;
}
