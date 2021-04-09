from tkinter import *

global us, uk, fr, jp
us=0
uk=0
fr=0
jp=0

def plus_us(event):
    us += 1
    b1 = Button(window, text='미국 : %d' %us)
    b1.pack()
def plus_uk():
    uk += 1
def plus_fr():
    fr += 1
def plus_jp():
    jp += 1

window = Tk()
label = Label(window, text="가장 여행하고 싶은 나라는?")
label.pack()
b1 = Button(window, text='미국 : %d' %us)
b2 = Button(window, text='영국 : %d' %uk)
b3 = Button(window, text='프랑스 : %d' %fr)
b4 = Button(window, text='일본 : %d' %jp)
b1.pack()
b2.pack()
b3.pack()
b4.pack()

b1['text'] = '미국 : %d' %us


window.mainloop()
