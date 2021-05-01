#include "Tetris.h"

int** Tetris::initSetOfBlockArrays(){
    int block10[][] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
    int block11[][] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    int block12[][] = {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
    int block13[][] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    int block20[][] = {{2, 0, 0}, {2, 2, 2}, {0, 0, 0}};
    int block21[][] = {{0, 2, 2}, {0, 2, 0}, {0, 2, 0}};
    int block22[][] = {{0, 0, 0}, {2, 2, 2}, {0, 0, 2}};
    int block23[][] = {{0, 2, 0}, {0, 2, 0}, {2, 2, 2}};

    int block3[][] = {{0, 0, 3}, {3, 3, 3}, {0, 0, 0, 0}};
    int block3[][] = 

    int block4[4][4] = {{0, 0, 4, 4}, {0, 0, 4, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int block5[4][4] = {{0, 5, 5, 0}, {5, 5, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int block6[4][4] = {{0, 6, 0, 0}, {6, 6, 6, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int block7[4][4] = {{0, 7, 7, 0}, {0, 0, 7, 7}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    int** setOfBlockArrays[] = {block1, block2, block3, block4, block5, block6, block7};

    nBlocks = len(arrayBlks)
    setOfBlockArrays = [[0] * 4 for _ in range(nBlocks)]

    for idxBlockType in range(nBlocks):
        temp_array = arrayBlks[idxBlockType]
        setOfBlockArrays[idxBlockType][0] = temp_array
        for idxBlockDegree in range(1,4):
            temp_array = rotate(temp_array)
            setOfBlockArrays[idxBlockType][idxBlockDegree] = temp_array

}

Tetris::Tetris(){
    ColorLists = {"\033[37m", "\033[31m", "\033[32m", "\033[33m",
    "\033[34m", "\033[35m", "\033[36m", "\033[95m"};
  
    nBlockTypes = sizeof(setOfBlockArrays);
    nBlockDegrees = sizeof(setOfBlockArrays[0]);

    for(int i=0;i<nBlockTypes;i++)
        for(int j=0;j<nBlockDegrees;j++)
            setOfBlockObjects[i][j] = 0;
    
    arrayBlk_maxSize = 0;

    for(int i=0;i<Tetris.nBlockTypes;i++){
        if (arrayBlk_maxSize <= size(setOfBlockArrays[i][0]))
            arrayBlk_maxSize = size(setOfBlockArrays[i][0]);
    }

    Tetris.iScreenDw = arrayBlk_maxSize;

    for(int i=0;i<Tetris.nBlockTypes;i++)
        for(int j=0;j<Tetris.nBlockDegrees;j++)
            Tetris.setOfBlockObjects[i][j] = Matrix(setOfBlockArrays[i][j]);

    Tetris.iScreenDy = iScreenDy;
    Tetris.iScreenDx = iScreenDx;
    Tetris.idxBlockDegree = 0;
    Tetris.arrayScreen = Tetris.createArrayScreen();
    Tetris.iScreen = Matrix(Tetris.arrayScreen);
    Tetris.oScreen = Matrix(Tetris.iScreen);
    Tetris.justStarted = True;
}

TetrisState Tetris::accept(char key){

        Tetris.state = Running;

        if (key >= '0' & key <= '6'){
            if (Tetris.justStarted == False)
                Tetris.deleteFullLines();
            Tetris.iScreen = Matrix(Tetris.oScreen);
            Tetris.idxBlockType = int(key);
            Tetris.idxBlockDegree = 0;
            Tetris.idxBlockColor = Tetris.idxBlockType + 1;

            Tetris.currBlk = Tetris.setOfBlockObjects[Tetris.idxBlockType][Tetris.idxBlockDegree];
            Tetris.currBlk = Tetris.currBlk.binary();
            Tetris.currBlk.mulc(Tetris.idxBlockColor);

            top = 0;
            left = Tetris.iScreenDw + Tetris.iScreenDx/2 - Tetris.currBlk.get_dx()/2;
            
            Tetris.tempBlk = Tetris.iScreen.clip(top, left, top+Tetris.currBlk.get_dy(), left+Tetris.currBlk.get_dx());
            Tetris.tempBlk = tempBlk.binary();
            Tetris.tempBlk = Tetris.tempBlk + Tetris.currBlk;

            Tetris.justStarted = False;
            cout << endl;

            if (tempBlk.anyGreaterThan(Tetris.idxBlockColor))
                Tetris.state = Finished;
            Tetris.oScreen = Matrix(Tetris.iScreen);
            Tetris.oScreen.paste(Tetris.tempBlk, top, left);

            //Tetris.tempBlk = Tetris.tempBlk.binary()
            Tetris.tempBlk = Tetris.tempBlk + Tetris.currBlk;

            return Tetris.state;
        }
        else if ( key == 'q' )
            continue;
        else if ( key == 'a')
            Tetris.left -= 1;
        else if ( key == 'd' )
            Tetris.left += 1;
        else if ( key == 's' )
            Tetris.top += 1;
        else if ( key == 'w') {
            Tetris.idxBlockDegree = (Tetris.idxBlockDegree + 1) % Tetris.nBlockDegrees;
            Tetris.currBlk = Tetris.setOfBlockObjects[Tetris.idxBlockType][Tetris.idxBlockDegree];
            Tetris.currBlk = Tetris.currBlk.binary();
            Tetris.currBlk.mulc(Tetris.idxBlockColor);
        }
        else if (key == ' '){
            while !(Tetris.tempBlk.anyGreaterThan(Tetris.idxBlockColor)){
                    Tetris.top += 1;
                    Tetris.tempBlk = Tetris.iScreen.clip(Tetris.top, Tetris.left, Tetris.top+Tetris.currBlk.get_dy(), Tetris.left+Tetris.currBlk.get_dx());
                    Tetris.tempBlk = Tetris.tempBlk.binary();
                    Tetris.tempBlk = Tetris.tempBlk + Tetris.currBlk;
            }
        }
        else
            cout << "Wrong key!!!\n";
            
        Tetris.tempBlk = Tetris.iScreen.clip(Tetris.top, Tetris.left, Tetris.top+Tetris.currBlk.get_dy(), Tetris.left+Tetris.currBlk.get_dx());
        Tetris.tempBlk = Tetris.tempBlk.binary();
        Tetris.tempBlk = Tetris.tempBlk + Tetris.currBlk;

        if (Tetris.tempBlk.anyGreaterThan(Tetris.idxBlockColor)){
            if (key == 'a') // undo: move right
                Tetris.left += 1;
            else if (key == 'd') // undo: move left
                Tetris.left -= 1;
            else if (key == 's'){ // undo: move up
                Tetris.top -= 1;
                Tetris.state = NewBlock;
            }
            else if (key == 'w'){ // undo: rotate the block counter-clockwise
                Tetris.idxBlockDegree = (Tetris.idxBlockDegree - 1) % Tetris.nBlockDegrees;
                Tetris.currBlk = Tetris.setOfBlockObjects[Tetris.idxBlockType][Tetris.idxBlockDegree];
                Tetris.currBlk = Tetris.currBlk.binary();
                Tetris.currBlk.mulc(Tetris.idxBlockColor);
            }
            else if (key == ' '){ // undo: move up
                Tetris.top -= 1;
                Tetris.state = NewBlock;
            }

            Tetris.tempBlk = Tetris.iScreen.clip(Tetris.top, Tetris.left, Tetris.top+Tetris.currBlk.get_dy(), Tetris.left+Tetris.currBlk.get_dx());
            Tetris.tempBlk = Tetris.tempBlk + Tetris.currBlk;
        }

        Tetris.oScreen = Matrix(Tetris.iScreen);
        Tetris.oScreen.paste(Tetris.tempBlk, Tetris.top, Tetris.left);

        return Tetris.state;


}
    // iScreen, oScreen, currBlk can have int nums(0~7) for arguments

// delete lines
void deleteFullLines(){
        nDeleted = 0;
        nScanned = Tetris.currBlk.get_dy();

        if (Tetris.top + Tetris.currBlk.get_dy() - 1 >= Tetris.iScreenDy)
            nScanned -= (Tetris.top + Tetris.currBlk.get_dy - Tetris.iScreenDy);

        int zero[Tetris.iScreenDx - 2*Tetris.iScreenDw][Tetris.iScreenDx - 2*Tetris.iScreenDw] = {0,};

        for (int i=nScanned-1;i>-1;i--){
            int cy = Tetris.top + y + nDeleted;

            Matrix line = Tetris.oScreen.clip(cy, 0, cy+1, Tetris.oScreen.get_dx());

            int sum=0;
            for(int i=0;i<Tetris.oScreen.get_dx();i++)
                sum += line[cy][i];

            if (sum == Tetris.oScreen.get_dx()){
                // Tetris Screen
                Matrix temp = Tetris.oScreen.clip(0, 0, cy, Tetris.oScreen.get_dx());
                Tetris.oScreen.paste(temp, 1, 0);
                Tetris.oScreen.paste(zero, 0, Tetris.iScreenDw);

                // CTetris Screen
                temp = Tetris.oCScreen.clip(0, 0, cy, Tetris.oCScreen.get_dx());
                Tetris.oCScreen.paste(temp, 1, 0);
                Tetris.oCScreen.paste(zero, 0, Tetris.iScreenDw);

                nDeleted += 1;
            }
        }
    
        return;
}



Matrix createArrayScreen(){
        Tetris.arrayScreenDx = Tetris.iScreenDw * 2 + Tetris.iScreenDx;
        Tetris.arrayScreenDy = Tetris.iScreenDy + Tetris.iScreenDw;
        
        for(int i=0;i<Tetris.arrayScreenDy;i++)
            for(int j=0;j<Tetris.arrayScreenDx;j++)
                Tetris.arrayScreen[i][j] = 0;
        
        for (int i=0;i<Tetris.iSCreenDy;i++){
            for (int j=0;j<Tetris.iScreenDw;j++)
                Tetris.arrayScreen[y][x] = 1;
            for (int j=0;j<Tetris.iSCreenDx;j++)
                Tetris.arrayScreen[y][Tetris.iScreenDw + x] = 0;
            for (int j=0;j<Tetris.iScreenDw;j++)
                Tetris.arrayScreen[y][Tetris.iScreenDw + Tetris.iScreenDx + x] = 1;
        }

        for (int i=0;i<Tetris.iScreenDw;i++)
            for (int j=0;j<Tetris.arrayScreenDx;j++)
                Tetris.arrayScreen[Tetris.iScreenDy + y][x] = 1;

        return Tetris.arrayScreen;
}
