before = input("문자열 입력하세요 : ")
after = ""

for i in range(1, len(before)+1):
    after += before[-i]

print(before)
print(after)

if after==before:
    print("회문입니다.")
else :
    print("회문이 아닙니다.")
