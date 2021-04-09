decimal = int(input("decimal : "))
num = decimal

i = 0
binary=""

while num > 2**i:
    if (decimal%2==0):
        binary = "0" + binary
    else :
        binary = "1" + binary
    decimal = decimal//2
    i += 1

reversed(binary)

print("binary : ", binary)
