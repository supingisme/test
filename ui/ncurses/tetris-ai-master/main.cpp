#include <ncurses.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>

#include "TetrisBox.h"
#include "StatusBox.h"
#include "Piece.h"

#include <time.h>
#include <sys/time.h>
#include <signal.h>

#define FRAME_ORIGIN_X 1
#define FRAME_ORIGIN_Y 1
#define FRAME_WIDTH 12
#define FRAME_HEIGHT 18

void InitCurses()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
}

void RestartGame(Piece& curPiece, Piece& nextPiece, 
        TetrisBox& gameBox, StatusBox& statusBox)
{

    gameBox.ClearAllLines();

    curPiece.RandomShape();
    curPiece.ResetPos();
    nextPiece.RandomShape();
    statusBox.UpdateNextPiece(nextPiece);
    statusBox.UpdateScore(0);
}


int main()
{
    InitCurses();

    TetrisBox gameBox(FRAME_ORIGIN_Y, FRAME_ORIGIN_X, FRAME_HEIGHT, FRAME_WIDTH);
    StatusBox statusBox(FRAME_ORIGIN_Y, FRAME_ORIGIN_X+FRAME_WIDTH-1, 
            FRAME_HEIGHT, FRAME_WIDTH);

    Piece curPiece(0, gameBox);
    Piece nextPiece(0, gameBox);
    int score = 0;
    bool gameStop = false;
    bool gameOver = false;


    fd_set read_fds;
    FD_ZERO(&read_fds);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    RestartGame(curPiece, nextPiece, gameBox, statusBox);
    
    while (!gameOver) {
        
        while (gameStop) {
            char key = getch();
            if (key == 'q') {
                gameOver = true;
                gameStop = false;
            }
            else if (key == 'r') {
                gameStop = false;
                RestartGame(curPiece, nextPiece, gameBox, statusBox);
            }
        }

        FD_SET(0, &read_fds);
        int ret = select(1, &read_fds, NULL, NULL, &tv);
       
        if (ret == 0) {
            
            if (curPiece.ReachBottom()) {
                gameBox.AddPiece(curPiece);
                int clearLines = gameBox.ClearFullLines();
                if (clearLines > 0) {
                    score += clearLines;
                    statusBox.UpdateScore(score);
                }
                if (!gameBox.IsFreeLines()) {
                    gameBox.ShowGameOver();
                    gameStop = true;
                }
                else {
                    curPiece = nextPiece;
                    curPiece.ResetPos();
                    nextPiece.RandomShape();
                    statusBox.UpdateNextPiece(nextPiece);
                }
                curPiece.Show();
            }
            else {
                curPiece.MoveDown();
            }
            
            tv.tv_sec = 1;
            tv.tv_usec = 0;
        }
        else if (ret > 0 && FD_ISSET(0, &read_fds)) {
            int key = getch();
            
            switch (key) {
                case KEY_UP:
                    curPiece.Rotate();
                    break;
                case KEY_DOWN:
                    curPiece.MoveDown();
                    break;
                case KEY_LEFT:
                    curPiece.MoveLeft();
                    break;
                case KEY_RIGHT:
                    curPiece.MoveRight();
                    break;
            }            
        } 
    }
    
    endwin();
    return 0;
}
