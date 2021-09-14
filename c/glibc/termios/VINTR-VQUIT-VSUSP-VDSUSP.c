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
17.4.9.2 Characters that Cause Signals
These special characters may be active in either canonical or noncanonical input mode, but
only when the ISIG ﬂag is set (see Section 17.4.7 [Local Modes], page 442).
int VINTR [Macro]
This is the subscript for the INTR character in the special control character array.
termios.c_cc[VINTR] holds the character itself.
The INTR (interrupt) character raises a SIGINT signal for all processes in the fore
ground job associated with the terminal. The INTR character itself is then discarded.
See Chapter 24 [Signal Handling], page 602, for more information about signals.
Typically, the INTR character is C-c.
int VQUIT [Macro]
This is the subscript for the QUIT character in the special control character array.
termios.c_cc[VQUIT] holds the character itself.
The QUIT character raises a SIGQUIT signal for all processes in the foreground job
associated with the terminal. The QUIT character itself is then discarded. See
Chapter 24 [Signal Handling], page 602, for more information about signals.
Typically, the QUIT character is C-\.
int VSUSP [Macro]
This is the subscript for the SUSP character in the special control character array.
termios.c_cc[VSUSP] holds the character itself.
The SUSP (suspend) character is recognized only if the implementation supports job
control (see Chapter 27 [Job Control], page 699). It causes a SIGTSTP signal to be
sent to all processes in the foreground job associated with the terminal. The SUSP
character itself is then discarded. See Chapter 24 [Signal Handling], page 602, for
more information about signals.
Typically, the SUSP character is C-z.
Few applications disable the normal interpretation of the SUSP character. If your pro
gram does this, it should provide some other mechanism for the user to stop the job. When
the user invokes this mechanism, the program should send a SIGTSTP signal to the process
group of the process, not just to the process itself. See Section 24.6.2 [Signaling Another
Process], page 630.
int VDSUSP [Macro]
This is the subscript for the DSUSP character in the special control character array.
termios.c_cc[VDSUSP] holds the character itself.
The DSUSP (suspend) character is recognized only if the implementation supports
job control (see Chapter 27 [Job Control], page 699). It sends a SIGTSTP signal,
like the SUSP character, but not right away—only when the program tries to read
it as input. Not all systems with job control support DSUSP; only BSD-compatible
systems (including the GNU system).
See Chapter 24 [Signal Handling], page 602, for more information about signals.
Typically, the DSUSP character is C-y.



 */

#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

	tcgetattr(fileno(stdout), &t);

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
