phonekey = {'ABC':'2', 'DEF':'3', 'GHI':'4', 'JKL':'5','MNO':'6', 'PQRS':'7', 'TUV':'8', 'WXYZ':'9'}

alphabet = input("문자열을 입력하시오 : ")

for i in alphabet:
    for k in phonekey:
        if i in k:
            print(phonekey[k], end='')
