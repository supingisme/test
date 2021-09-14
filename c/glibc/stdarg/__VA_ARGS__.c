/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:24 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:30 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:01 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:14 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:52 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:58 CST. */
/*
 *	6.19 Macros with a Variable Number of Arguments.
 *	In the ISO C standard of 1999, a macro can be declared to accept a variable number of
 *	arguments much as a function can. The syntax for defning the macro is similar to that of
 *	a function. Here is an example:
 */

#define debug1(format, ...) fprintf (stderr, format, __VA_ARGS__)
#define debug2(format, args...) fprintf (stderr, format, args)
#define debug3(format, ...) fprintf (stderr, format, ## __VA_ARGS__)
#define debug4(format, alrID, ...) fprintf(stderr, format, ## __VA_ARGS__)
#include <stdio.h>

int main()
{
	debug3("%s\n", "hello world!");
	debug4("debug4i%d\n", 12, 23);
	debug3("adsfadf\n");


}
