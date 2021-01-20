moonja = input("문자열을 입력하세요 : ")
finding = input("어떤 문자를 찾을까요 : ")

count = 0

for i in range(len(moonja)-1):
    if moonja[i] == finding :
        count += 1

print(finding,"의 개수는 ", count, "입니다.")
