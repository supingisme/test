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
 *	17.4.1 Terminal Mode Data Types
 *	The entire collection of attributes of a terminal is stored in a structure of type struct
 *	termios. This structure is used with the functions tcgetattr and tcsetattr to read and
 *	set the attributes.
 *	struct termios [Data Type]
 *	Structure that records all the I/O attributes of a terminal. The structure includes at
 *	least the following members:
 *	tcflag_t c_iflag
 *	A bit mask specifying ﬂags for input modes; see Section 17.4.4 [Input
 *	Modes], page 438.
 *	tcflag_t c_oflag
 *	A bit mask specifying ﬂags for output modes; see Section 17.4.5 [Output
 *	Modes], page 440.
 *	tcflag_t c_cflag
 *	A bit mask specifying ﬂags for control modes; see Section 17.4.6 [Control
 *	Modes], page 440.
 *	tcflag_t c_lflag
 *	A bit mask specifying ﬂags for local modes; see Section 17.4.7 [Local
 *	Modes], page 442.
 *	cc_t c_cc[NCCS]
 *	An array specifying which characters are associated with various control
 *	functions; see Section 17.4.9 [Special Characters], page 446.
 *	The struct termios structure also contains members which encode input and output
 *	transmission speeds, but the representation is not specifed. See Section 17.4.8 [Line
 *	Speed], page 444, for how to examine and store the speed values.
 *	The following sections describe the details of the members of the struct termios struc
 *	ture.
 *	tcflag_t [Data Type]
 *	This is an unsigned integer type used to represent the various bit masks for terminal
 *	ﬂags.
 *	cc_t [Data Type]
 *	This is an unsigned integer type used to represent characters associated with various
 *	terminal control functions.
 *
 *	int NCCS [Macro]
 *	The value of this macro is the number of elements in the c_cc array.
 *
 */

#include <termios.h>

struct termios{
	tcflag_t c_iflag;
	tcflag_t c_oflag;
	tcflag_t c_cflag;
	tcflag_t c_lflag;
	cc_t c_cc[NCCS];
};
