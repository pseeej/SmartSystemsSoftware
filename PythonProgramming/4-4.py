# for문 이용
'''
n = int(input("어디까지 계산할까요~? : "))
res = 1

for i in range(1, n+1):
    res *= i

print(res)
'''

# while문 이용

n = int(input("어디까지 계산할까요~? : "))
res = 1
i=1

while (i<(n+1)):
    res *= i
    i+=1

print(res)
