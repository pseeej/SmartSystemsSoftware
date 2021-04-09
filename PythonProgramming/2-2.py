from math import *

x1 = int(input("x1의 값을 입력하시오 : "))
y1 = int(input("y1의 값을 입력하시오 : "))
x2 = int(input("x2의 값을 입력하시오 : "))
y2 = int(input("y2의 값을 입력하시오 : "))

dist = sqrt((x1-x2)**2+(y1-y2)**2)
print(dist)
