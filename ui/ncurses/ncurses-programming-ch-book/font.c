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
#include<ncurses.h>
#include<stdlib.h>
/*
A_NORMAL 普通字符输出 (不加亮显示)
A_STANDOUT 终端字符最亮
A_UNDERLINE 下划线
A_REVERSE 字符反白显示
A_BLINK 闪动显示
A_DIM 半亮显示
A_BOLD 加亮加粗
A_PROTECT 保护模式
A_INVIS 空白显示模式
A_ALTCHARSET 字符交替
A_CHARTEXT 字符掩盖
COLOR_PAIR(n) 前景、背景色设置
*/
int main(int argc,char *argv[])
{
    int ch,prev;
    FILE*fp;
    int goto_prev= FALSE, y, x;
    
    if(argc!= 2)
    {
        printf("Usage:%s <a c file name>\n",argv[0]);
        exit(1);
    }
    
    fp = fopen(argv[1],"r"); /* 在这里检测文件是否成功打开 */
    
    if(fp== NULL)
    {
        perror("Cannotopeninputfile");
        exit(1);
    }
    
    initscr(); /* 初始化并进入 curses模式 */
    prev= EOF;
    
    while((ch= fgetc(fp))!= EOF)
    {
        if(prev== '/'&& ch== '*')/* 当读到字符“/”和“*”的时候开启修饰*/
        {
            attron(A_BOLD); /* 将“/”和“*”及以后输出的文字字体加粗 */
            goto_prev= TRUE;
        }
        if(goto_prev== TRUE) /* 回到“/”和“*”之前开始输出 */
        {
            getyx(stdscr,y, x);
            move(y,x-1);
            printw("%c%c", '/',ch);/* 打印实际内容的部分 */
            ch = 'a'; /* 避免下次读取变量错误，这里赋一个任意值 */
            goto_prev= FALSE; /* 让这段程序只运行一次 */
        }
        else 
            printw("%c", ch);
        refresh(); /* 将缓冲区的内容刷新到屏幕上 */
        if(prev== '*' && ch == '/')
            attroff(A_BOLD); /* 当读到字符“*”和“/”的时候关闭修饰*/
        prev= ch;
    }
    getch();
    endwin(); /* 结束并退出 curses模式 */
    return 0;
}