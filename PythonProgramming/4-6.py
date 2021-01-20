x = int(input("x의 값을 입력하시오 : "))
y = int(input("y의 값을 입력하시오 : "))

i=1

gongyak = ''

while i <= x and i <= y :
    if (x%i == 0 and y%i == 0):
        gongyak = i
    i+= 1

print(x,"와 ", y,"의 최대공약수는 ", gongyak,"이다.")
