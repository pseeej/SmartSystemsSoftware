# get_max

def get_max (a, b):
    if a>b :
        return a
    else :
        return b

def get_min (a, b):
    if a<b :
        return a
    else :
        return b

x = int(input("source : "))
y = int(input("dest : "))

dist = get_max(x, y)- get_min(x, y)

print("distance : %d" %dist)
