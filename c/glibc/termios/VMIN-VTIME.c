/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/**

int VMIN [Macro]
This is the subscript for the MIN slot in the c_cc array. Thus, termios.c_cc[VMIN]
is the value itself.
The MIN slot is only meaningful in noncanonical input mode; it specifes the minimum
number of bytes that must be available in the input queue in order for read to return.
int VTIME [Macro]
This is the subscript for the TIME slot in the c_cc array. Thus, termios.c_
cc[VTIME] is the value itself.
The TIME slot is only meaningful in noncanonical input mode; it specifes how long
to wait for input before returning, in units of 0.1 seconds.

 */

#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

	tcgetattr(fileno(stdout), &t);

    printf("%2d:%4d:%c\n", VMIN, t.c_cc[VMIN], (char)t.c_cc[VMIN]);
	printf("%2d:%4d:%c\n", VTIME, t.c_cc[VTIME], (char)t.c_cc[VTIME]);

    
	return 0;
}
