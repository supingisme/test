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
#include<curses.h>
#include<menu.h>
#include<malloc.h>


#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define CTRLD 4


char*choices[]={
    "Choice 1","Choice 2","Choice 3","Choice 4","Choice 5",
    "Choice 6","Choice 7","Choice 8","Choice 9","Choice 10",
    "Choice11","Choice12","Choice13","Choice14","Choice 15",
    "Choice16","Choice17","Choice18","Choice19","Choice 20",
    "Exit",
    (char*)NULL,
};


/*
我们来仔细看一下set_menu_format() 函数的调用，它指定列数为3，即每行就显示3列菜
单项。我们已经用menu_opts_off()函数关闭了描述信息的显示。 set_menu_opts()，
menu_opts_on() 和 menu_opts() 也是用来设置菜单选项的函数。
以下就是一些常用的菜单选项：

    O_ONEVALUE 在菜单中只能选一个菜单项。
    O_SHOWDESC 当菜单被传递时显示对菜单项的描述。
    O_ROWMAJOR 以行为主序显示菜单。
    O_IGNORECASE 在样式匹配时忽略大小写。
    O_SHOWMATCH 样式匹配时光标移到菜单项上。
    O_NONCYCLIC 上移或下移一个菜单项时，不能跳到菜单另一端的菜单项上去。
*/


/*
$ gcc menu-7-pointer.c -lncurses -lmenu
*/

int main()
{ 
    ITEM **my_items;
    int c;
    MENU *my_menu;
    WINDOW *my_menu_win;
    int n_choices, i;
    /* 初始化 curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    init_pair(1,COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_CYAN, COLOR_BLACK);
    /* 创建菜单项 */
    n_choices=ARRAY_SIZE(choices);
    my_items= (ITEM **)calloc(n_choices, sizeof(ITEM*));
    for(i= 0; i < n_choices; ++i)
    my_items[i] = new_item(choices[i],choices[i]);
    /* 创建菜单 */
    my_menu= new_menu((ITEM**)my_items);
    /* 设置菜单选项，不显示描述 */
    menu_opts_off(my_menu,O_SHOWDESC);
    /* 创建与菜单相关联的窗口 */
    my_menu_win= newwin(10, 70, 4, 4);
    keypad(my_menu_win,TRUE);
    /* 设置主窗口和子窗口 */
    set_menu_win(my_menu,my_menu_win);
    set_menu_sub(my_menu,derwin(my_menu_win,6, 68, 3, 1));
    set_menu_format(my_menu,5, 3);
    set_menu_mark(my_menu," * ");
    /* 在主窗口的边界打印边框线和标题 */
    box(my_menu_win,0, 0);
    attron(COLOR_PAIR(2));
    mvprintw(LINES- 3, 0, "Use PageUp and PageDown to scroll");
    mvprintw(LINES- 2, 0, "Use ArrowKeys to navigate (F1 to Exit)");
    attroff(COLOR_PAIR(2));
    refresh();
    /* 传递菜单 */
    post_menu(my_menu);
    wrefresh(my_menu_win);
    while((c=wgetch(my_menu_win))!=KEY_F(1))
    { 
        switch(c)
        { 
            case KEY_DOWN:
                menu_driver(my_menu,REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu,REQ_UP_ITEM);
                break;
            case KEY_LEFT:
                menu_driver(my_menu,REQ_LEFT_ITEM);
                break;
            case KEY_RIGHT:
                menu_driver(my_menu,REQ_RIGHT_ITEM);
                break;
            case KEY_NPAGE:
                menu_driver(my_menu,REQ_SCR_DPAGE);
                break;
            case KEY_PPAGE:
                menu_driver(my_menu,REQ_SCR_UPAGE);
                break;
        }
        wrefresh(my_menu_win);
    }
    /* 取消传递并释放占用的内存 */
    unpost_menu(my_menu);
    free_menu(my_menu);
    for(i=0; i<n_choices;++i)
    free_item(my_items[i]);
    endwin();
}