#include "TetrisBox.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <ncurses.h>

using namespace std;

TetrisBox::TetrisBox(int starty, int startx, int height, int width)
    : Box(starty, startx, height, width),
      mGrids(height-2, vector<int>(width-2, 0))
{
    SetBorder('*');
}

int TetrisBox::Layout(int raw, int col) const
{
    int gridsRaw = raw - 1;
    int gridsCol = col - 1;
    if (gridsRaw < 0 || gridsCol < 0)
        return 1;
    if (gridsRaw >= mHeight-2 || gridsCol >= mWidth-2)
        return 1;
    return mGrids[gridsRaw][gridsCol];
}

bool TetrisBox::AddPiece(const Piece& pie)
{
    for (int raw = 0; raw < pie.mBlocksHeight; raw++) {
        for (int col = 0; col < pie.mBlocksWidth; col++) {
            int gY = pie.mPosY + raw - 1;
            int gX = pie.mPosX + col - 1;
            
            if (gY < mHeight-2 && gX < mWidth-2 && gX >= 0 && gY >= 0) {
                mGrids[gY][gX] |= pie.mBlocks[raw][col];
                if (gY == 0 && mGrids[gY][gX] == 1)
                    return false;
            }
        }
    }
    return true;
}

bool TetrisBox::IsFreeLines()
{
    for (int col = 0; col < mWidth-2; col++) {
        if (mGrids[0][col])
            return false;
    }
    return true;
}

void TetrisBox::ClearAllLines()
{
    int gridsWidth = mWidth - 2;
    int gridsHeight = mHeight - 2;
    for (int row = 0; row < gridsHeight; row++) {
        for (int col = 0; col < gridsWidth; col++) {
            mGrids[row][col] = 0;
            mvwaddch(mCurWin, row+1, col+1, ' ');
        }
    }
    wrefresh(mCurWin);
}

int TetrisBox::ClearFullLines()
{
    int gridsWidth = mWidth - 2;
    int gridsHeight = mHeight - 2;
    bool isFull = true;
    vector<int> fullLines(gridsHeight, 0);
    int fullLinesCount = 0;

    for (int r = 0; r < gridsHeight; r++) {
        isFull = true;
        for (int c = 0; c < gridsWidth; c++) {
            if (mGrids[r][c] == 0)
                isFull = false;
        }
        if (isFull) {
            fullLines[r] = 1;
            fullLinesCount++;
        }
    }
   
    int notFull = gridsHeight-1;
    for (int r = gridsHeight-1; r >= 0; r--) {
        if (fullLines[r] == 0) {
            for (int c = 0; c < gridsWidth; c++) {
                mGrids[notFull][c] = mGrids[r][c];
            }
            notFull--;
        }
    }
    while (notFull > 0) {
        for (int c = 0; c < gridsWidth; c++)
            mGrids[notFull][c] = 0;
        notFull--;
    }

    RefreshGrids();
    
    return fullLinesCount;
}

void TetrisBox::RefreshGrids()
{
    int gridsWidth = mWidth - 2;
    int gridsHeight = mHeight - 2;
    for (int row = 0; row < gridsHeight; row++) {
        for (int col = 0; col < gridsWidth; col++) {
            if (mGrids[row][col])
                mvwaddch(mCurWin, row+1, col+1, '#');
            else
                mvwaddch(mCurWin, row+1, col+1, ' ');
        }
    }
}

void TetrisBox::ShowGameOver()
{
    mvwprintw(mCurWin, 7, 4, "GAME");
    mvwprintw(mCurWin, 8, 4, "OVER");
    mvwprintw(mCurWin, 10, 3, "q:quit");
    mvwprintw(mCurWin, 11, 2, "r:replay");

    wrefresh(mCurWin);
}

TetrisBox::~TetrisBox()
{
}

