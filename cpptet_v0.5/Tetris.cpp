#include "Tetris.h"

void Tetris::initSetOfBlockArrays(){
    int block10[] = {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, -1};
    // int block11[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, -1};
    // int block12[] = {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1};
    // int block13[] = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1};

    int block20[] = {2, 0, 0, 2, 2, 2, 0, 0, 0, -1};
    // int block21[] = {0, 2, 2, 0, 2, 0, 0, 2, 0, -1};
    // int block22[] = {0, 0, 0, 2, 2, 2, 0, 0, 2, -1};
    // int block23[] = {0, 2, 0, 0, 2, 0, 2, 2, 2, -1};

    int block30[] = {0, 0, 3, 3, 3, 3, 0, 0, 0, -1};
    // int block31[] = {0, 3, 0, 0, 3, 0, 0, 3, 3, -1};
    // int block32[] = {0, 0, 0, 3, 3, 3, 3, 0, 0, -1};
    // int block33[] = {3, 3, 0, 0, 3, 0, 0, 3, 0, -1};

    int block40[] = {4, 4, 4, 4, -1};
    // int block41[] = {4, 4, 4, 4, -1};
    // int block42[] = {4, 4, 4, 4, -1};
    // int block43[] = {4, 4, 4, 4, -1};

    int block50[] = {0, 5, 5, 5, 5, 0, 0, 0, 0, -1};
    // int block51[] = {0, 5, 0, 0, 5, 5, 0, 0, 5, -1};
    // int block52[] = {0, 0, 0, 0, 5, 5, 5, 5, 0, -1};
    // int block53[] = {5, 0, 0, 5, 5, 0, 0, 5, 0, -1};

    int block60[] = {0, 6, 0, 6, 6, 6, 0, 0, 0, -1};
    // int block61[] = {0, 6, 0, 0, 6, 6, 0, 6, 0, -1};
    // int block62[] = {0, 0, 0, 6, 6, 6, 0, 6, 0, -1};
    // int block63[] = {0, 6, 0, 6, 6, 0, 0, 6, 0, -1};

    int block70[] = {7, 7, 0, 0, 7, 7, 0, 0, 0, -1};
    // int block71[] = {0, 0, 7, 0, 7, 7, 0, 7, 0, -1};
    // int block72[] = {0, 0, 0, 7, 7, 0, 0, 7, 7, -1};
    // int block73[] = {0, 7, 0, 7, 7, 0, 7, 0, 0, -1};

    int* setOfBlockArrays[] = {
        block10, //block11, block12, block13,
        block20, //block21, block22, block23,
        block30, //block31, block32, block33,
        block40, //block41, block42, block43,
        block50, //block51, block52, block53,
        block60, //block61, block62, block63,
        block70, //block71, block72, block73
    };

}

Tetris::Tetris(){
  
    nBlockTypes = sizeof(setOfBlockArrays);
    nBlockDegrees = sizeof(setOfBlockArrays[0]);

    for(int i=0;i<nBlockTypes;i++)
        for(int j=0;j<nBlockDegrees;j++)
            setOfBlockObjects[i][j] = 0;
    
    int arrayBlk_maxSize = 0;

    for(int i=0;i<nBlockTypes;i++){
        if (arrayBlk_maxSize <= (sizeof(setOfBlockArrays[i][0])/sizeof(int)))
            arrayBlk_maxSize = (sizeof(setOfBlockArrays[i][0])/sizeof(int));
    }

    iScreenDw = arrayBlk_maxSize;

    for(int i=0;i<nBlockTypes;i++)
        for(int j=0;j<nBlockDegrees;j++)
            setOfBlockObjects[i][j] = Matrix(setOfBlockArrays[i][j]);

    iScreenDy = iScreenDy;
    iScreenDx = iScreenDx;
    idxBlockDegree = 0;
    arrayScreen = createArrayScreen();
    iScreen = Matrix(arrayScreen);
    oScreen = Matrix(iScreen);
    justStarted = 1;
}

TetrisState Tetris::accept(char key){

        state = Running;

        if (key >= '0' & key <= '6'){
            if (justStarted == 0)
                deleteFullLines();
            iScreen = Matrix(oScreen);
            idxBlockType = int(key-'0');
            idxBlockDegree = 0;
            idxBlockColor = idxBlockType + 1;

            currBlk = setOfBlockObjects[idxBlockType][idxBlockDegree];
            currBlk = currBlk.binary();
            currBlk.mulc(idxBlockColor);

            top = 0;
            left = iScreenDw + iScreenDx/2 - currBlk.get_dx()/2;
            
            tempBlk = iScreen.clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
            tempBlk = tempBlk.binary();
            tempBlk.paste(currBlk, top, left);  // = tempBlk + currBlk;

            justStarted = 0;
            cout << endl;

            if (tempBlk.anyGreaterThan(idxBlockColor))
                state = Finished;
            oScreen = Matrix(iScreen);
            oScreen.paste(tempBlk, top, left);

            //Tetris.tempBlk = Tetris.tempBlk.binary()
            tempBlk.paste(currBlk, top, left);  // = tempBlk + currBlk;

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
            currBlk = currBlk.binary();
            currBlk.mulc(idxBlockColor);
        }
        else if (key == ' '){
            while !(tempBlk.anyGreaterThan(idxBlockColor)){
                    top += 1;
                    tempBlk = iScreen.clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
                    tempBlk = tempBlk.binary();
                    tempBlk.paste(currBlk, top, left); // = tempBlk + currBlk;
            }
        }
        else
            cout << "Wrong key!!!\n";
            
        tempBlk = iScreen.clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
        tempBlk = tempBlk.binary();
        tempBlk.paste(currBlk, top, left);  // = tempBlk + currBlk;

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
                currBlk = currBlk.binary();
                currBlk.mulc(idxBlockColor);
            }
            else if (key == ' '){ // undo: move up
                top -= 1;
                state = NewBlock;
            }

            tempBlk = iScreen.clip(top, left, top+currBlk.get_dy(), left+currBlk.get_dx());
            tempBlk.paste(currBlk, top, left); // = tempBlk + currBlk;
        }

        oScreen = Matrix(iScreen);
        oScreen.paste(tempBlk, top, left);

        return state;


}
    // iScreen, oScreen, currBlk can have int nums(0~7) for arguments

// delete lines
void deleteFullLines(){
        int nDeleted = 0;
        int nScanned = currBlk.get_dy();

        if (top + currBlk.get_dy() - 1 >= iScreenDy)
            nScanned -= (top + currBlk.get_dy - iScreenDy);

        int zero[iScreenDx - 2*iScreenDw][iScreenDx - 2*iScreenDw] = {0,};

        for (int i=nScanned-1;i>-1;i--){
            int cy = top + y + nDeleted;

            Matrix line = oScreen.clip(cy, 0, cy+1, oScreen.get_dx());

            int sum=0;
            for(int i=0;i<oScreen.get_dx();i++)
                sum += line[cy][i];

            if (sum == oScreen.get_dx()){
                // Tetris Screen
                Matrix temp = oScreen.clip(0, 0, cy, oScreen.get_dx());
                oScreen.paste(temp, 1, 0);
                oScreen.paste(zero, 0, iScreenDw);

                // CTetris Screen
                temp = oCScreen.clip(0, 0, cy, oCScreen.get_dx());
                oCScreen.paste(temp, 1, 0);
                oCScreen.paste(zero, 0, iScreenDw);

                nDeleted += 1;
            }
        }
    
        return;
}



Matrix createArrayScreen(){
        arrayScreenDx = iScreenDw * 2 + iScreenDx;
        arrayScreenDy = iScreenDy + iScreenDw;
        
        for(int i=0;i<arrayScreenDy;i++)
            for(int j=0;j<arrayScreenDx;j++)
                arrayScreen[i][j] = 0;
        
        for (int i=0;i<iSCreenDy;i++){
            for (int j=0;j<iScreenDw;j++)
                arrayScreen[y][x] = 1;
            for (int j=0;j<iSCreenDx;j++)
                arrayScreen[y][iScreenDw + x] = 0;
            for (int j=0;j<iScreenDw;j++)
                arrayScreen[y][iScreenDw + iScreenDx + x] = 1;
        }

        for (int i=0;i<iScreenDw;i++)
            for (int j=0;j<arrayScreenDx;j++)
                arrayScreen[iScreenDy + y][x] = 1;

        return arrayScreen;
}
