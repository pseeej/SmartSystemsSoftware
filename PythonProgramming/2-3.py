n = int(input("number = "))

num1 = n//1000
num2 = n%1000//100
num3 = n%100//10
num4 = n%10

sum = num1+num2+num3+num4

print(sum)
