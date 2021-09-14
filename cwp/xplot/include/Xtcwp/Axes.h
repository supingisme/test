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

/******************************************************************************
Axes.h:  Public header file for XtcwpAxes Widget
*******************************************************************************
Author:  Dave Hale, Colorado School of Mines, 08/28/90
******************************************************************************/

#ifndef AXES_H
#define AXES_H

/* WIDGET CLASS POINTER (WIDGET CLASS NAME IS "XtcwpAxes") */
extern WidgetClass xtcwpAxesWidgetClass;

/* RESOURCE STRINGS */
#define XtNgrid1 "grid1" /* "none", "dot", "dash" or "solid" */
#define XtNgrid2 "grid2" /*   grid lines for dimensions 1 and 2 */
#define XtNnTic1 "nTic1" /* number of tics per numbered tic */
#define XtNnTic2 "nTic2" /*   for dimensions 1 and 2 */
#define XtNlabel1 "label1" /* label for dimension 1 */
#define XtNlabel2 "label2" /* label for dimension 2 */
#define XtNtitle "title" /* axes title */
#define XtNstyle "style" /* "normal" or "seismic" */
#define XtNaxesColor "axesColor" /* name of color to use for axes */
#define XtNgridColor "gridColor" /* name of color to use for gridlines */
#define XtNtitleColor "titleColor" /* name of color to use for title */
#define XtNlabelFont "labelFont" /* name of font to use for labels */
#define XtNtitleFont "titleFont" /* name of font to use for title */
#define XtNresizeCallback "resizeCallback" /* called when axes resized */
#define XtNexposeCallback "exposeCallback" /* called before drawing axes */
#define XtNinputCallback "inputCallback" /* for input events */

/* CALLBACK STRUCTURE */
typedef struct {
	int reason; /* XtcwpCR_RESIZE, XtcwpCR_EXPOSE, or XtcwpCR_INPUT */
	XEvent *event; /* NULL for XtcwpCR_RESIZE */
	Region region; /* NULL for XtcwpCR_RESIZE and XtcwpCR_INPUT */
	int x,y,width,height; /* axes rectangle */
	float x1beg,x1end,x2beg,x2end; /* axes values */
	float p1beg,p1end,p2beg,p2end; /* axes pads */
	int style; /* axes style (either XtcwpNORMAL or XtcwpSEISMIC) */
} XtcwpAxesCallbackStruct;

/* POINTERS TO CLASS AND INSTANCE RECORDS */
typedef struct _XtcwpAxesClassRec *XtcwpAxesWidgetClass;
typedef struct _XtcwpAxesRec *XtcwpAxesWidget;


/* PUBLIC FUNCTIONS */

Boolean XtcwpPointInAxesRectangle (Widget w, Position x, Position y);
/*****************************************************************************
returns TRUE if point is inside axes rectangle, otherwise FALSE
******************************************************************************
Input:
w		axes widget
x		x coordinate of point
y		y coordinate of point
******************************************************************************
Notes:
This function is useful for determining whether or not input events
occured with the pointer inside the axes rectangle.  I.e., the input
callback function will typically call this function.
*****************************************************************************/

void XtcwpSetAxesValues (Widget w,
	float x1beg, float x1end, float x2beg, float x2end);
/*****************************************************************************
set axes values
******************************************************************************
Input:
w		axes widget
x1beg		axis value at beginning of axis 1
x1end		axis value at end of axis 1
x2beg		axis value at beginning of axis 2
x2end		axis value at end of axis 2
*****************************************************************************/

void XtcwpSetAxesPads (Widget w,
	float p1beg, float p1end, float p2beg, float p2end);
/*****************************************************************************
set axes pads
******************************************************************************
Input:
w		axes widget
p1beg		axis pad at beginning of axis 1
p1end		axis pad at end of axis 1
p2beg		axis pad at beginning of axis 2
p2end		axis pad at end of axis 2
******************************************************************************
Notes:
Pad values must be specified in the same units as the corresponding 
axes values.  These pads are useful when the contents of the axes box
require more space than implied by the axes values.  For example, the
first and last seismic wiggle traces plotted inside an axes box
will typically extend beyond the axes values corresponding to the
first and last traces.  However, all tics will lie within the limits
specified in the axes values (x1beg, x1end, x2beg, and x2end).
*****************************************************************************/

#endif /* AXES_H */
