from random import choices

# 똑똑이 경찰
def smartpol(chcarr, citnum, polnum):
    # 확인하지 않은 것들 중에서만 선택하도록
    choice = choices(range(0, chcarr.count(0)), weights=[1]*(chcarr.count(0)))

    unchkidx = 0    # chcarr에서 값이 0인 것들의 index
    realidx = 0
    for i in range(len(chcarr)):
        # 0 값이 choice번 나왔을 경우
        if chcarr[i] == 0 and unchkidx == choice[0]:
            realidx = i
            break
        elif chcarr[i] == 0:
            unchkidx += 1

    if realidx < citnum+polnum:    # 시민으로 확인
        chcarr[realidx] = -1
    else:   # 마피아로 확인
        chcarr[realidx] = 1

    return chcarr


# 아침
def morning(chcarr, citnum, polnum, mafnum):
    tot_citizen = citnum + polnum   # 총 시민 수

    # 경찰이 남아있을 때만 경찰 조사 진행
    if polnum > 0:
        chcarr = smartpol(chcarr, citnum, polnum)
    # 경찰이 남아있지 않은 경우에는 이전에 사용하던 chcarr 이어서 사용

    print(">> 경찰 조사 결과 : ", chcarr)

    # 경찰이 조사한 결과를 바탕으로 가중치 부여
    ch_weight = [1]*(tot_citizen+mafnum)    # 초기에는 모두 동일한 가중치 부여
    for i in range(len(chcarr)):
        if chcarr[i] == 1:
            ch_weight[i] = tot_citizen  # 마피아로 밝혀진 위치의 가중치 높임

    kill = choices(range(0, tot_citizen+mafnum), weights=ch_weight)
    print(f"{kill[0]}번째가 선택됨으로써 ", end="")

    if 0 <= kill[0] < citnum:   # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    elif citnum <= kill[0] < citnum+polnum:    # 경찰 죽음
        polnum -= 1
        print("경찰이 죽었습니다.")
    else:   # 마피아 죽음
        mafnum -= 1
        print("마피아가 죽었습니다.")

    chcarr.pop(kill[0]) # 죽은 애 위치 빼기
    print(f"<< 현재 인원 마피아 {mafnum}명, 경찰 {polnum}명, 총 시민 {citnum+polnum}명 >>")
    return (chcarr, citnum, polnum, mafnum)

# 저녁
def evening(chcarr, citnum, polnum, mafnum):
    tot_citizen = citnum + polnum

    kill = choices(range(0, tot_citizen), weights=[1]*(tot_citizen))
    if kill[0] < citnum:    # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    else:   # 경찰 죽음
        polnum -= 1
        print("경찰이 죽었습니다.")

    chcarr.pop(kill[0]) # 죽은 애 위치 빼기
    print(f"<< 현재 인원 마피아 {mafnum}명, 경찰 {polnum}명, 총 시민 {citnum+polnum}명 >>")
    return (chcarr, citnum, polnum, mafnum)

# 승패 확인 위한 함수
def checkIfEnd(citnum, polnum, mafnum):
    if mafnum >= citnum+polnum:
        print(f"\n마피아 {mafnum}명과 시민 {citnum+polnum}명으로 마피아가 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    elif mafnum == 0:
        print(f"\n마피아 {mafnum}명과 시민 {citnum+polnum}명으로 시민이 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    else:
        return 0
    

mafia = int(input("마피아 수를 입력하시오. "))
police = int(input("경찰의 수를 입력하시오. "))
citizen = int(input("시민의 수를 입력하시오. "))

day = 0
chcarr = [0] * (mafia+police+citizen)

# 초기에 경찰 본인은 마피아가 아님을 표시
for i in range(citizen, citizen+police):
    chcarr[i] = -1

while True:
    if checkIfEnd(citizen, police, mafia):
        break

    print("============================")
    
    day += 1

    print(f"{day}번째 낮입니다.")
    (chcarr, citizen, police, mafia) = morning(chcarr, citizen, police, mafia)
    if checkIfEnd(citizen, police, mafia):
        break

    print("-----------------------------")

    print(f"{day}번째 밤입니다.")
    (chcarr, citizen, police, mafia) = evening(chcarr, citizen, police, mafia)
    if checkIfEnd(citizen, police, mafia):
        break

    