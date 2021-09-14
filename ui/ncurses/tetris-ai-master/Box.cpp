#include "Box.h"
#include <ncurses.h>

Box::Box(int starty, int startx, int height, int width)
    : mStartY(starty), mStartX(startx),
      mHeight(height), mWidth(width)
{
    mCurWin = CreateNewWin(height, width, starty, startx);
}

Box::~Box()
{
    DestroyWin(mCurWin);
}

WINDOW* Box::CreateNewWin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx); 
    wrefresh(local_win);
    return local_win;
}

void Box::DestroyWin(WINDOW* win)
{
    
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(win);
    delwin(win);
}

void Box::SetBorder(const char bor)
{
    if (bor == 0)
        box(mCurWin, 0, 0);
    else 
        wborder(mCurWin, bor, bor, bor, bor, bor, bor, bor, bor);
    wrefresh(mCurWin);
}
