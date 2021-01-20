file = open('data.txt', 'r')

sum = 0
i = 0

for line in file :
    num_list = line.split()
    for num in num_list:
        sum+=float(num)
    i += 1
    print(num)

avg = sum/i

print("합계는 %f이고 평균은 %f이다." %(sum, avg))

wfile = open('output.txt', 'w')
wfile.write("sum : %f\n" %sum)
wfile.write("avg : %f" %avg)
