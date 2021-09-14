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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
/* Drawing Function Wrapper */
#ifndef DRAW_LIB_H
#define DRAW_LIB_H

/* Struct defintion for LuxDraw Window parameters */
struct LXwindow {
	int height;			/* Height */
	int width;			/* Width */
	int xpos;			/* X Position */
	int ypos;			/* Y position */
	int border;			/* Border width */
	unsigned long bdc;	/* Border Color */
	unsigned long bgc;	/* Background Color */
	unsigned long fgc;	/* Foreground Color */
} LXwindow;

/* Struct for QuickDraw Root Window*/

/* Struct for QuickDraw Text Parameters*/
struct LXtext {
	const char* text;	/* Actual Text */
	const char* font;	/* Font Name */
	const char* color;	/* Color of Text */
	unsigned int pt;	/* Point Size */
	int len;			/* String Length */
	int xpos;			/* X Position */
	int ypos;			/* Y Position */

} LXtext;

/* LuxDraw object */
typedef struct LXobject {

} LXobject;

/* Objects to draw in window */
LXObject* visibleObjects;

/* Function Definitions */

/* Sets up environment */
int initQuickDraw( Display** disp, int* screen, Window* win, XEvent* event);

/*Creates Root Window */
int initRootWindow( LXWindow* rwin );

#endif	/* DRAW_LIB_H */
