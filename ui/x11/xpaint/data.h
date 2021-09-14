/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:55 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:17 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:58 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
#ifndef _DATA_H_
#define _DATA_H_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>

#define VERSION "0.02"
#define WINDOW_WIDTH	300
#define WINDOW_HEIGHT	200
#define BACKGROUND_COLOR	"White"
#define FOREGROUND_COLOR	"Black"

#define BUTTON_AMOUNT	5
#define BUTTON_WIDTH	20
#define BUTTON_HEIGHT	20
#define BUTTON_DIST	3//distance of buttons

#define LINE_SIZE	1

typedef enum _bt_type{COLOR, SHAPE, EXIT, CHANGE_GC}bt_type;
typedef enum _bt_shape_id{NONE, LINE, RECTANGLE, ELIPSE}bt_shape_id;
typedef struct _bt_mode{
	bt_shape_id shape_id;
	char color[32];
}bt_mode;

typedef struct _button{
	int x, y;
	bt_type type;
	bt_mode mode;
}button;

unsigned long int get_color(const char *color_name);
GC change_color(const char *fg, const char *bg);
GC draw_main(char *bg);
void init_main_window(char *bg);
int ev_loop();

void draw_button(button *bt);
int mouse_event(bt_shape_id *shape, int x, int y, GC *gc);

#endif /*<_DATA_H_>*/
