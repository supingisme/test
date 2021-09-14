/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:51 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:35 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

#ifndef _PICKING_H
#define _PICKING_H
#ifndef EGSTERN
#define EGSTERN extern
#endif

#define COLOR_FLAGS DoRed | DoGreen | DoBlue
#define COMMAND_WIDTH 100
#define BUTTON_HEIGHT 30
#define BUTTON_WIDTH  90
#define BUTTON_BRIGHTNESS 60000
#define FONT_NAME "9x15"
#define PICK_MODE 1
#define REGULAR_MODE 0
#define ADD_MODE 1
#define DELETE_MODE 0
#define DRAW_FLAG 1
#define ERASE_FLAG 0

EGSTERN int char_width, char_height;
EGSTERN XColor grey_color, black_color,red_color,blue_color;
EGSTERN unsigned long grey_pixel,black_pixel,red_pixel,blue_pixel;
EGSTERN GC blue_r_gc;
EGSTERN GC red_r_gc;

typedef struct pick_tag {
  float x2;
  float time;
  int picked;
} pick_t;

#endif /* end PICKING */
