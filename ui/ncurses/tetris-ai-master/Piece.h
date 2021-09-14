#ifndef PIECE_H
#define PIECE_H

#include "TetrisBox.h"

class TetrisBox;

class Piece
{
public:
    Piece(int type, const TetrisBox& b);
    
    Piece(const Piece& pie);

    Piece& operator=(const Piece& pie);

    ~Piece() {}

    void Rotate();

    bool IsCollision();

    bool ReachBottom();

    void RandomShape();

    void Show();

    void MoveDown();

    void MoveLeft();

    void MoveRight();

    void ResetPos();

private:
    void SetShape(int type);

public:


    const TetrisBox& cmBox;

    int mBlocks[4][4];
    int mBlocksWidth;
    int mBlocksHeight;

    int mPosY;
    int mPosX;

private:
    int mShape;
    static bool smIsFirstRandom;
};
#endif
