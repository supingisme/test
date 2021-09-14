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
#include<panel.h>
#include<string.h>

#define NLINES 10
#define NCOLS 40

void init_wins(WINDOW**wins, int n);
void win_show(WINDOW*win, char *label,int label_color);
void print_in_middle(WINDOW*win, int starty, int startx, int width, char *string, chtype color);

/*
$ gcc panel.c -lncurses -lpanel

*/

int main()
{ 
    WINDOW*my_wins[3];
    PANEL *my_panels[3];
    PANEL *top;
    int ch;
    /*初始化 curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化所有的颜色 */
    init_pair(1,COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_BLUE, COLOR_BLACK);
    init_pair(4,COLOR_CYAN, COLOR_BLACK);
    init_wins(my_wins,3);
    /* 按自底向上的顺序，把每个窗口添加进一个面板 */
    my_panels[0]=new_panel(my_wins[0]);
    /* 把面板 0压入栈， 顺序: stdscr-0*/
    my_panels[1]=new_panel(my_wins[1]);
    /* 把面板 1压入栈，顺序: stdscr-0-1*/
    my_panels[2]=new_panel(my_wins[2]);
    /* 把面板 2压入栈，顺序: stdscr-0-1-2*/
    /* 为下一个面板建立用户指针 */
    set_panel_userptr(my_panels[0],my_panels[1]);
    set_panel_userptr(my_panels[1],my_panels[2]);
    set_panel_userptr(my_panels[2],my_panels[0]);
    /* 更新面板栈的顺序。把面板 2置于栈顶*/
    update_panels();
    /* 在屏幕上显示*/
    attron(COLOR_PAIR(4));
    mvprintw(LINES- 2,0, "Usetab tobrowsethroughthewindows (F1to Exit)");
    attroff(COLOR_PAIR(4));
    doupdate();
    top=my_panels[2];
    while((ch=getch())!=KEY_F(1))
    { 
        switch(ch)
        { 
            case 9:
                top=(PANEL *)panel_userptr(top);
                top_panel(top);
                break;
        }
        update_panels();
        doupdate();
    }
    endwin();
    return 0;
}
/* 显示所有的窗口 */
void init_wins(WINDOW**wins, int n)
{ 
    int x,y, i;
    char label[80];
    y =2;
    x =10;
    for(i=0; i <n;++i)
    { 
        wins[i] =newwin(NLINES, NCOLS, y,x);
        sprintf(label,"Window Number%d", i + 1);
        win_show(wins[i],label,i + 1);
        y += 3;
        x += 7;
    }
}

/* 用一个边框和控件显示所有的窗口 */
void win_show(WINDOW*win, char *label,int label_color)
{ 
    int startx,starty,height,width;
    getbegyx(win,starty,startx);
    getmaxyx(win,height,width);
    box(win,0, 0);
    mvwaddch(win,2, 0,ACS_LTEE);
    mvwhline(win,2, 1,ACS_HLINE, width -2);
    mvwaddch(win,2, width -1,ACS_RTEE);
    print_in_middle(win,1,0, width,label, COLOR_PAIR(label_color));
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
    int length,x,y;
    float temp;
    if(win == NULL)
        win = stdscr;
    getyx(win,y, x);
    if(startx!= 0)
        x = startx;
    if(starty!= 0)
        y = starty;
    if(width== 0)
        width = 80;
    length= strlen(string);
    temp= (width- length)/2;
    x = startx+ (int)temp;
    wattron(win,color);
    mvwprintw(win,y,x, "%s", string);
    wattroff(win,color);
    refresh();
}

