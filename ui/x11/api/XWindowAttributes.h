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
typedef struct {
	int x, y; /* location of window */
	int width, height; /* width and height of window */
	int border_width; /* border width of window */
	int depth; /* depth of window */
	Visual *visual; /* the associated visual structure */
	Window root; /* root of screen containing window */
	int class; /* InputOutput, InputOnly*/
	int bit_gravity; /* one of the bit gravity values */
	int win_gravity; /* one of the window gravity values */
	int backing_store; /* NotUseful, WhenMapped, Always */
	unsigned long backing_planes; /* planes to be preserved if possible */
	unsigned long backing_pixel; /* value to be used when restoring planes */
	Bool save_under; /* boolean, should bits under be saved? */
	Colormap colormap; /* color map to be associated with window */
	Bool map_installed; /* boolean, is color map currently installed*/
	int map_state; /* IsUnmapped, IsUnviewable, IsViewable */
	long all_event_masks; /* set of events all people have interest in*/
	long your_event_mask; /* my event mask */
	long do_not_propagate_mask; /* set of events that should not propagate */
	Bool override_redirect; /* boolean value for override-redirect */
	Screen *screen; /* back pointer to correct screen */
} XWindowAttributes;
