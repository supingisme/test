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

int main(int argc,char *argv[])
{
    initscr(); /* 进入 curses 模式 */
    start_color();/* 开启颜色管理功能 */
    init_pair(1,COLOR_CYAN, COLOR_BLACK);
    printw("ABig string whichididn'tcareto typefully");
    mvchgat(0,0, -1,A_BLINK, 1,NULL);
    /*
    *第一、二个参数表明了函数开始的位置。
    *第三个参数是被改变修饰的字符的数目，-1表示一整行。
    *第四个参数是被改变的修饰名。
    *第五个参数是颜色索引。颜色索引已经在init_pair()中被初试化了。
    *如果用０表示不使用颜色。
    *最后一个总是NULL，没什么特殊含义。
    */
    refresh();
    getch();
    endwin(); /* 结束curses模式 */
    return 0;
}