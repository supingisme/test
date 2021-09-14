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


#define STARTX 15
#define STARTY 4
#define WIDTH 25
#define N_FIELDS 3


/*
$ gcc form-1.c -lncurses -lform

*/
int main()
{ 
    FIELD*field[N_FIELDS];
    FORM *my_form;
    int ch,i;
    /* 初始化 curses*/
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    /* 初始化表单域 */
    for(i=0; i<N_FIELDS- 1; ++i)
    field[i]= new_field(1,WIDTH, STARTY+i* 2,STARTX, 0,0);
    field[N_FIELDS- 1]= NULL;
    /* 设置表单域选项 */
    set_field_back(field[1],A_UNDERLINE); /* 为选项打印下划线 */
    field_opts_off(field[0],O_ACTIVE); /* 这个表单域是静态标签 */
    field_opts_off(field[1],O_PUBLIC); /* 这个表单域类似密码域 */
    field_opts_off(field[1],O_AUTOSKIP);
    /* 防止在输入完最后一个字符后还是在同一个域输入*/
    /* 创建表单并递送 */
    my_form=new_form(field);
    post_form(my_form);
    refresh();
    set_field_just(field[0],JUSTIFY_CENTER); /* 表单域输入时居中对齐 */
    set_field_buffer(field[0],0, "Thisis a staticField "); /* 初始化表单域 */
    mvprintw(STARTY,STARTX- 10,"Field1:");
    mvprintw(STARTY+ 2,STARTX -10, "Field2:");
    refresh();
    /* 循环读取用户请求 */
    while((ch=getch())!=KEY_F(1))
    { 
        switch(ch)
        { 
            case KEY_DOWN:
                /* 跳到下一个表单域 */
                form_driver(my_form,REQ_NEXT_FIELD);
                /* 跳到当前缓冲的末尾 */
                /* 在最后一个字符处跳出 */
                form_driver(my_form,REQ_END_LINE);
                break;
            case KEY_UP:
                /* 跳到前一个表单域 */
                form_driver(my_form,REQ_PREV_FIELD);
                form_driver(my_form,REQ_END_LINE);
                break;
            default:
                /* 若是普通的字符，则打印出来 */
                form_driver(my_form,ch);
                break;
        }
    }
    /* 取消表单传递并释放内存 */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);
    endwin();
    return 0;
}