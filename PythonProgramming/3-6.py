from random import *

ans1 = randint(1, 100)
ans2 = randint(1, 100)
ans = (ans1, ans2)

print("복권번호는 : ", ans)

guess1 = int(input("복권 첫 번째 번호를 입력하시오 : "))
guess2 = int(input("복권 두 번째 번호를 입력하시오 : "))
guess = (guess1, guess2)

if guess1 == ans or guess1 == reversed(ans) :
    print("1등입니다. 100만원을 수령하세요.")
elif (guess in ans):
    print("2등입니다. 50만원을 수령하세요.")
else :
    print("상금 없습니다.")
