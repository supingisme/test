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
/*
 *
 */

#include<panel.h>

/*
$ gcc panel.c -lncurses -lpanel

*/

int main()
{
    WINDOW*my_wins[3];
    PANEL *my_panels[3];
    int lines= 10,cols =40,y =2, x=4, i;
    initscr();
    cbreak();
    noecho();
    /* 为每个面板创建窗口 */
    my_wins[0]=newwin(lines,cols, y, x);
    my_wins[1]=newwin(lines,cols, y +1,x +5);
    my_wins[2]=newwin(lines,cols, y +2,x +10);
    /* 为窗口添加创建边框以便你能看到面板的效果 */
    for(i=0; i<3;++i)
        box(my_wins[i],0,0);
    /* 按自底向上的顺序，为每一个面板关联一个窗口*/
    my_panels[0]=new_panel(my_wins[0]);
    /* 把面板 0压进栈, 叠放顺序: stdscr­0*/
    my_panels[1]=new_panel(my_wins[1]);
    /* 把面板 1压进栈, 叠放顺序: stdscr­0­1*/
    my_panels[2]=new_panel(my_wins[2]);
    /* 把面板 2压进栈, 叠放顺序: stdscr­0­1­2*/
    /* 更新栈的顺序。把面板 2置于栈顶 */
    update_panels();
    /* 在屏幕上显示 */
    doupdate();
    getch();
    endwin();
}
