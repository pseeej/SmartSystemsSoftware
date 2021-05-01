#pragma once
#include "Matrix.h"

#define color_black "\033[37m"
#define color_red "\033[31m"
#define color_green "\033[32m"
#define color_yellow "\033[33m"
#define color_blue "\033[34m"
#define color_purple "\033[35m"
#define color_cyan "\033[36m"
#define color_pink "\033[95m"

enum TetrisState { Running, NewBlock, Finished };

class Tetris {
private:
    TetrisState state;
    int justStarted;
    int nBlockTypes = 0;
    int nBlockDegrees = 0;
    int idxBlockDegree;
    int idxBlockColor;
    int idxBlockType;

    char* ColorLists[8];
    int** setOfBlockArrays;
    int** setOfBlockObjects;

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

    void initSetOfBlockArrays();
    void initColorLists();
};
