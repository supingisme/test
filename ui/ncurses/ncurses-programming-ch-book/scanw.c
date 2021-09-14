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
#include<ncurses.h> /*ncurses.h 已经包含了stdio.h */
#include<string.h>

int main()
{
    char mesg[]="Enterastring:"; /* 将要被打印的字符串信息 */
    char str[80];
    int row,col; /* 存储行号和列号的变量，用于指定光标位置 */
    initscr(); /* 进入 curses模式 */
    getmaxyx(stdscr,row,col); /* 取得 stdscr的行数和列数 */
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
    /* 在屏幕的正中打印字符串 mesg*/
    getstr(str); /* 将指针 str 指向读取的字符串 */
    mvprintw(LINES- 2,0, "YouEntered:%s", str);
    getch();
    endwin();
    return 0;
}