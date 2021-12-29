from tetris import *

class CTetris(Tetris) :

    def accept(self, key):
        self.state = TetrisState.Running

        if key >= '0' and key <= '6':
            if self.justStarted == False:
                self.deleteFullLines()
            self.iScreen = Matrix(self.oScreen)
            self.idxBlockType = int(key)
            self.idxBlockDegree = 0
            self.idxBlockColor = self.idxBlockType + 1

            self.currBlk = Tetris.setOfBlockObjects[self.idxBlockType][self.idxBlockDegree]
            self.currBlk = self.currBlk.binary()
            self.currBlk.mulc(self.idxBlockColor)

            self.top = 0
            self.left = Tetris.iScreenDw + self.iScreenDx//2 - self.currBlk.get_dx()//2
            
            self.tempBlk = self.iScreen.clip(self.top, self.left, self.top+self.currBlk.get_dy(), self.left+self.currBlk.get_dx())
            self.tempBlk = self.tempBlk.binary()
            self.tempBlk = self.tempBlk + self.currBlk

            self.justStarted = False
            print()

            if self.tempBlk.anyGreaterThan(self.idxBlockColor):
                self.state = TetrisState.Finished
            self.oScreen = Matrix(self.iScreen)
            self.oScreen.paste(self.tempBlk, self.top, self.left)

            #self.tempBlk = self.tempBlk.binary()
            self.tempBlk = self.tempBlk + self.currBlk
            return self.state

        elif key == 'q':
            pass
        elif key == 'a': # move left
            self.left -= 1
        elif key == 'd': # move right
            self.left += 1
        elif key == 's': # move down
            self.top += 1
        elif key == 'w': # rotate the block clockwise
            self.idxBlockDegree = (self.idxBlockDegree + 1) % Tetris.nBlockDegrees
            self.currBlk = Tetris.setOfBlockObjects[self.idxBlockType][self.idxBlockDegree]
            self.currBlk = self.currBlk.binary()    # 이거 주석처리하면 w가 안 먹음
            self.currBlk.mulc(self.idxBlockColor)
        elif key == ' ': # drop the block
            while not self.tempBlk.anyGreaterThan(self.idxBlockColor):
                    self.top += 1
                    self.tempBlk = self.iScreen.clip(self.top, self.left, self.top+self.currBlk.get_dy(), self.left+self.currBlk.get_dx())
                    self.tempBlk = self.tempBlk.binary()    # 이거 주석처리하면 ' ' 안 먹음
                    self.tempBlk = self.tempBlk + self.currBlk
        else:
            print('Wrong key!!!')
            
        self.tempBlk = self.iScreen.clip(self.top, self.left, self.top+self.currBlk.get_dy(), self.left+self.currBlk.get_dx())
        self.tempBlk = self.tempBlk.binary() # 이거 주석처리하면 붕 뜸
        self.tempBlk = self.tempBlk + self.currBlk

        if self.tempBlk.anyGreaterThan(self.idxBlockColor):   ## 벽 충돌시 undo 수행
            if key == 'a': # undo: move right
                self.left += 1
            elif key == 'd': # undo: move left
                self.left -= 1
            elif key == 's': # undo: move up
                self.top -= 1
                self.state = TetrisState.NewBlock
            elif key == 'w': # undo: rotate the block counter-clockwise
                self.idxBlockDegree = (self.idxBlockDegree - 1) % Tetris.nBlockDegrees
                self.currBlk = Tetris.setOfBlockObjects[self.idxBlockType][self.idxBlockDegree]
                self.currBlk = self.currBlk.binary()
                self.currBlk.mulc(self.idxBlockColor)
            elif key == ' ': # undo: move up
                self.top -= 1
                self.state = TetrisState.NewBlock
            
            self.tempBlk = self.iScreen.clip(self.top, self.left, self.top+self.currBlk.get_dy(), self.left+self.currBlk.get_dx())
            # self.tempBlk = self.tempBlk.binary() # 얘는 확실히 아님. 이거 주석처리 안 하면 그냥 빨간색으로 바뀜
            self.tempBlk = self.tempBlk + self.currBlk

        self.oScreen = Matrix(self.iScreen)
        self.oScreen.paste(self.tempBlk, self.top, self.left)

        return self.state


    # iScreen, oScreen, currBlk can have int nums(0~7) for arguments

    # delete lines
    def deleteFullLines(self) :
        array = self.oScreen.get_array()

        cnt = 0
        
        for y in range(self.oScreen.get_dy()-Tetris.iScreenDw):

            for x in range(Tetris.iScreenDw, self.oScreen.get_dx()-Tetris.iScreenDw):
                if array[y][x] >= 1:
                    cnt += 1

            if cnt == (self.oScreen.get_dx()-Tetris.iScreenDw-Tetris.iScreenDw) :
                for i in range(Tetris.iScreenDw, self.oScreen.get_dx()-Tetris.iScreenDw):
                    array[y][i] = 0
                
                for i in range(y, 1, -1):
                    for j in range(Tetris.iScreenDw, self.oScreen.get_dx()-Tetris.iScreenDw):
                        array[i][j] = array[i-1][j]
            
            cnt = 0

            

        return array

		
        
