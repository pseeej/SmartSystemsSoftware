#pragma once
#include "Matrix.h"

enum TetrisState { Running, NewBlock, Finished };

class Tetris {
private:
    TetrisState state;
    bool justStarted;
    int nBlockTypes = 0;
    int nBlockDegrees = 0;
    int idxBlockDegree;
    int idxBlockColor;

    char* ColorLists[8];

    Matrix iScreen;
    Matrix oScreen;
    int iScreenDw = 0;  // largest enough to cover the largest block
    int iScreenDx;
    int iScreenDy;

    Matrix arrayScreen;
    int arrayScreenDx;
    int arrayScreenDy;

    Matrix currBlk;
    Matrix tempBlk;

    int top;
    int left;
public:
    Tetris();
    ~Tetris();
    Matrix createArrayScreen();

    // argument Matrix *matrix deleted;
    TetrisState accept(char key);
    void deleteFullLines();

    int** initSetOfBlockArrays();
};
