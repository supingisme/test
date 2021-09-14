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


int main()
{
    int ch;
    initscr(); /* 开始 curses模式 */
    raw(); /* 禁用行缓冲 */
    keypad(stdscr,TRUE); /* 开启功能键响应模式 */
    noecho(); /* 当执行 getch()函数的时候关闭键盘回显 */
    printw("Typeany characterto seeit in bold\n");
    ch = getch(); /* 如果没有调用 raw()函数，
                 我们必须按下enter键才可以将字符传递给程序*/
    if(ch== KEY_F(1)) /* 如果没有调用 keypad（）初始化，将不会执行这条语句 */
        printw("F1Key pressed");
        /* 如果没有使用 noecho() 函数，一些控制字符将会被打印到屏幕上 */
    else
    { 
        printw("Thepressedkeyis ");
        attron(A_BOLD);
        printw("%c",ch);
        attroff(A_BOLD);
    }
    refresh(); /* 将缓冲区的内容打印到显示器上 */
    getch(); /* 等待用户输入 */
    endwin(); /* 结束 curses模式 */
    return 0;
}
