dict = {}

id = input("ID를 입력하세요 (종료하려면 -1 입력) : ")

while (id!='-1') :
    password = input("비밀번호를 입력하세요 : ")
    dict[id] = password
    id = input("ID를 입력하세요 (종료하려면 -1 입력) : ")

print(dict)

find_id = input("찾을 ID를 입력하세요 : ")
print("해당 ID의 비밀번호는 ", dict[id], "입니다.")
