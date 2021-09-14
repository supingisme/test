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
 *	void exit (int status) [Function]
 *	The exit function tells the system that the program is done, which causes it to
 *	terminate the process.
 *	status is the program’s exit status, which becomes part of the process’ termination
 *	status. This function does not return.
 *	Normal termination causes the following actions:
 *	1. Functions that were registered with the atexit or on_exit functions are called in the
 *	reverse order of their registration. This mechanism allows your application to specify
 *	its own “cleanup” actions to be performed at program termination. Typically, this is
 *	used to do things like saving program state information in a fle, or unlocking locks in
 *	shared data bases.
 *	2. All open streams are closed, writing out any buﬀered output data. See Section 12.4
 *	[Closing Streams], page 230. In addition, temporary fles opened with the tmpfile
 *	function are removed; see Section 14.11 [Temporary Files], page 380.
 *	3. _exit is called, terminating the program. See Section 25.6.5 [Termination Internals],
 *	page 687.
 *
 *
 *	int EXIT_SUCCESS [Macro]
 *	This macro can be used with the exit function to indicate successful program com
 *	pletion.
 *	On POSIX systems, the value of this macro is 0. On other systems, the value might
 *	be some other (possibly non-constant) integer expression.
 *	int EXIT_FAILURE [Macro]
 *	This macro can be used with the exit function to indicate unsuccessful program
 *	completion in a general sense.
 *	On POSIX systems, the value of this macro is 1. On other systems, the value might be
 *	some other (possibly non-constant) integer expression. Other nonzero status values
 *	also indicate failures. Certain programs use diﬀerent nonzero status values to indicate
 *	particular kinds of "non-success". For example, diff uses status value 1 to mean that
 *	the fles are diﬀerent, and 2 or more to mean that there was difculty in opening the
 *	fles.
 */

#include <stdlib.h>


