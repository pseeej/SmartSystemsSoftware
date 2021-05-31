##############################################################
### Threading code (Observer pattern)
##############################################################
from abc import *

import threading
import time
import curses

isGameDone = False

class Publisher(metaclass = ABCMeta):
	@abstractmethod
	def addObserver(self, observer):
		pass

	@abstractmethod
	def notifyObservers(self, key):
		pass

class Observer(metaclass = ABCMeta):
	@abstractmethod
	def update(self, key):
		pass

class KeyController(threading.Thread, Publisher):
	def __init__(self, *args, **kwargs):
		super(KeyController, self).__init__(*args[1:], **kwargs)
		self.name = args[0]
		self.observers = list()
		return

	def addObserver(self, observer):
		self.observers.append(observer)
		return
	
	def notifyObservers(self, key):
		for observer in self.observers:
			observer.update(key)
		return

	def run(self):
		global isGameDone

		while not isGameDone:
			try:
				key = getChar()
			except:
				isGameDone = True
				printMsg('getChar() wakes up!!')
				break

			self.notifyObservers(key)

		printMsg('%s terminated... Press any key to continue' % self.name)
		time.sleep(1)
		self.notifyObservers('')
		return

class TimeController(threading.Thread, Publisher):
	def __init__(self, *args, **kwargs):
		super(TimeController, self).__init__(*args[1:], **kwargs)
		self.name = args[0]
		self.observers = list()
		return

	def addObserver(self, observer):
		self.observers.append(observer)
		return
	
	def notifyObservers(self, key):
		for observer in self.observers:
			observer.update(key)
		return

	def run(self):
		while not isGameDone:
			time.sleep(1)
			self.notifyObservers('y')

		printMsg('%s terminated... Press any key to continue' % self.name)
		time.sleep(1)
		self.notifyObservers('')
		return


class Model(threading.Thread, Observer, Publisher):
	def __init__(self, *args, **kwargs):
		super(Model, self).__init__(*args[1:], **kwargs)
		self.name = args[0]
		self.queue = list()
		self.cv = threading.Condition()
		self.observers = list()	# 추가
		return

	def update(self, key):
		self.cv.acquire()
		self.queue.append(key)
		self.cv.notify()
		self.cv.release()
		return
	
	def read(self):
		self.cv.acquire()
		while len(self.queue) < 1:
			self.cv.wait()
		key = self.queue.pop(0)
		self.cv.release()
		return key

	def addObserver(self, observer):	# 추가
		self.observers.append(observer)
		return
	
	def notifyObservers(self, key):	# 추가
		for observer in self.observers:
			observer.update(key)
		return
	
	def addKeypad(self, keypad):
		self.keypad = keypad
		return

	def run(self):
		global isGameDone

		# setOfBlockArrays = initSetOfBlockArrays()

		# Tetris.init(setOfBlockArrays)
		# board = Tetris(20, 15)

		# idxBlockType = randint(0, nBlocks-1)
		# key = str(idxBlockType)
		# state = board.accept(key)
		# printWindow(self.window, board.getScreen())

		while not isGameDone:
			key = self.read()
			if key == '':
				break
			if key not in self.keypad:
				continue

			key = self.keypad[key]
			if key == 'q':
				state = TetrisState.Finished
			else:
				state = processKey(self.window, board, key)

			if state == TetrisState.Finished:
				isGameDone = True
				printMsg('%s IS DEAD!!!' % self.name)
				time.sleep(2)
				break

		printMsg('%s terminated... Press any key to continue' % self.name)
		time.sleep(1)
		self.notifyObservers('')	# 이거 추가해줬음
		return

class View(threading.Thread, Observer):
	def __init__(self, *args, **kwargs):
		super(Model, self).__init__(*args[1:], **kwargs)
		self.name = args[0]
		self.queue = list()
		self.cv = threading.Condition()
		return
    
	def addWindow(self, window):	# Model에서 뽀려옴
		self.window = window
		return

	def read(self):
		self.cv.acquire()
		while len(self.queue) < 1:
			self.cv.wait()
		key = self.queue.pop(0)
		self.cv.release()
		return key

	def run(self):
		global isGameDone

		setOfBlockArrays = initSetOfBlockArrays()

		Tetris.init(setOfBlockArrays)
		board = Tetris(20, 15)

		idxBlockType = randint(0, nBlocks-1)
		key = str(idxBlockType)
		state = board.accept(key)
		printWindow(self.window, board.getScreen())

		while not isGameDone:
			key = self.read()
			if key == '':
				break
			if key not in self.keypad:
				continue

			key = self.keypad[key]
			if key == 'q':
				state = TetrisState.Finished
			else:
				state = processKey(self.window, board, key)

			if state == TetrisState.Finished:
				isGameDone = True
				printMsg('%s IS DEAD!!!' % self.name)
				time.sleep(2)
				break

		printMsg('%s terminated... Press any key to continue' % self.name)
		time.sleep(1)
		return

##############################################################
### Main code
##############################################################

def main(args):
	global lock
	global win0

	lock = threading.Lock()

	screen = curses.initscr()
	screen.clear()

	curses.echo()
	curses.start_color()
	curses.use_default_colors()

	win1 = curses.newwin(20, 30, 0, 0)
	win2 = curses.newwin(20, 30, 0, 40)
	win0 = curses.newwin(3, 70, 21, 0)

	th_view1 = View('view1')
	th_view1.addWindow(win1)

	th_view2 = View('view2')
	th_view2.addWindow(win2)

	keypad1 = { 'q': 'q', 'w': 'w', 'a': 'a', 's': 'y', 'd': 'd', ' ': ' ', 'y': 'y' }
	th_model1 = Model('model1')
	th_model1.addKeypad(keypad1)
	th_model1.addObserver(th_view1)

	keypad2 = { 'u': 'q', 'i': 'w', 'j': 'a', 'k': 'y', 'l': 'd', '\r': ' ', 'y': 'y' }
	th_model2 = Model('model2')
	th_model2.addKeypad(keypad2)
	th_model2.addObserver(th_view2)

	th_cont1 = KeyController('kcont')
	th_cont1.addObserver(th_model1)
	th_cont1.addObserver(th_model2)

	th_cont2 = TimeController('tcont')
	th_cont2.addObserver(th_model1)
	th_cont2.addObserver(th_model2)

	threads = list()
	threads.append(th_view1)
	threads.append(th_view2)
	threads.append(th_model1)
	threads.append(th_model2)
	threads.append(th_cont1)
	threads.append(th_cont2)

	exited = list()

	fd = sys.stdin.fileno()
	old_settings = termios.tcgetattr(fd)
	tty.setcbreak(sys.stdin.fileno())

	for th in threads:
		th.start()
	
	for th in threads:
		th.join()
		exited.append(th.name)
	
	string = ''
	for name in exited:
		string += ':%s' % name
	string += ' terminated!!!'

	printMsg(string)
	time.sleep(2)
	printMsg('Program terminated...')
	time.sleep(1)

curses.wrapper(main)