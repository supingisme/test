#include "Piece.h"
#include "TetrisBox.h"
#include <ncurses.h>
#include <utility>
#include "stdlib.h"
#include "time.h"

Piece::Piece(int type, const TetrisBox& b)
    : cmBox(b), mShape(type)
{
    if (mShape == 0) {
        RandomShape();
    }
    else {
        SetShape(mShape);
    }
    mPosX = (b.mWidth- mBlocksWidth)/2;
    mPosY = 1;
}

Piece::Piece(const Piece& other)
    : mPosY(other.mPosY), mPosX(other.mPosX), 
      cmBox(other.cmBox), mShape(other.mShape)
{
    SetShape(other.mShape);
}

void Piece::Show()
{
    for (int i = mBlocksHeight-1; i >= 0; i--) {
        for (int j = mBlocksWidth-1; j >= 0; j--) {
            if (mBlocks[i][j] == 1) {
                mvwaddch(cmBox.mCurWin, mPosY+i, mPosX+j, '#');
            }
        }
    }
    wrefresh(cmBox.mCurWin);
}

Piece& Piece::operator=(const Piece& other) 
{
    mPosX = other.mPosX;
    mPosY = other.mPosY;
    SetShape(other.mShape);
    return *this;
}

void Piece::MoveDown()
{
    mPosY++;
    if (IsCollision()) {
        mPosY--;
        return;
    }

    for (int i = mBlocksHeight-1; i >= 0; i--) {
        for (int j = mBlocksWidth-1; j >= 0; j--) {
            if (mBlocks[i][j] == 1) {
                mvwaddch(cmBox.mCurWin, mPosY+i, mPosX+j, '#');
                mvwaddch(cmBox.mCurWin, mPosY+i-1, mPosX+j, ' ');
            }
        }
    }
    wrefresh(cmBox.mCurWin);
}

void Piece::MoveLeft()
{
    mPosX--;
    if (IsCollision()) {
        mPosX++;
        return;
    }

    for (int col = 0; col < mBlocksWidth; col++) {
        for (int raw = 0; raw < mBlocksHeight; raw++) {
            if (mBlocks[raw][col] == 1) {
                mvwaddch(cmBox.mCurWin, mPosY+raw, mPosX+col, '#');
                mvwaddch(cmBox.mCurWin, mPosY+raw, mPosX+col+1, ' ');
            }
        }
    }
    wrefresh(cmBox.mCurWin);
}

void Piece::MoveRight()
{
    mPosX++;
    if (IsCollision()) {
        mPosX--;
        return;
    }

    for (int col = mBlocksWidth-1; col >= 0; col--) {
        for (int raw = 0; raw < mBlocksHeight; raw++) {
            if (mBlocks[raw][col] == 1) {
                mvwaddch(cmBox.mCurWin, mPosY+raw, mPosX+col, '#');
                mvwaddch(cmBox.mCurWin, mPosY+raw, mPosX+col-1, ' ');
            }
        }
    }
    wrefresh(cmBox.mCurWin);
}



void Piece::Rotate() {
    int btmp[mBlocksHeight][mBlocksWidth];
    int braw = 0;
    int bcol = 0;
    for (int raw = mBlocksHeight-1; raw >= 0; raw--) {
        for (int col = 0; col < mBlocksWidth; col++) {
            btmp[braw][bcol] = mBlocks[raw][col];
            braw++;
        }
        bcol++;
        braw = 0;
    }

    for (int raw = 0; raw < mBlocksHeight; raw++) {
        for (int col = 0; col < mBlocksWidth; col++) {
            std::swap(mBlocks[raw][col], btmp[raw][col]);
        }
    }

    if (IsCollision()) {
        for (int raw = 0; raw < mBlocksHeight; raw++) {
            for (int col = 0; col < mBlocksWidth; col++) {
                std::swap(mBlocks[raw][col], btmp[raw][col]);
            }
        }
        return;
    }
    else {
        for (int raw = 0; raw < mBlocksHeight; raw++) {
            for (int col = 0; col < mBlocksWidth; col++) {
                mvwaddch(cmBox.mCurWin,mPosY+raw, mPosX+col, ' ');
                if (mBlocks[raw][col] == 1)
                    mvwaddch(cmBox.mCurWin, mPosY+raw, mPosX+col, '#');
            }
        }
    }
    wrefresh(cmBox.mCurWin);
}

void Piece::ResetPos()
{
    mPosX = (cmBox.mWidth- mBlocksWidth)/2;
    mPosY = 1;
}

bool Piece::smIsFirstRandom = true;

void Piece::RandomShape()
{
    if (smIsFirstRandom) {
        srand(time(NULL));
        smIsFirstRandom = false;
    }
    int r = random()%7 + 1;
    SetShape(r);
}

bool Piece::IsCollision()
{
    for (int raw = 0; raw < mBlocksHeight; raw++) {
        for (int col = 0; col < mBlocksWidth; col++) {
            if (mBlocks[raw][col] == 1 && cmBox.Layout(mPosY+raw, mPosX+col) == 1) {
                    return true;
            }
        }
    }
    return false;
}

bool Piece::ReachBottom()
{
    for (int raw = 0; raw < mBlocksHeight; raw++) {
        for (int col = 0; col < mBlocksWidth; col++) {
            if (mBlocks[raw][col] == 1 && cmBox.Layout(mPosY+raw+1, mPosX+col) == 1) {
                    return true;
            }
        }
    }
    return false;
}

void Piece::SetShape(int type) {
    this->mShape = type;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mBlocks[i][j] = 0;
        }
    }

    switch(type)
    {
        case 1:    
            mBlocksHeight=4;
            mBlocksWidth=4;    
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            mBlocks[1][2]=1;
            mBlocks[1][3]=1;
            break;
        case 2:
            mBlocksHeight=3;
            mBlocksWidth=3;
            mBlocks[0][0]=1;
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            mBlocks[1][2]=1;
            break;
        case 3:
            mBlocksHeight=3;
            mBlocksWidth=3;    
            mBlocks[0][2]=1;
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            mBlocks[1][2]=1;
            break;
        case 4:
            mBlocksHeight=2;
            mBlocksWidth=2;
            mBlocks[0][0]=1;
            mBlocks[0][1]=1;
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            break;
        case 5:
            mBlocksHeight=3;
            mBlocksWidth=3;
            mBlocks[0][1]=1;
            mBlocks[0][2]=1;
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            break;
        case 6:    
            mBlocksHeight=3;
            mBlocksWidth=3;
            mBlocks[0][1]=1;
            mBlocks[1][0]=1;
            mBlocks[1][1]=1;
            mBlocks[1][2]=1;
            break;
        case 7:    
            mBlocksHeight=3;
            mBlocksWidth=3;
            mBlocks[0][0]=1;
            mBlocks[0][1]=1;
            mBlocks[1][1]=1;
            mBlocks[1][2]=1;
            break;
    }
}
