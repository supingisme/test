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

17.4.9.3 Special Characters for Flow Control
These special characters may be active in either canonical or noncanonical input mode,
but their use is controlled by the ﬂags IXON and IXOFF (see Section 17.4.4 [Input Modes],
page 438).
int VSTART [Macro]
This is the subscript for the START character in the special control character array.
termios.c_cc[VSTART] holds the character itself.
The START character is used to support the IXON and IXOFF input modes. If IXON is
set, receiving a START character resumes suspended output; the START character
itself is discarded. If IXANY is set, receiving any character at all resumes suspended
output; the resuming character is not discarded unless it is the START character.
IXOFF is set, the system may also transmit START characters to the terminal.
The usual value for the START character is C-q. You may not be able to change this
value—the hardware may insist on using C-q regardless of what you specify.
int VSTOP [Macro]
This is the subscript for the STOP character in the special control character array.
termios.c_cc[VSTOP] holds the character itself.
The STOP character is used to support the IXON and IXOFF input modes. If IXON is
set, receiving a STOP character causes output to be suspended; the STOP character
itself is discarded. If IXOFF is set, the system may also transmit STOP characters to
the terminal, to prevent the input queue from overﬂowing.
The usual value for the STOP character is C-s. You may not be able to change this
value—the hardware may insist on using C-s regardless of what you specify.

 */

#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

	tcgetattr(fileno(stdout), &t);

    
	printf("%2d:%4d:%c\n", VSTART, t.c_cc[VSTART], (char)t.c_cc[VSTART]);
	printf("%2d:%4d:%c\n", VSTOP, t.c_cc[VSTOP], (char)t.c_cc[VSTOP]);
    
	printf("%2d:%4d:%c\n", VINTR, t.c_cc[VINTR], (char)t.c_cc[VINTR]);
	printf("%2d:%4d:%c\n", VQUIT, t.c_cc[VQUIT], (char)t.c_cc[VQUIT]);
	printf("%2d:%4d:%c\n", VSUSP, t.c_cc[VSUSP], (char)t.c_cc[VSUSP]);
	//printf("%2d:%4d:%c\n", VDSUSP, t.c_cc[VDSUSP], (char)t.c_cc[VDSUSP]);

    printf("%2d:%4d:%c\n", VEOF, t.c_cc[VEOF], (char)t.c_cc[VEOF]);
	printf("%2d:%4d:%c\n", VEOL, t.c_cc[VEOL], (char)t.c_cc[VEOL]);
	printf("%2d:%4d:%c\n", VEOL2, t.c_cc[VEOL2], (char)t.c_cc[VEOL2]);
	printf("%2d:%4d:%c\n", VERASE, t.c_cc[VERASE], (char)t.c_cc[VERASE]);
	printf("%2d:%4d:%c\n", VWERASE, t.c_cc[VWERASE], (char)t.c_cc[VWERASE]);
	printf("%2d:%4d:%c\n", VKILL, t.c_cc[VKILL], (char)t.c_cc[VKILL]);
	printf("%2d:%4d:%c\n", VREPRINT, t.c_cc[VREPRINT], (char)t.c_cc[VREPRINT]);
    
	return 0;
}
