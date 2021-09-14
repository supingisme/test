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

#define ARRAY_SIZE(a)(sizeof(a)/sizeof(a[0]))
#define CTRLD 4

char*choices[] ={
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Choice 5",
    "Choice 6",
    "Choice 7",
    "Exit",
};


/*
$ gcc menu-7-pointer.c -lncurses -lmenu
*/


int main()
{ 
    ITEM**my_items;
    int c;
    MENU *my_menu;
    int n_choices,i;
    ITEM*cur_item;
    /* 初始化 curses*/
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化菜单菜单项 */
    n_choices=ARRAY_SIZE(choices);
    my_items=(ITEM**)calloc(n_choices+1, sizeof(ITEM*));
    for(i=0; i<n_choices;++i)
    my_items[i]=new_item(choices[i],choices[i]);
    my_items[n_choices]=(ITEM*)NULL;
    my_menu=new_menu((ITEM**)my_items);
    /* 设置菜单为多值菜单 */
    menu_opts_off(my_menu,O_ONEVALUE);
    mvprintw(LINES- 3,0, "Use <SPACE> to select or unselect an item.");
    mvprintw(LINES- 2,0, "<ENTER> to see presently selected items(F1 to Exit)");
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
            case ' ':
                menu_driver(my_menu,REQ_TOGGLE_ITEM);
                break;
            case 10:/*Enter 键*/
                { 
                    char temp[200];
                    ITEM**items;
                    items=menu_items(my_menu);
                    temp[0]='\0';
                    for(i=0; i<item_count(my_menu);++i)
                    if(item_value(items[i])==TRUE)
                    { 
                        strcat(temp,item_name(items[i]));
                        strcat(temp," ");
                    }
                    move(20,0);
                    clrtoeol();
                    mvprintw(20,0,temp);
                    refresh();
                }
                break;
        }
    }
    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();
}