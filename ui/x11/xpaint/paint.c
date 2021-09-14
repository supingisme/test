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
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Window main_win;
Display *dpy;
XWindowAttributes wa;

button *bt_arr[BUTTON_AMOUNT];

int main(int argc ,char *argv[])
{
    char bg[16] = BACKGROUND_COLOR;
    
    if(argc == 2 && !strcmp("-v", argv[1]))
    {
        fprintf(stdout, "xpaint version %s\n", VERSION);
        exit(0);
    }
    if(argc == 3 && !strcmp("-bg", argv[1]))
    {
        if(strlen(argv[2]) <= 16)
        {
            fprintf(stdout, "Background Color: %s\n", argv[2]);
            strcpy(bg, argv[2]);
        }
        else 
        {
            fprintf(stdout, "BG Color too long\n");
            exit(1);
        }
    }
    
    if((dpy = XOpenDisplay(NULL)) == NULL)
    {
        fprintf(stdout, "Could't open display!\n");
        exit(1);
    }
    
    init_main_window(bg);
    ev_loop();
    (void )XCloseDisplay(dpy);
    
    return 0;
}

void init_main_window(char *bg)
{
    unsigned long int mask = ButtonPressMask | ButtonReleaseMask 
                            | ExposureMask | StructureNotifyMask;
    Window root = XDefaultRootWindow(dpy);
    
    main_win = XCreateSimpleWindow(dpy, root, 0,0,WINDOW_WIDTH,WINDOW_HEIGHT,
                                    LINE_SIZE, get_color("Pink"), get_color(bg));
    XSelectInput(dpy, main_win, mask);
    XMapWindow(dpy, main_win);
}

GC init_gc(char *bg)
{
    XGCValues gcvals;
    unsigned long int vals = GCBackground | GCForeground;
    
    gcvals.background = get_color(bg);
    gcvals.foreground = get_color("Black");
    
    return XCreateGC(dpy, main_win, vals, &gcvals);
}

unsigned long int get_color(const char *color_name)
{
    Colormap colormap = DefaultColormap(dpy, DefaultScreen(dpy));
    XColor c1, c2;
    XAllocNamedColor(dpy, colormap, color_name, &c1, &c2);
    
    return c1.pixel;
}

GC change_color(const char *fg, const char *bg)
{
    int line = 0;
    XGCValues gcvals;
    unsigned long int vals = GCBackground | GCForeground | GCLineWidth;
    
    gcvals.background = get_color(fg);
    gcvals.foreground = get_color(bg);
    
    if(line == 0)line = LINE_SIZE;
    gcvals.line_width = line;
    
    return XCreateGC(dpy, main_win, vals, &gcvals);
}

void draw_button(button *bt)
{
    XDrawRectangle(dpy, main_win, change_color(FOREGROUND_COLOR, BACKGROUND_COLOR),
                    bt->x, bt->y, BUTTON_WIDTH, BUTTON_HEIGHT);
    switch(bt->type)
    {
        case COLOR:
        {
            XFillRectangle(dpy, main_win, 
                            change_color(FOREGROUND_COLOR, BACKGROUND_COLOR),
                            bt->x+1, bt->y+1, BUTTON_WIDTH-1, BUTTON_HEIGHT-1);
            break;
        }
        case SHAPE:
        {
            if(bt->mode.shape_id == LINE)
            {
                XDrawLine(dpy, main_win, change_color("Black", "While"),
                            bt->x+2, bt->y+2, 
                            bt->x+BUTTON_WIDTH-2, bt->y+BUTTON_HEIGHT-2);
            }
            if(bt->mode.shape_id == RECTANGLE)
            {
                XDrawRectangle(dpy, main_win, change_color("Black", "While"),
                            bt->x+2, bt->y+2, 
                            BUTTON_WIDTH-4, BUTTON_HEIGHT-4);
            }
            break;
        }
        case EXIT:
        {
            break;
        }
        case CHANGE_GC:
        {
            break;
        }
    }
}

int mouse_event(bt_shape_id *shape, int bp_x, int bp_y, GC *gc)
{
    int i;
    for(i=0;i<BUTTON_AMOUNT;i++)
    {
        if(bp_x >= bt_arr[i]->x && 
           bp_y >= bt_arr[i]->y &&
           bp_x >= bt_arr[i]->x + BUTTON_WIDTH && 
           bp_y >= bt_arr[i]->y + BUTTON_HEIGHT)
        {
            switch(bt_arr[i]->type)
            {
                case COLOR:
                {
                    *gc = change_color(bt_arr[i]->mode.color, "Black");
                    break;

                }
                case SHAPE:
                {
                    *shape = bt_arr[i]->mode.shape_id;
                    break;
                }
                case CHANGE_GC:
                {
                    break;
                }
                case EXIT:
                {
                    return 1;
                    break;
                }
                
            }
        }
    }
    return 0;
}

int ev_loop()
{
    GC gc = init_gc("Black");
    
    XEvent ev;
    int quit = 0;
    int i;
    
    int bp_x, bp_y, br_x, br_y;
    
    int w, h;
    button bt_close, bt_line, bt_rectangle, bt_red, bt_blue;
    bt_shape_id shape = LINE;
    
    bt_close.x = 3;
    bt_close.y = 3;
    strcpy(bt_close.mode.color, "Black");
    bt_close.type = EXIT;
    
    bt_red.x = 26;
    bt_red.y = 3;
    strcpy(bt_red.mode.color, "Red");
    bt_red.type = COLOR;
    
    bt_blue.x = 49;
    bt_blue.y = 3;
    strcpy(bt_blue.mode.color, "Blue");
    bt_blue.type = COLOR;
    
    bt_line.x = 72;
    bt_line.y = 3;
    bt_line.mode.shape_id = LINE;
    bt_line.type = SHAPE;
    
    bt_rectangle.x = 95;
    bt_rectangle.y = 3;
    bt_rectangle.mode.shape_id = RECTANGLE;
    bt_rectangle.type = SHAPE;
    
    bt_arr[0] = &bt_close;
    bt_arr[1] = &bt_red;
    bt_arr[2] = &bt_blue;
    bt_arr[3] = &bt_line;
    bt_arr[4] = &bt_rectangle;
    
    while(!quit)
    {
        XNextEvent(dpy, &ev);
        
        switch(ev.type)
        {
            case Expose:
            {
                for(i=0;i<BUTTON_AMOUNT;i++)
                {
                    draw_button(bt_arr[i]);
                }
                if(XGetWindowAttributes(dpy, main_win, &wa) == 0)
                {
                    fprintf(stderr, "Could't get window arrtibutes\n");
                    return 1;
                }
                break;
            }
            case ConfigureNotify:
            {
                if(XGetWindowAttributes(dpy, main_win, &wa) == 0)
                {
                    fprintf(stderr, "Could't get window arrtibutes\n");
                    return 1;
                }
            }
            case ButtonPress:
            {
                bp_x = ev.xbutton.x;
                bp_y = ev.xbutton.y;
                break;
            }
            case ButtonRelease:
            {
                br_x = ev.xbutton.x;
                br_y = ev.xbutton.y;
                w = br_x - bp_x;
                h = br_y - bp_y;
                if(w < 0) {w = w * (-1);}
                if(h < 0) {h = h * (-1);}
                
                quit = mouse_event(&shape, bp_x, bp_y, &gc);
                
                if(quit == 0)
                {
                    switch(shape)
                    {
                        case LINE:
                        {
                            fprintf(stdout, "Before Line x:%d|y:%d\n", ev.xbutton.x, ev.xbutton.y);
                            XDrawLine(dpy, main_win, gc, bp_x, bp_y, ev.xbutton.x, ev.xbutton.y);
                            fprintf(stdout, "After Line x:%d|y:%d\n", ev.xbutton.x, ev.xbutton.y);
                            break;
                        }
                        case RECTANGLE:
                        {
                            if((bp_x < br_x) && bp_y < br_y)
                            {
                                XDrawRectangle(dpy, main_win, gc, bp_x, bp_y, w, h);
                            }
                            if((bp_x > br_x) && bp_y < br_y)
                            {
                                XDrawRectangle(dpy, main_win, gc, br_x, bp_y, w, h);
                            }
                            if((bp_x > br_x) && bp_y > br_y)
                            {
                                XDrawRectangle(dpy, main_win, gc, br_x, br_y, w, h);
                            }
                            if((bp_x < br_x) && bp_y > br_y)
                            {
                                XDrawRectangle(dpy, main_win, gc, bp_x, br_y, w, h);
                            }
                            break;
                        }
                    }
                }
                break;
            }
            case DestroyNotify:
            {
                //XFreeGC(gc);
                XCloseDisplay(dpy);
                quit = 1;
                break;
            }
        }
    }
}



















