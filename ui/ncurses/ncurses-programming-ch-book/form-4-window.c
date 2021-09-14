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
#include<form.h>
#include<string.h>

void print_in_middle(WINDOW*win, int starty, int startx, int width, char *string, chtype color);

int main()
{
    FIELD*field[3];
    FORM *my_form;
    WINDOW*my_form_win;
    int ch,rows, cols;
    /* 初始化 curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化颜色对 */
    init_pair(1,COLOR_RED, COLOR_BLACK);
    /* 初始化域 */
    field[0]=new_field(1,10,6, 1,0, 0);
    field[1]=new_field(1,10,8, 1,0, 0);
    field[2]=NULL;
    /* 设置表单域选项*/
    set_field_back(field[0],A_UNDERLINE);
    field_opts_off(field[0],O_AUTOSKIP);
    /* 如果当前表单域已满，不跳自动跳到下一个表单域 */
    set_field_back(field[1],A_UNDERLINE);
    field_opts_off(field[1],O_AUTOSKIP);
    /* 创建表单并传递 */
    my_form=new_form(field);
    /* 计算表单所需要的面积大小 */
    scale_form(my_form,&rows, &cols);
    /* 创建与表单相关联的窗口 */
    my_form_win=newwin(rows+4, cols +4,4, 4);
    keypad(my_form_win,TRUE);
    /* 设置主窗口和子窗口 */
    set_form_win(my_form,my_form_win);
    set_form_sub(my_form,derwin(my_form_win,rows,cols, 2, 2));
    /* 在窗口的四周显示边框和标题 */
    box(my_form_win,0, 0);
    print_in_middle(my_form_win,1,0, cols +4,"My Form",COLOR_PAIR(1));
    post_form(my_form);
    wrefresh(my_form_win);
    mvprintw(LINES- 2,0, "Use UP, DOWN arrow keys to switch between fields");
    refresh();
    /* 循环以获取用户请求 */
    while((ch=wgetch(my_form_win))!=KEY_F(1))
    { 
        switch(ch)
        { 
            case KEY_DOWN:
                /* 跳到下一个域 */
                form_driver(my_form,REQ_NEXT_FIELD);
                /* 跳到当前缓冲区的末尾 */
                /* 在最后一个字符处跳出 */
                form_driver(my_form,REQ_END_LINE);
                break;
            case KEY_UP:
                /* 跳到上一个域 */
                form_driver(my_form,REQ_PREV_FIELD);
                form_driver(my_form,REQ_END_LINE);
                break;
            default:
                /* 如果是一个普通的字符，则打印出来 */
                form_driver(my_form,ch);
                break;
        }
    }
    /* 取消表单递送并释放内存 */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);
    endwin();
    return 0;
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