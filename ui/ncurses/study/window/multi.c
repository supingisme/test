#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void* head_refresh(void *arg);
void* input_refresh(void *arg);
void* output_refresh(void *arg);
void* right_refresh(void *arg);
//class window
//{
//    friend void* head_refresh(void *arg);
//    friend void* input_refresh(void *arg);
//    friend void* output_refresh(void *arg);
//    friend void* right_refresh(void *arg);
//    public:
//    window()
//    {
//        initscr();
//
//        getmaxyx(stdscr,y,x);
//    }
//    void create_head()
//    {
//        head_window = newwin(4,x,0,0);
//        box(head_window,'.','.');
//        mvwprintw(head_window,4/2,x/3,"|Welcome to here|");
//    }
//    
//    void create_input()
//    {
//        input_window = newwin(y-5,x/2,5,0);
//        box(input_window,'.','.');
//        mvwprintw(input_window,1,0,"input:");
//    }
//    void create_output()
//    {
//        output_window = newwin((y-5)/2,x/2,5+(y-5)/2+1,x/2);
//        box(output_window,'.','.');
//        mvwprintw(output_window,1,0,"output:");
//    }
//
//    void create_right()
//    {
//        right_window = newwin((y-5)/2,x/2,5,x/2);
//        box(right_window,'.','.');
//        mvwprintw(right_window,1,0,"friend:");
//    }
//
//    ~window()
//    {
//        endwin();
//    }
//
//    private:
//    WINDOW *head_window;
//    WINDOW *input_window;
//    WINDOW *output_window;
//    WINDOW *right_window;
//    int x;
//    int y;
//};

struct window {
    WINDOW *head_window;
    WINDOW *input_window;
    WINDOW *output_window;
    WINDOW *right_window;
    int x;
    int y;
};

void _refresh(WINDOW *win)
{
    wrefresh(win);
    wgetch(win);
}

void* head_refresh(void *arg)
{
    struct window *win = (struct window*)arg;

    _refresh(win->head_window);

    return NULL;
}

void* input_refresh(void *arg)
{   
    struct window *win = (struct window*)arg;
    _refresh(win->input_window);
    return NULL;
}


void* output_refresh(void *arg)
{   
    struct window *win = (struct window*)arg;
    _refresh(win->output_window);
    return NULL;
}
void* right_refresh(void *arg)
{   
    struct window *win = (struct window*)arg;
    _refresh(win->right_window);
    return NULL;
}


int main()
{
    struct window win;
    
    initscr();
    getmaxyx(stdscr,win.y,win.x);

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>> x %d, y %d\n", win.x, win.y);

    win.head_window = newwin(4,win.x,0,0);
    box(win.head_window,'.','.');
    mvwprintw(win.head_window,4/2,win.x/3,"|Welcome to here|");

    win.input_window = newwin(win.y-5,win.x/2,5,0);
    box(win.input_window,'.','.');
    mvwprintw(win.input_window,1,0,"input:");

    win.output_window = newwin((win.y-5)/2,win.x/2,5+(win.y-5)/2+1,win.x/2);
    box(win.output_window,'.','.');
    mvwprintw(win.output_window,1,0,"output:");

    win.right_window = newwin((win.y-5)/2,win.x/2,5,win.x/2);
    box(win.right_window,'.','.');
    mvwprintw(win.right_window,1,0,"friend:");

    pthread_t head_id,input_id,output_id,right_id;

    pthread_create(&head_id,NULL,head_refresh,(void *)&win);
    pthread_create(&input_id,NULL,input_refresh,(void *)&win);
    pthread_create(&output_id,NULL,output_refresh,(void *)&win);
    pthread_create(&right_id,NULL,right_refresh,(void *)&win);

    
    pthread_join(head_id,NULL);
    pthread_join(input_id,NULL);
    pthread_join(output_id,NULL);
    pthread_join(right_id,NULL);

    getch();
    
    return 0;
}

