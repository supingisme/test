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
    FORM *my_form;
    int ch;
    /* 初始化 curses*/
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化表单域 */
    field[0] = new_field(1,20,4, 18,0,0);
    field[1] = new_field(1,20,6, 18,0,0);
    field[2] = NULL;
    /* 设置表单域 */
    set_field_back(field[0],A_UNDERLINE); /* 为选项打印一条下滑线 */
    field_opts_off(field[0],O_AUTOSKIP);
    /* 在域（输入框）填满后光标不会自动跳到下一个表单域 */
    set_field_back(field[1],A_UNDERLINE);
    field_opts_off(field[1],O_AUTOSKIP);
    /* 创建并递送表单 */
    my_form=new_form(field);
    post_form(my_form);
    refresh();
    mvprintw(4,10, "  User:");
    mvprintw(6,10, "passwd:");
    refresh();
    /* 用循环获取用户请求 */
    while((ch=getch())!=KEY_F(1))
    { 
        switch(ch)
        { 
            case KEY_DOWN:
                /* 跳至下一个表单域 */
                form_driver(my_form,REQ_NEXT_FIELD);
                /* 跳到当前缓冲的末尾 */
                /* 精确地在输入最后一个后字符跳出这个表单域 */
                form_driver(my_form,REQ_END_LINE);
                break;
            case KEY_UP:
                /* 移动到前一个表单域 */
                form_driver(my_form,REQ_PREV_FIELD);
                form_driver(my_form,REQ_END_LINE);
                break;
            default:
                /* 如果输入的是普通字符, 就把它打印出来 */
                form_driver(my_form,ch);
                break;
        }
    }
    /* 取消表单并释放内存 */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);
    
    endwin();
    
    return 0;
}