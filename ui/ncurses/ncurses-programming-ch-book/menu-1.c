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

char*choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit",
};

/*
$ gcc menu-1.c -lncurses -lmenu

*/

int main()
{ 
    ITEM**my_items;
    int c;
    MENU *my_menu;
    int n_choices,i;
    ITEM*cur_item;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    n_choices=ARRAY_SIZE(choices);
    my_items= (ITEM**)calloc(n_choices+ 1, sizeof(ITEM*));
    for(i= 0; i < n_choices;++i)
        my_items[i]= new_item(choices[i],choices[i]);
    my_items[n_choices]= (ITEM*)NULL;
    my_menu= new_menu((ITEM**)my_items);
    mvprintw(LINES- 2,0, "F1toExit");
    post_menu(my_menu);
    refresh();
    while((c= getch())!= KEY_F(1))
    { 
        switch(c)
        { 
            case KEY_DOWN:
                menu_driver(my_menu,REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(my_menu,REQ_UP_ITEM);
                break;
        }
    }
    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();
}
/*
menu_driver() 函数可以接受以下导览请求： （就是第二个参数）
REQ_LEFT_ITEM 左移一个菜单项。
REQ_RIGHT_ITEM 右移一个菜单项。
REQ_UP_ITEM 上移一个菜单项。
REQ_DOWN_ITEM 下移一个菜单项。
REQ_SCR_ULINE 向上滚动一行。
REQ_SCR_DLINE 向下滚动一行。
REQ_SCR_DPAGE 下翻一页。
REQ_SCR_UPAGE 上翻一页
REQ_FIRST_ITEM 跳到首项。
REQ_LAST_ITEM 跳到最末一项。
REQ_NEXT_ITEM 跳到下一项。
REQ_PREV_ITEM 跳到上一项。
REQ_TOGGLE_ITEM 选择/取消选择一项。
REQ_CLEAR_PATTERN 清空菜单模式缓冲区。
REQ_BACK_PATTERN 删除菜单模式缓冲区的前面一个字符。
REQ_NEXT_MATCH 跳到下一个与模式匹配的项。
REQ_PREV_MATCH 跳到上一个与模式匹配的项。
*/