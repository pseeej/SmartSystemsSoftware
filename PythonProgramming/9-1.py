import time
from tkinter import *

def Buttons():
    b1 = Button(window, text = "<- (left)", command=move_left())
    b1.pack(side=LEFT, padx=20)
    b2 = Button(window, text = "-> (right)", command=move_right())
    b2.pack(side = LEFT, padx=20)
    b3 = Button(window, text = "^ (up)", command=move_up())
    b3.pack(side = LEFT, padx = 20)
    b4 = Button(window, text = "V (down)", command=move_down())
    b4.pack(side = LEFT, padx=20)

global a, b, c, d
a = 100
b=100
c=200
d=200

def move_left(event):
    canvas.move(id, a-5, b, c-5, d)
    canvas.bind_all('<KeyPress-Left>', move_left)
def move_right(event):
    canvas.move(id, a+5, b, c+5, d)
    canvas.bind_all('<KeyPress-Right>', move_right)
def move_up(event):
    canvas.move(id, a, b+5, c, d+5)
    canvas.bind_all('<KeyPress-Up>', move_up)
def move_down(event):
    canvas.move(id, a, b-5, c, d-5)
    canvas.bind_all('<KeyPress-Down>', move_down)



window = Tk()
canvas = Canvas(window, width=500, height=300)
canvas.pack()
id = canvas.create_rectangle(a, b, c, d, fill = "red")

Buttons()

for i in range(100):
    window.update()
    time.sleep(0.05)
