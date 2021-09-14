/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:53 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:52 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:36 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:09 CST. */
#include <stdio.h>
#include "par.h"
#include "xplot.h"
#include <X11/Xatom.h>
#include <X11/keysym.h>

#define X 100
#define Y 100

#define WIDTH 256
#define HEIGHT 64

main()
{
	Display *dpy;
	Window root,win;
	Colormap cmap;
	XStandardColormap scmap;
	XColor color,junk;
	XImage *image;
	XEvent event;
	GC gc;
	int scr,i;
	unsigned long black,white,pmin,pmax;
	char *data;
	
	/* connect to X server */
	dpy = XOpenDisplay(NULL);
	if ((dpy=XOpenDisplay(NULL))==NULL) {
		fprintf(stderr,"Cannot open display!\n");
		exit(-1);
	}
	scr = DefaultScreen(dpy);
	root = RootWindow(dpy,scr);
	black = BlackPixel(dpy,scr);
	white = WhitePixel(dpy,scr);
	
	/* create and map window */
	win = XCreateSimpleWindow(dpy,root,X,Y,WIDTH,HEIGHT,4,black,white);
	cmap = xCreateRGBColormap(dpy,win, "rgb0", 1);
	XSetWindowColormap(dpy,win,cmap);
	XMapWindow(dpy,win);
	
	/* determine range of contiguous pixels from standard colormap */
	if (!xCreateRGBDefaultMap(dpy,&scmap)) {
		fprintf(stderr,"Cannot create standard colormap!\n");
		exit(-1);
	}
	pmin = xGetFirstPixel(dpy);
	pmax = xGetLastPixel(dpy);
	
	/* create image */
	data = (char*)malloc(WIDTH*HEIGHT);
	for (i=0; i<WIDTH*HEIGHT; ++i)
		data[i] = pmin+(pmax-pmin)*(i%WIDTH)/WIDTH;
	image = XCreateImage(dpy,DefaultVisual(dpy,scr),
		DefaultDepth(dpy,scr),ZPixmap,
		0,data,WIDTH,HEIGHT,BitmapPad(dpy),WIDTH);
	gc = XCreateGC(dpy,win,0,NULL);
	XAllocNamedColor(dpy,cmap,"red",&color,&junk);
	XSetForeground(dpy,gc,color.pixel);
	
	/* set event mask */
	XSelectInput(dpy,win,ExposureMask);

	/* loop forever */
	XPutImage(dpy,win,gc,image,0,0,0,0,WIDTH,HEIGHT);
	while(True) {
		XNextEvent(dpy,&event);
		while (XCheckTypedEvent(dpy,Expose,&event));
		XPutImage(dpy,win,gc,image,0,0,0,0,WIDTH,HEIGHT);
		XDrawLine(dpy,win,gc,0,0,WIDTH,HEIGHT);
	}

	/* close display */
	XCloseDisplay(dpy);
}