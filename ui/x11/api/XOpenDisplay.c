/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:54 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:16 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:26 CST. */
/*
 *	If successful, XOpenDisplay returns a pointer to a Display structure, which is de
 *	fined in <X11/Xlib.h>. If XOpenDisplay does not succeed, it returns NULL. After
 *	a successful call to XOpenDisplay, all of the screens in the display can be used by
 *	the client. The screen number specified in the display_name argument is returned
 *	by the DefaultScreen macro (or the XDefaultScreen function). You can access ele
 *	ments of the Display and Screen structures only by using the information macros or
 *	functions. For information about using macros and functions to obtain information
 *	from the Display structure, see section 2.2.1.
 *	
 */
//./Xlib.h:1483:extern Display *XOpenDisplay(
//./Xlib.h-1484-    _Xconst char*	/* display_name */
//./Xlib.h-1485-);

#include <X11/Xlib.h>
