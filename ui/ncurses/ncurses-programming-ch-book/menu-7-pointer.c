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

char*choices[] ={
    "Choice1",
    "Choice2",
    "Choice3",
    "Choice4",
    "Choice5",
    "Choice6",
    "Choice7",
    "Exit",
};

void func(char*name);

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
    {
        my_items[i]=new_item(choices[i],choices[i]);
        /* 设置用户指针 */
        set_item_userptr(my_items[i],func);
    }
    my_items[n_choices]=(ITEM*)NULL;
    /* 创建菜单 */
    my_menu=new_menu((ITEM**)my_items);
    /* 传递菜单 */
    mvprintw(LINES-3,0,"Press <ENTER> to see the option selected");
    mvprintw(LINES-2,0,"Up and Down arrow keys to naviage(F1 to Exit)");
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
            case 10: /*Enter 键 */
            { 
                ITEM*cur;
                void (*p)(char*);
                cur=current_item(my_menu);
                p =item_userptr(cur);
                p((char*)item_name(cur));
                pos_menu_cursor(my_menu);
                break;
            }
            break;
        }
    }
    unpost_menu(my_menu);
    for(i=0; i<n_choices;++i)
    free_item(my_items[i]);
    free_menu(my_menu);
    endwin();
}

void func(char*name)
{ 
    move(20,0);
    clrtoeol();
    mvprintw(20,0, "Itemselectedis :%s", name);
}