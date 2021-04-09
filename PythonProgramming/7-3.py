put = input("문자열을 입력하시오 : ")

'''
if ''.join(reversed(put)) == put :
    print("회문입니다.")
else :
    print("회문이 아닙니다.")
'''

if put[::-1] == put :
    print("회문입니다.")
else :
    print("회문이 아닙니다.")
