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
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:27 CST. */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define NIL (0)

#define debug() printf("LINE: %d-\n", __LINE__)

int main()
{
	Display *dpy = XOpenDisplay(NULL);

	if(dpy != NULL)
	{
		/*black and white color*/
		unsigned int blackcolor =  BlackPixel(dpy, DefaultScreen(dpy));
		unsigned int whitecolor =  WhitePixel(dpy, DefaultScreen(dpy));
        
        XVisualInfo info;
        
        /*get the visual info*/
        XMatchVisualInfo(dpy, DefaultScreen(dpy), 32, TrueColor, &info);
        XSetWindowAttributes attrs;
        debug();
        /*set attributes*/
        //段错误(吐核)///////////////////////////////////////////////
        attrs.colormap = XCreateColormap(dpy, DefaultRootWindow(dpy), 
                                        info.visual, AllocNone);debug();
        attrs.border_pixel = blackcolor;debug();
        attrs.background_pixel = whitecolor;
        debug();
        
		/*create window*/
		Window w = XCreateWindow(dpy, DefaultRootWindow(dpy),
						0,0,200,200,0,info.depth, InputOutput, info.visual,
                        CWColormap|CWBorderPixel|CWBackPixel, &attrs);
        debug();
		/*map window*/
		XMapWindow(dpy, w);

        /*select which event to respond to*/
        XSelectInput(dpy, w, ExposureMask|KeyPressMask);
        
		/*flush*/
		XFlush(dpy);
        
        XEvent ev;
        
        for(;;)
        {
            XNextEvent(dpy, &ev);
            if(ev.xany.window == w)
            {
                switch(ev.type)
                {
                    case Expose:
                    {
                        /*fill a black rectangle of 100*100 at (10,10)*/
                        GC gc = XCreateGC(dpy, w, 0, NIL);
                        XSetForeground(dpy, gc, blackcolor);
                        XFillRectangle(dpy, w, gc, 10, 10, 100, 100);
                        /*xflush unnecessary, as XNextEvent do the flush*/
                        break;
                    }
                    case KeyPress:
                    {
                        printf("%s\n", "bye");
                        XDestroyWindow(dpy, w);
                        XCloseDisplay(dpy);
                        return 0;
                        break;
                    }
                }
            }
        }
    }
	return 0;
}
