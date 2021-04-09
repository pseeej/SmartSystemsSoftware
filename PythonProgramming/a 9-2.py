from tkinter import *
window = Tk()
name = ["미국:","영국:","프랑스:","일본:"]
count = [0, 0, 0, 0]
button_list = []

def count_(i):
    button = button_list[i]
    count[i] += 1
    button["text"] = name[i] + str(count[i])

Label(window, text = "가장 여행하고 싶은 나라는?").pack()

for i in range(4):
    button = Button(window, text = name[i] + str(count[i]), command = lambda k = i : count_(k))
    button.pack()
    button_list.append(button)

window.mainloop()
