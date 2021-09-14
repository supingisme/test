/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:53 CST. */
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
#include<ncurses.h>


typedef struct _win_border_struct{
    chtype ls, rs,ts, bs,
    tl, tr,bl, br;
}WIN_BORDER;

typedef struct _WIN_struct{
    int startx,starty;
    int height,width;
    WIN_BORDER border;
}WIN;

void init_win_params(WIN*p_win);
void print_win_params(WIN*p_win);
void create_box(WIN*win, int bool_);

int main(int argc,char *argv[])
{
    WIN win;
    int ch;
    initscr(); /* 初始化并进入 curses模式 */
    start_color(); /* 开启彩色显示功能 */
    cbreak(); /* 行缓冲禁止，传递所有控制信息 */
    keypad(stdscr,TRUE); /* 程序需要使用 F1功能键 */
    noecho();
    init_pair(1,COLOR_CYAN, COLOR_BLACK);
    /* 以下代码初始化窗口的参数 */
    init_win_params(&win);
    print_win_params(&win);
    attron(COLOR_PAIR(1));
    printw("PressF1toexit");
    refresh();
    attroff(COLOR_PAIR(1));
    create_box(&win,TRUE);
    
    while((ch= getch())!= KEY_F(1))
    { 
        switch(ch)
        { 
            case KEY_LEFT:
                create_box(&win,FALSE);
                --win.startx;
                create_box(&win,TRUE);
                break;
            case KEY_RIGHT:
                create_box(&win,FALSE);
                ++win.startx;
                create_box(&win,TRUE);
                break;
            case KEY_UP:
                create_box(&win,FALSE);
                --win.starty;
                create_box(&win,TRUE);
                break;
            case KEY_DOWN:
                create_box(&win,FALSE);
                ++win.starty;
                create_box(&win,TRUE);
                break;
        }
    }
    endwin(); /* 结束 curses模式 */
    return 0;
}
void init_win_params(WIN *p_win)
{
    p_win->height= 3;
    p_win->width= 10;
    p_win->starty= (LINES -p_win->height)/2;
    p_win->startx= (COLS- p_win->width)/2;
    p_win->border.ls= '|';
    p_win->border.rs= '|';
    p_win->border.ts= '-';
    p_win->border.bs= '-';
    p_win->border.tl= '+';
    p_win->border.tr= '+';
    p_win->border.bl= '+';
    p_win->border.br= '+';
}
void print_win_params(WIN*p_win)
{
    #ifdef _DEBUG
    mvprintw(25,0, "%d %d %d %d", p_win->startx,p_win->starty,
            p_win->width,p_win->height);
    refresh();
    #endif
}
void create_box(WIN *p_win, int bool_)
{ 
    int i, j;
    int x,y, w, h;
    x = p_win->startx;
    y = p_win->starty;
    w = p_win->width;
    h = p_win->height;
    
    if(bool_== TRUE)
    {
        mvaddch(y,x, p_win->border.tl);
        mvaddch(y,x + w, p_win->border.tr);
        mvaddch(y+ h, x, p_win->border.bl);
        mvaddch(y+ h, x + w, p_win->border.br);
        mvhline(y,x + 1,p_win->border.ts,w -1);
        mvhline(y+ h,x + 1, p_win->border.bs,w -1);
        mvvline(y+ 1, x,p_win->border.ls,h - 1);
        mvvline(y+ 1, x + w, p_win->border.rs,h -1);
    }
    else
        for(j= y; j <= y + h; ++j)
            for(i= x; i <= x + w; ++i)
                mvaddch(j,i, ' ');
    refresh();
}