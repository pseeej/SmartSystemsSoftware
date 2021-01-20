written = "Welcome to Python"

print('함수 이용했을 때 : ', written.count('o'))

cnt = 0
for alpha in written:
    if (alpha=='o'):
        cnt += 1
print('함수 이용 안 했을 때 : ', cnt)
