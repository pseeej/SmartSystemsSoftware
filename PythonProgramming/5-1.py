# get_sum

def get_sum(a, b):
    k = 0
    for i in range(a, b+1):
        k += i
    return k

sum = get_sum(2, 5)
print(sum)
