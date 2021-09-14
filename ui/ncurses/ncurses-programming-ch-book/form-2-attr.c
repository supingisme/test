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


/*
$ gcc form-1.c -lncurses -lform

*/
int main()
{ 
    FIELD*field[3];
    FORM*my_form;
    int ch;
    /* 初始化 curses*/
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化颜色 */
    init_pair(1,COLOR_WHITE, COLOR_BLUE);
    init_pair(2,COLOR_WHITE, COLOR_BLUE);
    /* 初始化表单域 */
    field[0]=new_field(1,10,4, 18,0,0);
    field[1]=new_field(1,10,6, 18,0,0);
    field[2]=NULL;
    /* 设置表单域选项 */
    set_field_fore(field[0],COLOR_PAIR(1)); /* 设置表单域背景色为蓝色 */
    set_field_back(field[0],COLOR_PAIR(2)); /* 白色为前景色（字符为白色）*/
    field_opts_off(field[0],O_AUTOSKIP);
    /* 当这个域填满时不自动跳到下一个表单域*/
    set_field_back(field[1],A_UNDERLINE);
    field_opts_off(field[1],O_AUTOSKIP);
    /* 创建表单并递送 */
    my_form=new_form(field);
    post_form(my_form);
    refresh();
    set_current_field(my_form,field[0]);/* 把此表单域设为当前的活动域 */
    mvprintw(4,10, "Value1:");
    mvprintw(6,10, "Value2:");
    mvprintw(LINES- 2,0, "UseUP, DOWNarrowkeys toswitch betweenfields");
    refresh();
    /* 循环获取用户请求 */
    while((ch=getch())!=KEY_F(1))
    { 
        switch(ch)
        { 
            case KEY_DOWN:
                /* 跳到下一个表单域 */
                form_driver(my_form,REQ_NEXT_FIELD);
                /* 跳到当前缓冲区的末尾 */
                /* 在输入最后一个字符后跳出 */
                form_driver(my_form,REQ_END_LINE);
                break;
            case KEY_UP:
                /* 跳到前一个表单域 */
                form_driver(my_form,REQ_PREV_FIELD);
                form_driver(my_form,REQ_END_LINE);
                break;
            default:
                /* 如果是正常的字符，则读入并打印 */
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