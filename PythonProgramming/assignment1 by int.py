ans = int(input("정답 숫자를 입력하세요 : "))     #정답 숫자 입력

for i in range(10):
    ball = 0                                         #ball 값 초기화
    strike = 0                                       #strike 값 초기화
    guess = int(input("숫자를 입력하세요 : "))     #추측 값 입력

    a_rand = ans                                     #초기 나머지값 주어줌

    for k in range(4):
        k = 3-k                                      #정답의 천의 자리 수부터 나누기 위해 k값 지정
        a_divide = a_rand//(10**k)                   #정답의 10**(3-k)의 자리수 빼내기
        a_rand %= (10**k)                            #정답의 본래 수에서 사용한 수 빼기

        for t in range(4):
            t = 3-t                                 #추측 값의 천의 자리 수부터 나누기 위해 k값 지정

            if (t!=3) :
                g_divide = g_rand//(10**t)           #추측 값의 10**(3-k)의 자리수 빼내기 (처음에 g_rand의 값이 없으므로 첫회만 아래에서 지정)
            else :
                g_rand = guess                       #초기 나머지값 주어줌
                g_divide = g_rand//(10**t)           #추측 값의 10**(3-k)의 자리수 빼내기

            g_rand -= (g_divide*(10**t))             #추측 값의 10**(3-k)를 이용한 뒤의 수 빼기

            if (a_divide == g_divide) :             #정답 값과 추측 값이 같을 때
                if(k==t) :                          #자리수가 같을 때
                    strike+=1
                else :                              #자리수가 같지 않을 때
                    ball+=1

    if (strike==0 & ball==0) :
        print(strike, "스트라이크", ball, "볼")   #출력
    else :
        print(strike, "스트라이크", ball, "볼")

    if strike==4:                                   #추측값==정답
        print("정답입니다.")
        break                                       #게임 끝내기
