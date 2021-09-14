/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:07 CST. */
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
/*
 *	6.57 Binary constants using the ‘0b’ prefx
 *	Integer constants can be written as binary constants, consisting of a sequence of ‘0’ and ‘1’
 *	digits, prefxed by ‘0b’ or ‘0B’. This is particularly useful in environments that operate a
 *	lot on the bit-level (like microcontrollers).
 *	The following statements are identical:
 *	i = 42;
 *	i = 0x2a;
 *	i = 052;
 *	i = 0b101010;
 *	The type of these constants follows the same rules as for octal or hexadecimal integer
 *	constants, so sufxes like ‘L’ or ‘UL’ can be applied.
 */

#include <stdio.h>

int main()
{
	printf("%d\n", 0b00101);
}
