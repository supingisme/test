#ifndef TETRIS_BOX_H
#define TETRIS_BOX_H

#include <vector>
#include "Box.h"
#include "Piece.h"

class Piece;

class TetrisBox : public Box
{
public:
    TetrisBox(int starty, int startx, int height, int width);

    int Layout(int raw, int col) const;

    bool AddPiece(const Piece& pie);

    void ShowPiece(const Piece& pie);

    void ShowGameOver();

    int ClearFullLines();

    void ClearAllLines();

    bool IsFreeLines();

    ~TetrisBox();

private:
    void RefreshGrids();

private:
    int mGridsWidth;
    int mGridsHeight;
    std::vector<std::vector<int>> mGrids;
};

#endif
