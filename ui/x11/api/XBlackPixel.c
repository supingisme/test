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
 *	Applications should not directly modify any part of the Display and Screen struc
 *	tures. The members should be considered read-only, although they may change as
 *	the result of other operations on the display.
 *	The following lists the C language macros, their corresponding function equivalents
 *	that are for other language bindings, and what data both can return.
 *	AllPlanes()
 *	XAllPlanes()
 *	Both return a value with all bits set to 1 suitable for use in a plane argument to
 *	a procedure.
 *	Both BlackPixel and WhitePixel can be used in implementing a monochrome ap
 *	plication. These pixel values are for permanently allocated entries in the default col
 *	ormap. The actual RGB (red, green, and blue) values are settable on some screens
 *	and, in any case, may not actually be black or white. The names are intended to
 *	convey the expected relative intensity of the colors.
 *	BlackPixel(display, screen_number)
 */
//Xlib.h:1789:extern unsigned long XBlackPixel(
//Xlib.h-1790-    Display*		/* display */,
//Xlib.h-1791-    int			/* screen_number */
//Xlib.h-1792-);

#include <X11/Xlib.h>

unsigned long XBlackPixel(Display *display, int screen_number);
