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
Portability note: On some systems, the MIN and TIME slots are actually the same as
the EOF and EOL slots. This causes no serious problem because the MIN and TIME slots
are used only in noncanonical input and the EOF and EOL slots are used only in canonical
input, but it isn’t very clean. The GNU library allocates separate slots for these uses.
void cfmakeraw (struct termios *termios-p) [Function]
This function provides an easy way to set up *termios-p for what has traditionally
been called “raw mode” in BSD. This uses noncanonical input, and turns oﬀ most
processing to give an unmodifed channel to the terminal.
It does exactly this:
        termios-p->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP
                                |INLCR|IGNCR|ICRNL|IXON);
        termios-p->c_oflag &= ~OPOST;
        termios-p->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
        termios-p->c_cflag &= ~(CSIZE|PARENB);
        termios-p->c_cflag |= CS8;

 */

#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

	cfmakeraw(&t);

    printf("%2d:%4d:%c\n", VLNEXT, t.c_cc[VLNEXT], (char)t.c_cc[VLNEXT]);
	printf("%2d:%4d:%c\n", VDISCARD, t.c_cc[VDISCARD], (char)t.c_cc[VDISCARD]);
	//printf("%2d:%4d:%c\n", VSTATUS, t.c_cc[VSTATUS], (char)t.c_cc[VSTATUS]);
    
    
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
