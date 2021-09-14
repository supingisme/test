/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:06 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:21 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:28 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:06 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:45 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
#include <stdio.h>
#include <stdlib.h>

#ifndef __swapbyte64
#define __swapbyte64(l64) (((l64>>56)&0xff)      | ((l64&0xff)<<56) |\
				                  ((l64>>40)&0xff00)     | ((l64&0xff00)<<40) |\
				                  ((l64>>24)&0xff0000)   | ((l64&0xff0000)<<24) |\
				                  ((l64>> 8)&0xff000000) | ((l64&0xff000000)<<8))
#endif

int main()
{
	printf("%#2x\n", 1);
	printf("%lx -> %lx\n", 0x1234567890, __swapbyte64(0x1234567890));
	printf("%lx -> %lx\n", 274877906944, __swapbyte64(274877906944));
	printf("%lx -> %lx\n", 18446744073709551615, __swapbyte64(18446744073709551615));
	printf("%lx\n", 270582939648);
	printf("%lx\n", 403726925824);
	printf("%lx\n", 399431958528);
	printf("%lx\n", 390842023936);
	printf("%lx\n", 395136991232);

	printf("%lx -> %lx\n", 270544960, 12352);

}
