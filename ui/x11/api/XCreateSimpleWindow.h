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
 *	To create an unmapped InputOutput subwindow of a given parent window, use
 *	XCreateSimpleWindow.
 *	Window XCreateSimpleWindow( *display, parent, y, height,
 *	border_width, border, background);
 *	display Specifies the connection to the X server.
 *	parent Specifies the parent window. and are relative to the
 *	inside of the parent window's borders
 *	x y
 *	Specify the x and y coordinates(Xy. and do not include
 *	the created window's borders
 *	width
 *	height Specify the width and height(Wh. The dimensions
 *	must be nonzero, or a BadValue error results.
 *	border_width Specifies the width of the created window's border
 *	in pixels.
 *	border Specifies the border pixel value of the window.
 *	background Specifies the background pixel value of the window.
 */
