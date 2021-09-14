/*
https://blog.csdn.net/ccccce/article/details/51096167
Compile: gcc main.c -lncurses
*/
#include <curses.h>
#include <unistd.h>

void showstar(WINDOW * win, const int line);

int main(void)
{
    int key;
    int quit = 0;
    MEVENT mouse;
    WINDOW * win;

    initscr();
    raw();
    win = newwin(10, 50, 5, 3);     /*this must do before keypad*/
    keypad(win, TRUE);              /*then use win.*/
    mousemask(BUTTON1_CLICKED | BUTTON2_CLICKED, 0);    /*set actions*/
    box(win, '|', '-');
    mvwaddch(win, 1, 48, 'X');
    mvwaddstr(win, 3, 3, "Test 1");
    mvwaddstr(win, 4, 3, "Test 2");
    mvwaddstr(win, 5, 3, "Test 3");
    wrefresh(win);

    while (!quit)
    {
        key = wgetch(win);
        switch(key)
        {
            case KEY_MOUSE : 
                getmouse(&mouse); /*get mouse action*/

                if (!wenclose(win, mouse.y, mouse.x)) 
                    break; /*do nothing if not in window*/

                wmouse_trafo(win, &mouse.y, &mouse.x, FALSE);

                if ((3 <= mouse.x && mouse.x <= 8) 
                 && (3 <= mouse.y && mouse.y <= 5))
                    showstar(win, mouse.y);

                if (1 == mouse.y && 48 == mouse.x) /*Clicked 'X'*/
                    quit = 1;

                break;
            case 'q' :
                quit = 1;
                break;
            default :
                break;
        }
    }

    delwin(win);
    endwin();
    return 0;
}

void showstar(WINDOW * win, const int line)
{
    mvwaddch(win, line, 2, '*');
    wrefresh(win);
}

