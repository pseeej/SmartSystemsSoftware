#pragma once
#include "Matrix.h"

enum TetrisState { Running, NewBlock, Finished };

class Tetris {
public:
    TetrisState state;
    int justStarted;
    static int nBlockTypes;
    static int nBlockDegrees;
    int idxBlockDegree;
    int idxBlockColor;
    int idxBlockType;

    //char* ColorLists[8];
    //static Matrix setOfBlockArrays;
    static Matrix** setOfBlockObjects;

    Matrix* iScreen;
    Matrix* oScreen;
    static int iScreenDw;  // largest enough to cover the largest block
    int iScreenDx;
    int iScreenDy;

    int* arrayScreen;
    int arrayScreenDx;
    int arrayScreenDy;

    Matrix currBlk;
    Matrix tempBlk;

    int top;
    int left;
//public:
    Tetris(int dy, int dx);
    ~Tetris();
    int* createArrayScreen();
    void init(int **setOfBlockArrays, int nBlockTypes, int nBlockDegrees);

    // argument Matrix *matrix deleted;
    TetrisState accept(char key);
    void deleteFullLines();

};
