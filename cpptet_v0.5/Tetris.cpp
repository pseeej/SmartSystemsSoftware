#include "Tetris.h"
#include <cmath>
int Tetris::nBlockTypes = 0;
int Tetris::nBlockDegrees = 0;
int Tetris::iScreenDw = 0;
Matrix** Tetris::setOfBlockObjects;


Tetris::Tetris(int dy, int dx){
    this->iScreenDy = dy;
    this->iScreenDx = dx;
    idxBlockDegree = 0;
    arrayScreen = createArrayScreen();
    iScreen = new Matrix(arrayScreen, arrayScreenDy, arrayScreenDx);
    oScreen = iScreen;
    justStarted = 1;
}

void Tetris::init(int **setOfBlockArrays, int nBlockTypes, int nBlockDegrees){

    this->nBlockDegrees = nBlockDegrees;
    this->nBlockTypes = nBlockTypes;
    
    int* sizeArray = new int[nBlockTypes];
    int arrayBlk_maxSize = 0;

    for(int i=0;i<nBlockTypes;i++){
        int temp;
        while(setOfBlockArrays[i*nBlockDegrees][temp]!=-1)
            temp+=1;

        if(int(sqrt(temp))>arrayBlk_maxSize)
            arrayBlk_maxSize = int(sqrt(temp));
        
        sizeArray[i] = sqrt(temp);
    }

    iScreenDw = arrayBlk_maxSize;

    setOfBlockObjects = new Matrix*[nBlockTypes];
    for(int i=0;i<nBlockTypes;i++)
        setOfBlockObjects[i] = new Matrix[nBlockDegrees];

    for(int i=0;i<nBlockTypes;i++)
        for(int j=0;j<nBlockDegrees;j++)
            setOfBlockObjects[i][j] = Matrix(setOfBlockArrays[nBlockDegrees*i+j], sizeArray[i], sizeArray[i]);

    delete[] sizeArray;
}

TetrisState Tetris::accept(char key){

        state = Running;

        if (key >= '0' && key <= '6'){
            if (justStarted == 0)
                deleteFullLines();
            iScreen = new Matrix(oScreen);
            idxBlockType = int(key-'0');
            idxBlockDegree = 0;
            idxBlockColor = idxBlockType + 1;

            currBlk = setOfBlockObjects[idxBlockType][idxBlockDegree];
            //currBlk = currBlk.binary();
            //currBlk.mulc(idxBlockColor);

            top = 0;
            left = iScreenDw + iScreenDx/2 - currBlk.get_dx()/2;
            
            tempBlk = iScreen->clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
            //tempBlk = tempBlk.binary();
            tempBlk = tempBlk.add(&currBlk);  // = tempBlk + currBlk;

            justStarted = 0;
            cout << endl;

            if (tempBlk.anyGreaterThan(idxBlockColor))
                state = Finished;
            oScreen = new Matrix(iScreen);
            oScreen->paste(&tempBlk, top, left);

            //Tetris.tempBlk = Tetris.tempBlk.binary()

            return state;
        }
        else if ( key == 'q' )
            return Finished;
        else if ( key == 'a')
            left -= 1;
        else if ( key == 'd' )
            left += 1;
        else if ( key == 's' )
            top += 1;
        else if ( key == 'w') {
            idxBlockDegree = (idxBlockDegree + 1) % nBlockDegrees;
            currBlk = setOfBlockObjects[idxBlockType][idxBlockDegree];
            //currBlk = currBlk.binary();
            //currBlk.mulc(idxBlockColor);
        }
        else if (key == ' '){
            while (!tempBlk.anyGreaterThan(idxBlockColor)){
                    top += 1;
                    tempBlk = iScreen->clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
                    //tempBlk = tempBlk.binary();
                    tempBlk = tempBlk.add(&currBlk);
            }
        }
        else
            cout << "Wrong key!!!\n";
            
        tempBlk = iScreen->clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
        //tempBlk = tempBlk.binary();
        tempBlk = tempBlk.add(&currBlk);  // = tempBlk + currBlk;

        if (tempBlk.anyGreaterThan(idxBlockColor)){
            if (key == 'a') // undo: move right
                left += 1;
            else if (key == 'd') // undo: move left
                left -= 1;
            else if (key == 's'){ // undo: move up
                top -= 1;
                state = NewBlock;
            }
            else if (key == 'w'){ // undo: rotate the block counter-clockwise
                idxBlockDegree = (idxBlockDegree - 1) % nBlockDegrees;
                currBlk = setOfBlockObjects[idxBlockType][idxBlockDegree];
                //currBlk = currBlk.binary();
                //currBlk.mulc(idxBlockColor);
            }
            else if (key == ' '){ // undo: move up
                top -= 1;
                state = NewBlock;
            }

            tempBlk = iScreen->clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
            tempBlk = tempBlk.add(&currBlk); // = tempBlk + currBlk;
        }

        oScreen = new Matrix(iScreen);
        oScreen->paste(&tempBlk, top, left);

        return state;


}

Tetris::~Tetris(){
    ;
}

// delete lines

void Tetris::deleteFullLines(){
    int** array = oScreen->get_array();
    int cnt=0;

    for(int i=0; i<oScreen->get_dy()-iScreenDw;i++){
        for(int j=iScreenDw;j<oScreen->get_dx()-this->iScreenDw;j++)
            if (array[i][j] >= 1)
                cnt++;
        
        if(cnt == oScreen->get_dx()-this->iScreenDw-this->iScreenDw){
            for(int j=this->iScreenDw;j<oScreen->get_dx()-this->iScreenDw;j++)
                array[i][j] =0;
            
            for(int j=i;j>1;j--){
                for(int k=this->iScreenDw; k<this->oScreen->get_dx()-this->iScreenDw; k++)
                    array[j][k] = array[j-1][k];
            }

            cnt = 0;
        }
    }

    oScreen = new Matrix(*array, oScreen->get_dx(), oScreen->get_dy());
}

// void Tetris::deleteFullLines(){
//         int nDeleted = 0;
//         int nScanned = currBlk.get_dy();

//         if ((top + nScanned - 1) >= this->iScreenDy)
//             nScanned -= (this->top + currBlk.get_dy() - iScreenDy);

//         int** zero = new int*[this->iScreenDx - 2*this->iScreenDw];
//         for(int i=0;i<this->iScreenDx - 2*this->iScreenDw;i++)
//             zero[i] = new int [this->iScreenDx - 2*this->iScreenDw];

//         for(int i=0;i<this->iScreenDx - 2*this->iScreenDw;i++)
//             for(int j=0;j<this->iScreenDx - 2*this->iScreenDw;j++)
//                 zero[i][j] = 0;
        

//         for (int i=nScanned-1;i>-1;i--){
//             int cy = this->top + i + nDeleted;

//             Matrix line = oScreen->clip(cy, 0, cy+1, oScreen->get_dx());

//             int sum=0;
//             for(int i=0;i<oScreen->get_dx();i++)
//                 sum += line[cy][i];

//             if (sum == oScreen->get_dx()){
//                 // Tetris Screen
//                 Matrix temp = oScreen->clip(0, 0, cy, oScreen->get_dx());
//                 oScreen->paste(&temp, 1, 0);
//                 oScreen->paste(zero, 0, iScreenDw);

//                 // CTetris Screen
//                 // temp = oCScreen->clip(0, 0, cy, oCScreen->get_dx());
//                 // oCScreen->paste(temp, 1, 0);
//                 // oCScreen->paste(zero, 0, iScreenDw);

//                 nDeleted += 1;
//             }
//         }
    
//         return;
// }



int* Tetris::createArrayScreen(){
        arrayScreenDx = iScreenDw * 2 + iScreenDx;
        arrayScreenDy = iScreenDy + iScreenDw;

        arrayScreen = new int[arrayScreenDy * arrayScreenDx];
        
        for(int i=0;i<arrayScreenDy;i++)
            for(int j=0;j<arrayScreenDx;j++)
                arrayScreen[i*arrayScreenDx + j] = 0;
        
        for (int i=0;i<iScreenDy;i++){
            for (int j=0;j<iScreenDw;j++)
                arrayScreen[i*arrayScreenDx + j] = 1;
            for (int j=0;j<iScreenDx;j++)
                arrayScreen[i*arrayScreenDx + iScreenDw + j] = 0;
            for (int j=0;j<iScreenDw;j++)
                arrayScreen[i*arrayScreenDx + iScreenDw + iScreenDx + j] = 1;
        }

        for (int i=0;i<iScreenDw;i++)
            for (int j=0;j<arrayScreenDx;j++)
                arrayScreen[(iScreenDy + i)*arrayScreenDx + j] = 1;

        return arrayScreen;
}
