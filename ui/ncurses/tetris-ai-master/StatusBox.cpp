#include "StatusBox.h"
#include <ncurses.h>

StatusBox::StatusBox(int starty, int startx, int height, int width)
    : Box(starty, startx, height, width)
{
    mPiecePosY = 4;
    mPiecePosX = 4;
    mScorePosY = 12;
    mScorePosX = 4;
    SetBorder('*');
    mvwprintw(mCurWin, 2, 1, "next");
    mvwprintw(mCurWin, 10, 1, "score");
    wrefresh(mCurWin);
}

void StatusBox::UpdateNextPiece(const Piece& pie)
{
    for (int raw = 0; raw < 4; raw++)
        for (int col = 0; col < 4; col++) {
            if (pie.mBlocks[raw][col])
                mvwaddch(mCurWin, mPiecePosY+raw, mPiecePosX+col, '#');
            else
                mvwaddch(mCurWin, mPiecePosY+raw, mPiecePosX+col, ' ');
        }
    wrefresh(mCurWin);
}

void StatusBox::UpdateScore(const int& s)
{
    mvwprintw(mCurWin, mScorePosY, mScorePosX, "%d", s);
    wrefresh(mCurWin);
}

void StatusBox::ShowGameStop()
{
    mvwprintw(mCurWin, mPiecePosY, mPiecePosX, "GAME");
    mvwprintw(mCurWin, mPiecePosY+1, mPiecePosX, "OVER");
    wrefresh(mCurWin);
}
