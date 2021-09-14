#include <curses.h> 
#include <menu.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <ctype.h> 
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <termios.h>
#include <unistd.h>


#define TCATTR_ADD_ECHO(fd) \
    {\
        struct termios old, new;\
        if (tcgetattr (fd, &old) != 0) {\
            perror("tcgetattr.\n");\
        }\
        new = old;\
        new.c_lflag |= ECHO;\
        if (tcsetattr(fd, TCSAFLUSH, &new) != 0) {\
            perror("tcsetattr.\n");\
        }\
    }


struct frame_struct {
    WINDOW *scroll_win;
    WINDOW *box_win;
};

WINDOW *scroll_win_up, *box_win_up;
WINDOW *scroll_win_down, *box_win_down;



pthread_t thread_log, thread_input;

static void finish(int sig)
{
    endwin();
    exit(1);
}

#define TELNET_PREFIX   " >> "
#define LINE_SPACE(nspace) \
    ({\
        char __s[1024] = {0};\
        memset(__s, 0, sizeof(__s));\
        int __i;\
        for(__i=0;__i<nspace;__i++)\
            __s[__i]=' ';\
        __s;\
    })

//static void gotoxy(int x, int y)
//{
//    printf("%c[%d;%df", 0x1B, y, x);
//}
//
//#define posprintf(x,y,fmt...) ({int n=0;gotoxy(x,y);n=printf(fmt);n;})

void *thread_input_fn(void *arg)
{
    int row,col,i,n = 100;
    getmaxyx(stdscr,row,col);
    echo();
    
    char str[1024];
    while(1)
    {
        memset(str, 0, sizeof(str));
        mvprintw(LINES-2, 0,"%s", LINE_SPACE(n+sizeof(TELNET_PREFIX)));
        
        mvprintw(LINES-2, 0,TELNET_PREFIX);
        getstr(str); 
        
        n = strlen(str);
        wprintw(scroll_win_down, "%s\n",str, i%9);
        wrefresh(scroll_win_down);
    }
}

void *thread_log_fn(void *arg)
{
    int i;
    for(i=0;;i++)
    {
        if(i%20==0)
            sleep(1);
        wprintw(scroll_win_up, ">>\033[1;31m<<the string is >>\033[m<< %d \n",i%9);
        wrefresh(scroll_win_up);
    }
}

int main()
{
    int i;
    char ch;
    initscr();
    cbreak();
    noecho();
    nonl();

    int row,col;
    getmaxyx(stdscr,row,col);

    //(height, width, starty, startx);
    scroll_win_up=newwin(LINES/2-6,     COLS-6,     1,          3);
    box_win_up=newwin(LINES/2-2,        COLS-2,     0,          1);
    scroll_win_down=newwin(LINES/2-6,   COLS-6,     LINES/2,    3);
    box_win_down=newwin(LINES/2-2,      COLS-2,     LINES/2-1,  1);
    
    scrollok(scroll_win_up,2);
    scrollok(scroll_win_down,2);

    box(box_win_up, '|', '-');
    box(box_win_down, '|', '-');

    refresh();
    mvwprintw(box_win_up,0,2,"Std's log:");
    mvwprintw(box_win_down,0,2,"Telnet log:");
    
    wrefresh(box_win_up);
    wrefresh(box_win_down);
    
    pthread_create(&thread_input, NULL, thread_input_fn, NULL);
    pthread_create(&thread_input, NULL, thread_log_fn, NULL);
    
    signal(SIGINT, finish);
    signal(SIGQUIT, finish);

    int stdscr_fd = open(stdscr, "r");
    dup2(stdscr_fd, 0);

    while(1)
    {
        sleep(1);
//        char str[123] = {0};
//        scanf("%s", str);
//        printf("stdin: %s\n",str);
    }
}


