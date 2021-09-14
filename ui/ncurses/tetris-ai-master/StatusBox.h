#ifndef STATUS_BOX_H
#define STATUS_BOX_H

#include "Box.h"
#include "Piece.h"

class StatusBox : public Box
{
public:
    StatusBox(int starty, int startx, int height, int width);

    void UpdateNextPiece(const Piece& pie);
    
    void UpdateScore(const int& s);

    void ShowGameStop();

private:
    int mPiecePosX;
    int mPiecePosY;
    int mScorePosX;
    int mScorePosY;
};

#endif
