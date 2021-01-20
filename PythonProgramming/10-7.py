import math

class Circle:
    def __init__(self, radius):
        self.__radius=radius

    def __add__(self, other):
        return self.__radius+other.__radius

    def __lt__(self, other):
        return self.__radius<other.__radius

    def __gt__(self, other):
        return self.__radius>other.__radius

    def __str__(self):
        return Circle(self)


c1 = Circle(4)
c2 = Circle(5)
c3 = c1+c2

print(type(c3))
print(c3)

if c1<c2:
    print("c1이 c2보다 작습니다.")
else:
    print("c1이 c2보다 큽니다.")

if c2>c3:
    print("c2가 c3보다 큽니다.")
else:
    print("c2가 c3보다 작습니다.")
