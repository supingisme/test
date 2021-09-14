/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:08 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:22 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:29 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:53 CST. */
/*
 *	6.52.5.4 Raw read/write Functions
 *	This sections describes built-in functions related to read and write instructions to access
 *	memory. These functions generate membar instructions to ﬂush the I/O load and stores
 *	where appropriate, as described in Fujitsu’s manual described above.
 *	unsigned char __builtin_read8 (void *data)
 *	unsigned short __builtin_read16 (void *data)
 *	unsigned long __builtin_read32 (void *data)
 *	unsigned long long __builtin_read64 (void *data)
 *	void __builtin_write8 (void *data, unsigned char datum)
 *	void __builtin_write16 (void *data, unsigned short datum)
 *	void __builtin_write32 (void *data, unsigned long datum)
 *	void __builtin_write64 (void *data, unsigned long long datum)
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned char ch = __builtin_read8("abc");

	printf("ch =%c\n", ch);

	return 0;
}
