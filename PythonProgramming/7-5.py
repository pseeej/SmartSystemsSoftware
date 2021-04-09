age = input("나이를 입력하시오 : ")

while (age.isdigit()!=True):
    print("정수가 아닙니다. 다시 입력하시오.")
    age = input("나이를 입력하시오 : ")

print(age,"살이구나~")
