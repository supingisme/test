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
 *	XDestroyWindow( *display, w);
 *	display Specifies the connection to the X server.
 *	w Specifies the window.
 *	The XDestroyWindow function destroys the specified window as well as all of its
 *	subwindows and causes the X server to generate a DestroyNotify event for each
 *	window. The window should never be referenced again. If the window specified by
 *	the w argument is mapped, it is unmapped automatically. The ordering of the De
 *	stroyNotify events is such that for any given window being destroyed, DestroyNotify
 *	is generated on any inferiors of the window before being generated on the window
 *	itself. The ordering among siblings and across subhierarchies is not otherwise con
 *	strained. If the window you specified is a root window, no windows are destroyed.
 *	Destroying a mapped window will generate Expose events on other windows that
 *	were obscured by the window being destroyed.
 *	XDestroyWindow can generate a BadWindow error.
 */
