import random

board = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]

def pri_board() :  #게임판 출력 함수
    for i in range(5):
        for k in range(5):
            print(board[i][k], end="\t")
        print()

pri_board()

while 1 :
    sth = 0
    ant = 0
    while (sth == 0):       #빈 자리가 아닐 때 while문 계속 순환
        player = int(input("번호를 선택하세요 : "))     #player 위치 선정
        for i in range(5):
            for j in range(5):
                if board[i][j] == player and board[i][j]!=("O" or "X") :    #빈 자리인지 확인
                    sth += 1
                    board[i][j] = 'X'
        if (sth == 0):          #빈 자리가 아닐 때
            print("위치가 올바르지 않습니다.")

    while (ant == 0):       #빈 자리가 아닐 때 while문 계속 순환
        computer = random.randint(1, 25)        #randint로 computer 위치 선정
        for k in range(5):
            for l in range(5):
                if (board[l][k] == computer and board[i][j]!=("O" or "X")):     #빈 자리인지 확인
                    board[l][k] = "O"
                    ant += 1
    pri_board()     #판 출력

    playerC1 = 0    #오른쪽 하단으로 향하는 대각선
    playerC2 = 0    #왼쪽 하단으로 향하는 대각선
    right = 0       #맞는 개수 확인
    for m in range(5):
        playerR = 0     #행
        playerC = 0     #열
        for n in range(5):
            if board[m][n] == "X" :
                playerC += 1
            if board[n][m] == "X":
                playerR += 1
        if board[m][m] == "X":
            playerC1 +=1
        if board[m][4-m] == "X":
            playerC2 += 1
        if playerC == 5 or playerC1 == 5 or playerC2 == 5 or playerR == 5:  #한 종목 당 다섯 개 만족 시
            right += 1
            break       #for문 벗어남
    if right == 1:      #벗어날 수 있는 경우 성립
        print("빙고! 이겼습니다")
        break       #while문 벗어남
