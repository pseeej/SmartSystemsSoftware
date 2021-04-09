from random import *

nums = []

for i in range(10):
    nums.append(-randint(0, 100))

print(nums)

print(sorted(nums))

nums.sort(reverse=True)

print(nums)
