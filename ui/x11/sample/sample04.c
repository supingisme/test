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
#include <unistd.h>

#define NIL (0)

#define debug() printf("LINE: %d-\n", __LINE__)

unsigned int blackcolor;
unsigned int whitecolor;

/*没提供头文件 loadpng.h*/
void showpng(char *filename, Display *dpy, Window w, XVisualInfo info)
{
    unsigned error;
    unsigned char *image;
    unsigned width, height;
    unsigned char *png = 0;
    unsigned long pngsize;
    
    //error = loadpng_load_file(&png, &pngsize, filename);
}


int main(int argc, char *argv[])
{
    Display *dpy = XOpenDisplay(NULL);
    
    if(dpy != NULL)
	{
		/*black and white color*/
		blackcolor =  BlackPixel(dpy, DefaultScreen(dpy));
		whitecolor =  WhitePixel(dpy, DefaultScreen(dpy));
        
        XVisualInfo info;
        
        /*get the visual info*/
        XMatchVisualInfo(dpy, DefaultScreen(dpy), 32, TrueColor, &info);
        XSetWindowAttributes attrs;

        /*set attributes*/
        //段错误(吐核)///////////////////////////////////////////////
        attrs.colormap = XCreateColormap(dpy, DefaultRootWindow(dpy), 
                                        info.visual, AllocNone);
        attrs.border_pixel = blackcolor;
        attrs.background_pixel = whitecolor;

        
		/*create window*/
		Window w = XCreateWindow(dpy, DefaultRootWindow(dpy),
						0,0,200,200,0,info.depth, InputOutput, info.visual,
                        CWColormap|CWBorderPixel|CWBackPixel, &attrs);

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
                        showpng(argv[1], dpy, w, info);
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
}












