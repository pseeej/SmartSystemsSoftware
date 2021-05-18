from game import *
from matrix import *

##################################################
### ColorDecorator for Tetris Class
##################################################

class ColorDecorator(Game):
	def initCBlocks(self, setOfBlockObjects):
		### initialize self.setOfCBlockObjects
		return
		
	def __init__(self, game):
		self.game = game
		self.initCBlocks(game.setOfBlockObjects)
		arrayScreen = game.createArrayScreen()
		self.iCScreen = Matrix(arrayScreen)
		self.oCScreen = Matrix(self.iCScreen)
		return
	
	def accept(self, key):
		return state
	
	def getScreen(self):
		return self.oCScreen

	def deleteFullLines(self):
        nDeleted = 0
        nScanned = self.currBlk.get_dy()

        if self.top + self.currBlk.get_dy() - 1 >= self.iScreenDy:
            nScanned -= (self.top + self.currBlk.get_dy() - self.iScreenDy)

        zero = Matrix([[ 0 for x in range(0, (self.iScreenDx - 2*Tetris.iScreenDw))]])
        for y in range(nScanned - 1, -1, -1):
            cy = self.top + y + nDeleted
            line = self.oScreen.clip(cy, 0, cy+1, self.oScreen.get_dx())
            if line.sum() == self.oScreen.get_dx():
                temp = self.oScreen.clip(0, 0, cy, self.oScreen.get_dx())
				self.currBlk = self.currBlk.binary()
				self.currBlk.mulc(self.idxBlockType+1)
                self.oScreen.paste(temp, 1, 0)
                self.oScreen.paste(zero, 0, Tetris.iScreenDw)
                nDeleted += 1

		return

