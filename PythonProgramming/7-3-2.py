before = input("입력하세요 : ")

after = "".join(reversed(before))

if (before==after):
    print("회문입니다.")
else :
    print("회문이 아닙니다.")
