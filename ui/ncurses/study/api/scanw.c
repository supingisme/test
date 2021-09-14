/*
Compile: gcc main.c -lncurses
*/
#include <ncurses.h>                    /* ncurses.h 已经包含了stdio.h */
#include <string.h>
int main()
{
    char mesg[]="Enter a string: ";     /* 将要被打印的字符串信息*/
    char str[80];
    int row,col;                        /* 存储行号和列号的变量，用于指定光标位置*/
    initscr();                          /* 进入curses 模式*/
    getmaxyx(stdscr,row,col);           /* 取得stdscr 的行数和列数*/
    mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                                        /* 在屏幕的正中打印字符串mesg */
    getstr(str);                        /* 将指针str 指向读取的字符串*/
    mvprintw(LINES-2, 0, "You Entered: %s", str);
    getch();
    endwin();
    return 0;
}
//————————————————
//版权声明：本文为CSDN博主「Koma_Wong」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/Rong_Toa/article/details/80753590

