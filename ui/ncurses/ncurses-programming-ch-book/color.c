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
#include<stdlib.h>
#include<string.h>

void print_in_middle(WINDOW*win, int starty,int startx,int width,char*string);
/*
COLOR_BLACK 0 黑色
COLOR_RED 1 红色
COLOR_GREEN 2 绿色
COLOR_YELLOW 3 黄色
COLOR_BLUE 4 蓝色
COLOR_MAGENTA 5 洋红色
COLOR_CYAN 6 蓝绿色, 青色
COLOR_WHITE 7 白色
*/
int main(int argc,char *argv[])
{
    initscr(); /*启动 curses模式*/
    if(has_colors()== FALSE)
    { 
        endwin();
        printf("Youterminaldoesnot supportcolor\n");
        exit(1);
    }
    start_color(); /*启动 color机制 */
    init_pair(1,COLOR_RED, COLOR_BLUE);
    attron(COLOR_PAIR(1));
    print_in_middle(stdscr,LINES / 2,0, 0,"Viola !!!In color...");
    attroff(COLOR_PAIR(1));
    getch();
    endwin();
}
void print_in_middle(WINDOW*win, int starty,int startx,int width,char*string)
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
    length=strlen(string);
    temp=(width-length)/2;
    x =startx+(int)temp;
    mvwprintw(win,y,x, "%s", string);
    refresh();
}