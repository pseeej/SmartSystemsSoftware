# bin_to_dec

def bin_to_dec (binary):
    decimal = 0
    for i in range(len(binary)):
        decimal += int(binary[len(binary)-i-1]) * (2 ** i)
    return decimal

binary = input("2진수 : ")
print("10진수 : ", bin_to_dec(binary))
