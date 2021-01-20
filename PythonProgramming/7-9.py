phonebook = {}

name = input("(입력모드) 이름을 입력하세요 : ")

while (name!=''):
    number = input("(입력모드) 전화번호를 입력하세요 : ")
    phonebook[name] = number
    name = input("(입력모드) 이름을 입력하세요 : ")

find_name = input("(검색모드) 이름을 입력하세요 : ")

while(find_name not in phonebook):
    find_name = input(("(검색모드) 찾는 이름이 없습니다. 이름을 입력하세요 : "))

print("(검색모드) 전화번호는 %s 입니다." %phonebook[find_name])
