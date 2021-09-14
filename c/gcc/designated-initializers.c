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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:52 CST. */
/*
 *	6.25 Designated Initializers
 *	Standard C90 requires the elements of an initializer to appear in a fxed order, the same as
 *	the order of the elements in the array or structure being initialized.
 *	In ISO C99 you can give the elements in any order, specifying the array indices or structure
 *	feld names they apply to, and GNU C allows this as an extension in C90 mode as well.
 *	This extension is not implemented in GNU C++.
 *	To specify an array index, write ‘[index] =’ before the element value. For example,
 */

#include <stdio.h>

int a1[6] = { [4] = 29, [2] = 15 };
//is equivalent to
int a2[6] = { 0, 0, 15, 0, 29, 0 };

int widths[] = { [0 ... 9] = 1, [10 ... 99] = 2, [100] = 3 };

struct point { int x, y; };
struct point p1 = { .y = yvalue, .x = xvalue };
struct point p2 = { xvalue, yvalue };
struct point p3 = { y: yvalue, x: xvalue };

int main()
{

}
