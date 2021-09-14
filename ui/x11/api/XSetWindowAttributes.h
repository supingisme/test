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
/* Window attribute value mask bits */
/* Window attribute value mask bits */
#define CWBackPixmap (1L<<0)
#define CWBackPixel (1L<<1)
#define CWBorderPixmap (1L<<2)
#define CWBorderPixel (1L<<3)
#define CWBitGravity (1L<<4)
#define CWWinGravity (1L<<5)
#define CWBackingStore (1L<<6)
#define CWBackingPlanes (1L<<7)
#define CWBackingPixel (1L<<8)
#define CWOverrideRedirect (1L<<9)
#define CWSaveUnder (1L<<10)
#define CWEventMask (1L<<11)
#define CWDontPropagate (1L<<12)
#define CWColormap (1L<<13)
#define CWCursor (1L<<14)

/* Values */
typedef struct {
	Pixmap background_pixmap; /* background, None, or ParentRelative */
	unsigned long background_pixel; /* background pixel */
	Pixmap border_pixmap; /* border of the window or CopyFromParent */
	unsigned long border_pixel; /* border pixel value */
	int bit_gravity; /* one of bit gravity values */
	int win_gravity; /* one of the window gravity values */
	int backing_store; /* NotUseful, WhenMapped, Always */
	unsigned long backing_planes; /* planes to be preserved if possible */
	unsigned long backing_pixel; /* value to use in restoring planes */
	Bool save_under; /* should bits under be saved? (popups) */
	long event_mask; /* set of events that should be saved */
	long do_not_propagate_mask; /* set of events that should not propagate */
	Bool override_redirect; /* boolean value for override_redirect */
	Colormap colormap; /* color map to be associated with window */
	Cursor cursor; /* cursor to be displayed (or None) */
} XSetWindowAttributes;
