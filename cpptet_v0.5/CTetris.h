#pragma once
#include "Tetris.h"

class CTetris : public Tetris {
public:
    static Matrix** setOfCBlockObjects; 

    Matrix* iCScreen;
    Matrix* oCScreen;
    Matrix currCBlk;

    CTetris(int dy, int dx);
    ~CTetris();
    void init(int **setOfBlockArrays, int nBlockTypes, int nBlockDegrees);
    TetrisState accept(char key);
    void deleteFullLines();
};
