#include "CTetris.h"

Matrix** CTetris::setOfCBlockObjects; 

CTetris::CTetris(int dy, int dx) : Tetris(dy, dx){
    arrayScreen = createArrayScreen();
    iCScreen = new Matrix(arrayScreen, iScreenDw+dy, iScreenDx+dx);
    oCScreen = iCScreen;
}

CTetris::~CTetris(){
    ;
}

void CTetris::init(int **setOfBlockArrays, int nBlockTypes, int nBlockDegrees){
    Tetris::init(setOfBlockArrays, nBlockTypes, nBlockDegrees);

    for(int i=0;i<nBlockTypes;i++){
        for(int j=0;j<nBlockDegrees;j++){
            Matrix obj = Matrix(setOfBlockObjects[i][j]);
            obj.mulc(i+1);
            setOfCBlockObjects[i][j] = obj;
        }
    }
}

TetrisState CTetris::accept(char key){
    if(key>='0' && key<='6'){
        if(justStarted == 0)
            deleteFullLines();
        iCScreen = new Matrix(oCScreen);
    }

    state = Tetris::accept(key);

    currCBlk = setOfCBlockObjects[idxBlockType][idxBlockDegree];
    tempBlk = iCScreen->clip(top, left, top+currCBlk.get_dy(), left+currCBlk.get_dx());
    tempBlk = tempBlk.add(&currCBlk);

    oCScreen = new Matrix(iCScreen);
    oCScreen->paste(&tempBlk, top, left);

    return state;
}

void CTetris::deleteFullLines(){
    int** array = oCScreen->get_array();
    int cnt=0;

    for(int i=0; i<oCScreen->get_dy()-iScreenDw;i++){
        for(int j=iScreenDw;j<oCScreen->get_dx()-this->iScreenDw;j++)
            if (array[i][j] >= 1)
                cnt++;
        
        if(cnt == oCScreen->get_dx()-this->iScreenDw-this->iScreenDw){
            for(int j=this->iScreenDw;j<oCScreen->get_dx()-this->iScreenDw;j++)
                array[i][j] =0;
            
            for(int j=i;j>1;j--){
                for(int k=this->iScreenDw; k<this->oCScreen->get_dx()-this->iScreenDw; k++)
                    array[j][k] = array[j-1][k];
            }

            cnt = 0;
        }
    }

    oCScreen = new Matrix(*array, oCScreen->get_dx(), oCScreen->get_dy());
}