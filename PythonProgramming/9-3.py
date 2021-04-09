from tkinter import *

names=[]
ages=[]
nations=[]

def search():
    print("이름 : %s\n나이 : %s\n국적 : %s" %(e1.get(), e2.get(), e3.get()))
def save():
    names.append(e1.get())
    ages.append(e2.get())
    nations.append(e3.get())

window = Tk()
Label(window, text="이름").grid(row=0)
Label(window, text="나이").grid(row=1)
Label(window, text="국적").grid(row=2)

e1 = Entry(window)
e2 = Entry(window)
e3 = Entry(window)

e1.grid(row=0, column=1)
e2.grid(row=1, column=1)
e3.grid(row=2, column=1)

Button(window, text='저장', command=save).grid(row=3)
Label(window, text="저장할 데이터를 입력하세요")
Button(window, text='검색', command=search).grid(row=4, column=0, sticky=W, pady=4)
Label(window, text='검색할 이름을 입력하세요')

mainloop()
