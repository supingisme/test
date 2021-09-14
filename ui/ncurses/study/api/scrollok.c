#include <curses.h> 
#include <menu.h> 
#include <stdlib.h> 
#include <ctype.h> 

#define N_ITEMS 10

int main(int argc, char *argv[]) 
{ 
        int i; 
        int ch; 
        int lines, cols; 
        WINDOW *win, *subwin; 
//        ITEM *items[N_ITEMS]; 
        MENU *mymenu; 
        time_t tm; 
        tm = time(NULL); 

        if(initscr() == NULL) { 
                perror("initcurs"); 
                exit(EXIT_FAILURE); 
        } 
        cbreak(); 
        noecho(); 
        curs_set(1); 

        keypad(stdscr, TRUE); 
        getmaxyx(stdscr, lines, cols); 
        win = newwin(lines, cols, 0, 0); 
        box(win, 0, 0); 

        wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); 
        wrefresh(win); 

        scrollok(win, TRUE); 
        wsetscrreg(win, 0, lines); 

        mvwprintw(win, 0, 16, "Press Ctrl-C or 'Q' to exit; "); 
        mvwprintw(win, 2, 16, "Date: %s", ctime(&tm)); 
        wrefresh(win); 

        int k = 0; 
        for(k = 0; k < 50; k ++){ 
                wprintw(win, "test\n"); 
        } 

        while(toupper(ch = wgetch(win)) != '\n') { 
        } 

        endwin(); 
        return 0; 
}
