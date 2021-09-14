#ifndef BOX_H
#define BOX_H

#include <ncurses.h>

class Box {

public:
    Box(int starty, int startx, int height, int width);
    virtual ~Box();
    
    void SetBorder(const char bor = 0);

private:
    WINDOW* CreateNewWin(int h, int w, int y, int x);
    void DestroyWin(WINDOW* win);

public:
    int mStartY;
    int mStartX;
    int mHeight;
    int mWidth;

    WINDOW* mCurWin;

};
#endif
