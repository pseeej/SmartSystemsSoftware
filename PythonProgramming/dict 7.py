dictionary = {}

name = input("이름을 입력하세요 : ")
while (name!=""):
    pnumber = input("전화번호를 입력하세요. : ")
    dictionary[name] = pnumber
    name = input("이름을 입력하세요 : ")

fname = input("찾을 이름을 입력하세요 : ")
if fname not in dictionary.keys():
    print("찾는 이름이 없습니다.", end = " ")
    fname = input("이름을 입력하세요 : ")
else :
    print("전화번호는 ", dictionary[fname], "입니다.")
