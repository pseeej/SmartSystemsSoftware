from game import *
from matrix import *

##################################################
### ColorDecorator for Tetris Class
##################################################

class ColorDecorator(Game):
	def initCBlocks(self, setOfBlockObjects):
		### initialize self.setOfCBlockObjects

		self.setOfBlockObjects = []

		for i in range(len(setOfBlockObjects)):
			self.setOfBlockObjects.append([])
			for j in range(len(setOfBlockObjects[i])):
				obj = Matrix(setOfBlockObjects[i][j])
				obj.mulc(i+1)
				self.setOfBlockObjects[i].append(obj)
		return
		
	def __init__(self, game):
		self.game = game
		self.initCBlocks(game.setOfBlockObjects)
		arrayScreen = game.createArrayScreen()
		self.iCScreen = Matrix(arrayScreen)
		self.oCScreen = Matrix(self.iCScreen)
		return
	
	def accept(self, key):
		if key >= '0' and key <= '6' :
			if self.game.justStarted == False:
				self.deleteFullLines()
			self.iCScreen = Matrix(self.oCScreen)

		self.state = self.game.accept(key)

		self.currBlk = self.setOfBlockObjects[self.game.idxBlockType][self.game.idxBlockDegree]
		self.tempBlk = self.iCScreen.clip(self.game.top, self.game.left, self.game.top + self.currBlk.get_dy(), self.game.left + self.currBlk.get_dx())
		self.tempBlk = self.tempBlk + self.currBlk

		self.oCScreen = Matrix(self.iCScreen)
		self.oCScreen.paste(self.tempBlk, self.game.top, self.game.left)

		self.deleteFullLines()

		return self.state
	
	def getScreen(self):
		return self.oCScreen

	def deleteFullLines(self):
		nDeleted = 0
		nScanned = self.currBlk.get_dy()

		if self.game.top + self.currBlk.get_dy() - 1 >= self.game.iScreenDy:
			nScanned -= (self.game.top + self.currBlk.get_dy() - self.game.iScreenDy)

		zero = Matrix([[ 0 for x in range(0, (self.game.iScreenDx - 2*self.game.iScreenDw))]])
		for y in range(nScanned-1, -1, -1):
			cy = self.game.top + y + nDeleted
			temp = self.oCScreen.binary()
			line = temp.clip(cy, 0, cy+1, self.oCScreen.get_dx())
			temp.mulc(self.game.idxBlockType+1)
			if line.sum() == self.oCScreen.get_dx():
				temp = self.oCScreen.clip(0, 0, cy, self.oCScreen.get_dx())
				self.oCScreen.paste(temp, 1, 0)
				self.oCScreen.paste(zero, 0, self.game.iScreenDw)
				nDeleted += 1

		return