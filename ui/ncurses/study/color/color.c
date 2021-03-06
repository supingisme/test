/*
Compile: gcc main.c -lncurses
*/
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

int main(int argc, char *argv[])
{
    initscr();      /*启动curses 模式*/
    if(has_colors() == FALSE)
    { 
        endwin();
        printf("You terminal does not support color\n");
        exit(1);
    }
    start_color();  /*启动color 机制*/
    init_pair(1, COLOR_RED, COLOR_BLACK);
    
    attron(COLOR_PAIR(1));
    
    print_in_middle(stdscr,LINES / 2, 0, 0, "Viola !!! In color ...");
    
    attroff(COLOR_PAIR(1));
    
    getch();
    endwin();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{
    int length, x, y;
    float temp;
    
    if(win == NULL)
        win = stdscr;
    
    getyx(win, y, x);
    
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;
    
    length = strlen(string);
    temp = (width-length)/2;
    x = startx + (int)temp;
    
    mvwprintw(win, y, x, "%s", string);
    
    refresh();
}
//————————————————
//版权声明：本文为CSDN博主「Koma_Wong」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/Rong_Toa/article/details/80766592
