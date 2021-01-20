birth = input("생년월일을 입력하시오. : ")

if int(birth[4:6])<1 or int(birth[4:6])>12 or int(birth[6:])<1 or int(birth[6:])>31 :
    print("올바른 생년월일이 아닙니다.")
else :
    print("당신의 생일은 %s년 %s월 %s일이다!" %(birth[:4], birth[4:6], birth[6:]))
