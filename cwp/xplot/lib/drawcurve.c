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

/* DRAWCURVE: $Revision: 1.4 $ ; $Date: 2011/11/21 17:02:44 $	*/

/*********************** self documentation **********************/
/*****************************************************************************
DRAWCURVE - Functions to draw a curve from a set of points

xDrawCurve	draw a curve from a set of points
*****************************************************************************
Function Prototypes:
void xDrawCurve(Display *dpy, Window win,
		int x, int y, int width, int height,
		float x1beg, float x1end, float p1beg, float p1end,
		float x2beg, float x2end, float p2beg, float p2end,
		float *x1curve, float *x2curve, int ncurve,
		char *curvecolor, int style);
*****************************************************************************
xDrawCurve:
Input:
dpy		display pointer
win		window
x		x coordinate of upper left corner of box
y		y coordinate of upper left corner of box
width		width of box
height		height of box
x1beg		axis value at beginning of axis 1
x1end		axis value at end of axis 1
p1beg		pad value at beginning of axis 1
p1end		pad value at end of axis 1
x2beg		axis value at beginning of axis 2
x2end		axis value at end of axis 2
p2beg		pad value at beginning of axis 2
p2end		pad value at end of axis 2
x1curve		vector of x1 coordinates for points along curve
x2curve		vector of x2 coordinates for points along curve
ncurve		number of points along curve
curvecolor	name of color to use for axes
int style	NORMAL (axis 1 on bottom, axis 2 on left)
		SEISMIC (axis 1 on left, axis 2 on top)

******************************************************************************
Author:		Brian Macy, Phillips Petroleum Co., 11/14/98
		(Adapted after Dave Hale's xDrawAxesBox routine)
*****************************************************************************/
/**************** end self doc ********************************/

#include "xplot.h"

void xDrawCurve(Display *dpy, Window win,
		int x, int y, int width, int height,
		float x1beg, float x1end, float p1beg, float p1end,
		float x2beg, float x2end, float p2beg, float p2end,
		float *x1curve, float *x2curve, int ncurve,
		char *curvecolor, int curvewidth, int style)
/*****************************************************************************
draw a curve from a set of points
******************************************************************************
Input:
dpy		display pointer
win		window
x		x coordinate of upper left corner of box
y		y coordinate of upper left corner of box
width		width of box
height		height of box
x1beg		axis value at beginning of axis 1
x1end		axis value at end of axis 1
p1beg		pad value at beginning of axis 1
p1end		pad value at end of axis 1
x2beg		axis value at beginning of axis 2
x2end		axis value at end of axis 2
p2beg		pad value at beginning of axis 2
p2end		pad value at end of axis 2
x1curve		vector of x1 coordinates for points along curve
x2curve		vector of x2 coordinates for points along curve
ncurve		number of points along curve
curvecolor	name of color to use for axes
curvewidth	width of curve in pixels
int style	NORMAL (axis 1 on bottom, axis 2 on left)
		SEISMIC (axis 1 on left, axis 2 on top)
******************************************************************************
Author:		Brian Macy, Phillips Petroleum Co., 11/14/98
		(Adapted after Dave Hale's xDrawAxesBox routine)
*****************************************************************************/
{
	GC gcc;
	XGCValues *values=NULL;
	XColor scolor,ecolor;
	XWindowAttributes wa;
	Colormap cmap;
	float xbase,ybase,xscale,yscale;
	float *xcurve,*ycurve;
	XPoint *lpoints;   /* points for drawing line */
	XRectangle rectclip;
	int i;

	/* allocate memory for lpoints */
	if ((lpoints=(XPoint *)malloc(ncurve*sizeof(XPoint)))==NULL) {
		fprintf(stderr,"Cannot allocate memory for lpoints\n");
		exit(-1);
	}

	/* create graphics contexts */
	gcc = XCreateGC(dpy,win,0,values);
	XGCValues line_style;
	line_style.line_width = curvewidth;
	XChangeGC(dpy, gcc, GCLineWidth, &line_style);

	/* determine window's current colormap */
	XGetWindowAttributes(dpy,win,&wa);
	cmap = wa.colormap;

	/* get and set colors */
	if (XAllocNamedColor(dpy,cmap,curvecolor,&scolor,&ecolor))
		XSetForeground(dpy,gcc,ecolor.pixel);
	else
		XSetForeground(dpy,gcc,1L);

	if (style==NORMAL) {
		xscale = width/(x1end+p1end-x1beg-p1beg);
		xbase = x-xscale*(x1beg+p1beg);
		yscale = -height/(x2end+p2end-x2beg-p2beg);
		ybase = y+height-yscale*(x2beg+p2beg);
		xcurve=x1curve;
		ycurve=x2curve;
	} else {
		xscale = width/(x2end+p2end-x2beg-p2beg);
		xbase = x-xscale*(x2beg+p2beg);
		yscale = height/(x1end+p1end-x1beg-p1beg);
		ybase = y-yscale*(x1beg+p1beg);
		ycurve=x1curve;
		xcurve=x2curve;
	}

	/* Set up clip rectangle (only allows drawing inside rect.) */
	rectclip.x = (short) x;
	rectclip.y = (short) y;
	rectclip.width  = (unsigned short) width;
	rectclip.height = (unsigned short) height;
	XSetClipRectangles(dpy,gcc,0,0,&rectclip,1,Unsorted);

	/*
	 * Draw a curve from the input data xcurve,ycurve.
	 */
	for (i=0; i<ncurve; ++i) {
		lpoints[i].x=(short) (xbase+xscale*xcurve[i]);
		lpoints[i].y=(short) (ybase+yscale*ycurve[i]);
	}
	if (ncurve==1)
		XDrawPoints(dpy,win,gcc,lpoints,ncurve,CoordModeOrigin);
	else if (ncurve > 1)
		XDrawLines(dpy,win,gcc,lpoints,ncurve,CoordModeOrigin);

	/* free resources before returning */
	XFreeGC(dpy,gcc);
	free(lpoints);
}
