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
#include <X11/Xatom.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>

#define NIL (0)

#define debug() printf("LINE: %d-\n", __LINE__)

Display *dpy;
int screen;
Window root;
uint32_t blackcolor;
uint32_t whitecolor;
XVisualInfo info;
XSetWindowAttributes attrs;

Window createWindow(Window parent, int x, int y, 
                    int width, int height, uint32_t background)
{
    XMatchVisualInfo(dpy, screen, 32, TrueColor, &info);
    attrs.colormap = XCreateColormap(dpy, parent, info.visual, AllocNone);
    attrs.border_pixel = 0;
    attrs.background_pixel = background;
    
    Window w = XCreateWindow(dpy, parent, x, y, width, height, 0, info.depth,
                             InputOutput, info.visual, CWColormap|CWBorderPixel,
                             &attrs);
    return w;
}

int main()
{
    dpy = XOpenDisplay(NULL);
    
    if(dpy != NULL)
    {
        root = DefaultRootWindow(dpy);
        screen = DefaultScreen(dpy);
        
        blackcolor = BlackPixel(dpy, screen);
        whitecolor = WhitePixel(dpy, screen);
        
        Window parent = createWindow(root, 0,0,400,400,0);
        Window child = createWindow(parent, 0,0,100,100, whitecolor);
        
        XMapWindow(dpy, parent);
        XMapWindow(dpy, child);
        
        XFlush(dpy);
        /*select which event to respond to*/
        XSelectInput(dpy, parent, ExposureMask|KeyPressMask);
        
        XEvent ev;
        for(;;)
        {
            XNextEvent(dpy, &ev);
            if(ev.xany.window == parent)
            {
                switch(ev.type)
                {
                    case KeyPress:
                    {
                        printf("%s\n", "bye");
                        XCloseDisplay(dpy);
                        return 0;
                        break;
                    }
                }
            }
        }
    }
}