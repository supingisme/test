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
#include<string.h>


#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define CTRLD 4

char*choices[]={
    "Choice1",
    "Choice2",
    "Choice3",
    "Choice4",
    "Choice5",
    "Choice6",
    "Choice7",
    "Exit",
};
/*
好了，现在你一定非常想在菜单里弄出点花样来，菜单功能要更加强大且是彩色的。就像这
里的文本模式DOS 游戏。set_menu_fore() 和set_menu_back() 函数可以分别改变选中和
未选中菜单项属性， 这两个函数的名字可能会引起误会， 它们并不会改变菜单的前景色与背
景色哦！
set_menu_grey() 函数可以用来设置菜单中不可选菜单项的显示属性。这把我们引向了仅为
单个菜单项的进行设置的选项O_SELECTABLE。我们可以用item_opts_off() 函数来关闭这
个选项，然后被设置的菜单项就不可选了，且在菜单窗口中是灰色的。现在让我们把这些概
念运用到下面的这个例子中：
*/

/*
$ gcc menu-7-pointer.c -lncurses -lmenu
*/

int main()
{ 
    ITEM**my_items;
    int c;
    MENU*my_menu;
    int n_choices,i;
    ITEM*cur_item;
    /* 初始化curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    init_pair(3,COLOR_MAGENTA, COLOR_BLACK);
    /* 初始化菜单项 */
    n_choices=ARRAY_SIZE(choices);
    my_items=(ITEM**)calloc(n_choices+1,sizeof(ITEM*));
    for(i=0;i<n_choices;++i)
        my_items[i]=new_item(choices[i],choices[i]);
    my_items[n_choices]=(ITEM*)NULL;
    item_opts_off(my_items[3],O_SELECTABLE);
    item_opts_off(my_items[6],O_SELECTABLE);
    /* 创建菜单 */
    my_menu=new_menu((ITEM**)my_items);
    /* 为菜单设置前景和背景 */
    set_menu_fore(my_menu,COLOR_PAIR(1)|A_REVERSE);
    set_menu_back(my_menu,COLOR_PAIR(2));
    set_menu_grey(my_menu,COLOR_PAIR(3));
    /* 传递菜单 */
    mvprintw(LINES- 3,0, "Press <ENTER> to see the option selected");
    mvprintw(LINES- 2,0, "Up and Down arrow keys to naviage(F1 to Exit)");
    post_menu(my_menu);
    refresh();
    while((c=getch())!=KEY_F(1))
    { 
        switch(c)
        { 
            case KEY_DOWN:
                menu_driver(my_menu,REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu,REQ_UP_ITEM);
                break;
            case 10: /*Enter 键*/
                move(20,0);
                clrtoeol();
                mvprintw(20,0, "Itemselectedis :%s",
                item_name(current_item(my_menu)));
                pos_menu_cursor(my_menu);
                break;
        }
    }
    unpost_menu(my_menu);
    for(i=0; i<n_choices;++i)
        free_item(my_items[i]);
    free_menu(my_menu);
    endwin();
}