from tkinter import *
window = Tk()
name = dict()

def save():
    global e1
    global e2
    global e3
    if e1.get() in name:
        print("중복되는 이름이 있습니다. 덮어씌웁니다.")
    name[e1.get()] = [e2.get(), e3.get()]
    e1.delete(0, END)
    e2.delete(0, END)
    e3.delete(0, END)

def search():
    global e1
    if e1.get() in name:
        print("찾았습니다:", name[e1.get()])
    else:
        print("찾는 이름이 없습니다.")

Label(window, text = "이름").grid(row = 0)
Label(window, text = "직업").grid(row = 1)
Label(window, text = "국적").grid(row = 2)

e1 = Entry(window)
e2 = Entry(window)
e3 = Entry(window)

e1.grid(row = 0, column = 1)
e2.grid(row = 1, column = 1)
e3.grid(row = 2, column = 1)


Button(window, text = "저장", command = save).grid(row = 3, column = 0)
Label(window, text = "저장할 데이터를 입력하세요").grid(row = 3, column = 1)

Button(window, text = "검색", command = search).grid(row = 4, column = 0)
Label(window, text = "검색할 이름을 입력하세요").grid(row = 4, column = 1)

window.mainloop()
