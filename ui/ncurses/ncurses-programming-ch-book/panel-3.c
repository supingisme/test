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
#include<panel.h>
#include<string.h>
#include<malloc.h>


typedef struct _PANEL_DATA
{
    int x,y, w, h;
    char label[80];
    int label_color;
    PANEL *next;
}PANEL_DATA;

#define NLINES 10
#define NCOLS 40

void init_wins(WINDOW**wins, int n);
void win_show(WINDOW*win, char *label,int label_color);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void set_user_ptrs(PANEL**panels, int n);


/*
$ gcc panel.c -lncurses -lpanel

*/


int main()
{ 
    WINDOW *my_wins[3];
    PANEL *my_panels[3];
    PANEL_DATA *top;
    PANEL *stack_top;
    WINDOW *temp_win, *old_win;
    int ch;
    int newx, newy, neww, newh;
    int size = FALSE, move = FALSE;
    /* 初始化 curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化所有的颜色 */
    init_pair(1,COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_BLUE, COLOR_BLACK);
    init_pair(4,COLOR_CYAN, COLOR_BLACK);
    init_wins(my_wins, 3);
    /* 更新面板栈的顺序。把面板 2置于栈顶*/
    my_panels[0]= new_panel(my_wins[0]); /* 把面板 0压入栈，顺序: stdscr-0*/
    my_panels[1]= new_panel(my_wins[1]); /* 把面板 1压入栈。顺序: stdscr-0-1*/
    my_panels[2]= new_panel(my_wins[2]); /* 把面板 2压入栈,顺序: stdscr-0-1-2*/
    set_user_ptrs(my_panels,3);
    /* 更新面板栈的顺序。把面板 2置于栈顶 */
    update_panels();
    /* 在屏幕上显示出来 */
    attron(COLOR_PAIR(4));
    mvprintw(LINES- 3, 0, "Use 'm' for moving,'r' for resizing");
    mvprintw(LINES- 2, 0, "Use tab to browse through the windows (F1to Exit)");
    attroff(COLOR_PAIR(4));
    doupdate();
    stack_top = my_panels[2];
    top = (PANEL_DATA *)panel_userptr(stack_top);
    newx = top->x;
    newy =top->y;
    neww =top->w;
    newh=top->h;
    
    while((ch=getch())!=KEY_F(1))
    { 
        switch(ch)
        { 
            case 9: /*Tab 对应编号 */
                top=(PANEL_DATA *)panel_userptr(stack_top);
                top_panel(top->next);
                stack_top=top->next;
                top=(PANEL_DATA *)panel_userptr(stack_top);
                newx =top->x;
                newy =top->y;
                neww =top->w;
                newh=top->h;
                break;
            case 'r': /* 改变面板大小*/
                size =TRUE;
                attron(COLOR_PAIR(4));
                mvprintw(LINES - 4, 0, "Entered Resizing :Use Arrow Keys "\
                                       "to resize andpress<ENTER> to endresizing");
                refresh();
                attroff(COLOR_PAIR(4));
                break;
            case 'm':/* 移动面板 */
                attron(COLOR_PAIR(4));
                mvprintw(LINES- 4, 0, "EnteredMoving: UseArrowKeys to"\
                                      " Move and press<ENTER> toend moving");
                refresh();
                attroff(COLOR_PAIR(4));
                move=TRUE;
                break;
            case KEY_LEFT:
                if(size==TRUE)
                { 
                    --newx;
                    ++neww;
                }
                if(move==TRUE)
                    --newx;
                break;
            case KEY_RIGHT:
                if(size==TRUE)
                { 
                    ++newx;
                    --neww;
                }
                if(move == TRUE)
                    ++newx;
                break;
            case KEY_UP:
                if(size == TRUE)
                { 
                    --newy;
                    ++newh;
                }
                if(move == TRUE) --newy;
                break;
            case KEY_DOWN:
                if(size == TRUE)
                { 
                    ++newy;
                    --newh;
                }
                if(move == TRUE)
                    ++newy;
                break;
            case 10: /* Enter对应编号 */
                move(LINES- 4, 0);
                clrtoeol();
                refresh();
                if(size == TRUE)
                { 
                    old_win = panel_window(stack_top);
                    temp_win = newwin(newh, neww, newy, newx);
                    replace_panel(stack_top,temp_win);
                    win_show(temp_win,top->label, top->label_color);
                    delwin(old_win);
                    size = FALSE;
                }
                if(move == TRUE)
                { 
                    move_panel(stack_top,newy, newx);
                    move = FALSE;
                }
                break;
        }
        attron(COLOR_PAIR(4));
        mvprintw(LINES- 3, 0, "Use 'm' for moving,'r' for resizing");
        mvprintw(LINES- 2, 0, "Use tab to browse through the windows (F1to Exit)");
        attroff(COLOR_PAIR(4));
        refresh();
        update_panels();
        doupdate();
    }
    endwin();
    return 0;
}
/* 显示所有的窗口 */
void init_wins(WINDOW**wins, int n)
{ 
    int x,y, i;
    char label[80];
    y =2;
    x =10;
    for(i=0; i<n;++i)
    { 
        wins[i] =newwin(NLINES, NCOLS, y,x);
        sprintf(label,"Window Number%d", i+1);
        win_show(wins[i],label,i+1);
        y +=3;
        x +=7;
    }
}
/* 把每个面板设置为 PANEL_DATA 结构 */
void set_user_ptrs(PANEL**panels, int n)
{ 
    PANEL_DATA *ptrs;
    WINDOW*win;
    int x,y, w, h, i;
    char temp[80];
    ptrs=(PANEL_DATA *)calloc(n,sizeof(PANEL_DATA));
    for(i=0;i <n;++i)
    { 
        win =panel_window(panels[i]);
        getbegyx(win,y, x);
        getmaxyx(win,h, w);
        ptrs[i].x=x;
        ptrs[i].y=y;
        ptrs[i].w=w;
        ptrs[i].h=h;
        sprintf(temp,"WindowNumber%d", i+1);
        strcpy(ptrs[i].label,temp);
        ptrs[i].label_color=i +1;
        if(i +1== n)
            ptrs[i].next=panels[0];
        else
            ptrs[i].next=panels[i+1];
        set_panel_userptr(panels[i],&ptrs[i]);
    }
}
/* 用一个边框和标题栏来显示窗口 */
void win_show(WINDOW*win, char *label,int label_color)
{
    int startx,starty,height,width;
    getbegyx(win,starty,startx);
    getmaxyx(win,height,width);
    box(win,0, 0);
    mvwaddch(win,2, 0,ACS_LTEE);
    mvwhline(win,2, 1,ACS_HLINE, width -2);
    mvwaddch(win,2, width -1,ACS_RTEE);
    print_in_middle(win,1,0, width,label, COLOR_PAIR(label_color));
}
void print_in_middle(WINDOW*win, int starty, int startx, int width, char *string, chtype color)
{
    int length,x,y;
    float temp;
    if(win ==NULL)
        win =stdscr;
    getyx(win,y, x);
    if(startx!=0)
        x =startx;
    if(starty!=0)
        y =starty;
    if(width== 0)
        width =80;
    length=strlen(string);
    temp=(width- length)/2;
    x =startx+(int)temp;
    wattron(win,color);
    mvwprintw(win,y,x, "%s", string);
    wattroff(win,color);
    refresh();
}