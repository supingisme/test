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
#include<stdio.h>
#include<ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx= 0;
int starty= 0;

char *choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit",
};

int n_choices= sizeof(choices)/ sizeof(char*);
void print_menu(WINDOW*menu_win, int highlight);

int main()
{ 
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;
    initscr();
    clear();
    noecho();
    cbreak(); /*禁用行缓冲，直接传递所有输入 */
    startx= (80 - WIDTH) / 2;
    starty= (24 - HEIGHT) / 2;
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win,TRUE);
    mvprintw(0,0,"Use arrowkeysto go up and down, Pressenter to select a choice");
    refresh();
    print_menu(menu_win,highlight);
    while(1)
    { 
        c = wgetch(menu_win);
        switch(c)
        { 
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10:
                choice=highlight;
                break;
            default:
                mvprintw(24,0, "Charcterpressedis = %3dHopefullyitcanbeprintedas '%c'",c, c);
                refresh();
                break;
        }
        print_menu(menu_win,highlight);
        if(choice!=0) /*用户必须要做一个选择*/
            break;
    }
    mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice,
    choices[choice-1]);
    clrtoeol();
    refresh();
    endwin();
    return 0;
}
void print_menu(WINDOW *menu_win,int highlight)
{
    int x,y, i;
    x =2;
    y =2;
    box(menu_win,0,0);
    for(i=0; i<n_choices;++i)
    {
        if(highlight==i+1) /* 使选择的字符串高亮显示 */
        {
            wattron(menu_win,A_REVERSE);
            mvwprintw(menu_win,y,x, "%s", choices[i]);
            wattroff(menu_win,A_REVERSE);
        }
        else
            mvwprintw(menu_win,y,x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}