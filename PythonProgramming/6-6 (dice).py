from random import *

res = [0,0,0,0,0,0]

for i in range(601):
    dice = randint(1, 6)
    res[dice-1] += 1

for k in range(1, 7):
    print("주사위가 ", k, "인 경우는 ", res[k-1])
