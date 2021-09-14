/*
Compile: gcc main.c -lncurses
*/
#include <stdio.h>
#include <ncurses.h>
#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
            "Choice 1",
            "Choice 2",
            "Choice 3",
            "Choice 4",
            "Exit",};
            
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);
int main()
{ 
    WINDOW *menu_win;
    int highlight = 1;
    int choice = 0;
    int c;
    
    initscr();
    clear();
    noecho();
    cbreak(); /*禁用行缓冲，直接传递所有输入*/
    
    startx = (80-WIDTH)/ 2;
    starty = (24-HEIGHT)/ 2;
    
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    
    keypad(menu_win,TRUE);
    
    mvprintw(0, 0,"Use arrow keys to go up and down, Press enter to select a choice");
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
                choice = highlight;
                break;
                
            default:
                mvprintw(24, 0, "Charcter pressed is = %3d \
                                 Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        print_menu(menu_win,highlight);
        
        if(choice != 0) /*用户必须要做一个选择*/
        break;
    }
    mvprintw(23, 0, "You chose choice %d with choice string %s\n"
                    , choice,choices[choice-1]);
    clrtoeol();
    
    refresh();
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int highlight)
{
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    
    for(i = 0; i < n_choices; ++i)
    {
        if(highlight == i + 1)  /* 使选择的字符串高亮显示*/
        {
            wattron(menu_win,A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win,A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        
        ++y;
    }
    wrefresh(menu_win);
}
/**
结果：
                         ┌────────────────────────────┐
                         │                            │
                         │ Choice 1                   │
                         │ Choice 2                   │
                         │ Choice 3                   │
                         │ Choice 4                   │
                         │ Exit                       │
                         │                            │
                         │                            │
                         └────────────────────────────┘
*/
//————————————————
//版权声明：本文为CSDN博主「Koma_Wong」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/Rong_Toa/article/details/80766785

