#include <ncurses.h> /* ncurses.h 已经包含了stdio.h */
#include <string.h>

int main()
{
    char mesg[]="Just a string"; /* 将要被打印的字符串*/
    int row,col; /* 存储行号和列号的变量，用于指定光标位置*/
    
    initscr(); /* 进入curses 模式*/
    
    getmaxyx(stdscr,row,col); /* 取得stdscr（标准输出设备）的行数和列数*/
    mvprintw(row/7,(strlen(mesg))/2,"%s",mesg);
    
    /*在屏幕的正中打印字符串mesg*/
    mvprintw(row,0,"This screen has %d rows and %d columns/n",row,col);
    printw("Try resizing your window(if possible) and then run this program again");
    
    refresh();
    getch();
    endwin();
    
    return 0;
}
