ans = input("정답 숫자를 입력하세요 : ")

for i in range(10):
    ball =0     #ball 값 초기화
    strike =0   #strike 값 초기화
    guess = input("숫자를 입력하세요 : ")
    for k in range(4):
        for t in range(4):
            if guess[k]==ans[t] :   #값이 똑같을 때
                if k==t:            #값 일치, 순서 비일치
                    strike+=1
                else :              #값 일치, 순서 비일치
                    ball+=1
                break
            else :                  #값 비일치
                pass
    if strike!=0:
        print(strike, "스트라이크")      #스트라이크 값 출력
        if ball!=0:
            print(4-strike, "볼")        #스트라이크 존재 시 전체 개수에서 스트라이크 개수 제외 (스트라이크는 볼에도 해당되기 때문)
    elif strike==0:                      #스트라이크 존재 X
        if ball!=0:
           print(ball, "볼")             #볼 개수 출력
        if ball==0:
            print("아웃입니다.")
    if strike==4:
        print("정답입니다.")
        break
