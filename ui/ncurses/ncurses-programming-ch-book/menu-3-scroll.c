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
#include <curses.h>
#include <menu.h>
#include<malloc.h>
#include<string.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char *choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Choice 5",
    "Choice 6",
    "Choice 7",
    "Choice 8",
    "Choice 9",
    "Choice10",
    "Exit",
    (char*)NULL,
};
void print_in_middle(WINDOW*win, int starty, int startx, int width, char *string, chtype color);

/*
$ gcc menu-1.c -lncurses -lmenu

*/

int main()
{ 
    ITEM**my_items;
    int c;
    MENU*my_menu;
    WINDOW*my_menu_win;
    int n_choices,i;
    /* 初始化curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_CYAN, COLOR_BLACK);
    /* 创建菜单项 */
    n_choices=ARRAY_SIZE(choices);
    my_items=(ITEM**)calloc(n_choices,sizeof(ITEM*));
    for(i=0;i<n_choices;++i)
        my_items[i]=new_item(choices[i],choices[i]);
    /* 创建菜单 */
    my_menu=new_menu((ITEM**)my_items);
    /* 创建与菜单相关联的窗口 */
    my_menu_win=newwin(20,40,4,4);
    keypad(my_menu_win,TRUE);
    /* 设置主窗口和子窗口 */
    set_menu_win(my_menu,my_menu_win);
    set_menu_sub(my_menu,derwin(my_menu_win,6,38,3,1));
    set_menu_format(my_menu,5,1);
    /* 设置标志串为"* "*/
    set_menu_mark(my_menu,"* ");
    /* 在主窗口的边界打印边框线和标题 */
    box(my_menu_win,0, 0);
    print_in_middle(my_menu_win,1,0, 40,"My Menu",COLOR_PAIR(1));
    mvwaddch(my_menu_win,2,0,ACS_LTEE);
    mvwhline(my_menu_win,2, 1,ACS_HLINE, 38);
    mvwaddch(my_menu_win,2,39,ACS_RTEE);
    /* 传递菜单 */
    post_menu(my_menu);
    wrefresh(my_menu_win);
    attron(COLOR_PAIR(2));
    mvprintw(LINES- 2, 0, "Use PageUp and PageDown to scoll down or up a page of items");
    mvprintw(LINES- 1,0, "Arrow Keys to navigate(F1 to Exit)");
    attroff(COLOR_PAIR(2));
    refresh();
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
        case KEY_NPAGE:
            menu_driver(my_menu,REQ_SCR_DPAGE);
            break;
        case KEY_PPAGE:
            menu_driver(my_menu,REQ_SCR_UPAGE);
            break;
        }
        wrefresh(my_menu_win);
    }
    /* 取消传递并且释放占用的内存 */
    unpost_menu(my_menu);
    free_menu(my_menu);
    for(i=0; i<n_choices;++i)
        free_item(my_items[i]);
    endwin();
}
void print_in_middle(WINDOW*win, int starty, int startx, int width, char *string, chtype color)
{ 
    int length,x,y;
    float temp;
    if(win ==NULL)
        win =stdscr;
    getyx(win,y,x);
    if(startx!=0)
        x=startx;
    if(starty!=0)
        y=starty;
    if(width== 0)
        width =80;
    length=strlen(string);
    temp=(width- length)/2;
    x=startx+(int)temp;
    wattron(win,color);
    mvwprintw(win,y,x,"%s",string);
    wattroff(win,color);
    refresh();
}