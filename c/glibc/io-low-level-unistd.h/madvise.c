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
/*	int madvise (void *addr, size t length, int advice) [Function]
 *	This function can be used to provide the system with advice about the intended usage
 *	patterns of the memory region starting at addr and extending length bytes.
 *	The valid BSD values for advice are:
 *	MADV_NORMAL
 *	The region should receive no further special treatment.
 *	MADV_RANDOM
 *	The region will be accessed via random page references. The kernel should
 *	page-in the minimal number of pages for each page fault.
 *	MADV_SEQUENTIAL
 *	The region will be accessed via sequential page references. This may
 *	cause the kernel to aggressively read-ahead, expecting further sequential
 *	references after any page fault within this region.
 *	MADV_WILLNEED
 *	The region will be needed. The pages within this region may be pre
 *	faulted in by the kernel.
 *	MADV_DONTNEED
 *	The region is no longer needed. The kernel may free these pages, causing
 *	any changes to the pages to be lost, as well as swapped out pages to be
 *	discarded.
 *	The POSIX names are slightly diﬀerent, but with the same meanings:
 *	POSIX_MADV_NORMAL
 *	This corresponds with BSD’s MADV_NORMAL.
 *	POSIX_MADV_RANDOM
 *	This corresponds with BSD’s MADV_RANDOM.
 *	POSIX_MADV_SEQUENTIAL
 *	This corresponds with BSD’s MADV_SEQUENTIAL.
 *	POSIX_MADV_WILLNEED
 *	This corresponds with BSD’s MADV_WILLNEED.
 *	POSIX_MADV_DONTNEED
 *	This corresponds with BSD’s MADV_DONTNEED.
 *	msync returns 0 for success and −1 for error. Errors include:
 *	EINVAL An invalid region was given, or the advice was invalid.
 *	EFAULT There is no existing mapping in at least part of the given region.
 */

#include <unistd.h>
#include <sys/mman.h>

int madvise(void *addr, size_t length, int advice);
