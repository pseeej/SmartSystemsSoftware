from random import choices

# 바보 경찰
def dumbpol(citnum, polnum, mafnum):
    # 경찰 본인을 뺀 나머지에서 하나 고르도록 함
    choice = choices(range(0, citnum+mafnum), weights=[1]*(citnum+mafnum))
    if choice[0] < citnum:    # 마피아 지목 실패
        print(f">> 지목한 {choice[0]}은 마피아가 아닙니다.")
        return -1
    else:   # 마피아 지목 성공
        realidx = polnum + choice[0]  # 사이에 경찰은 빼고 확인할 것을 가정했을 때의 idx 재정의
        print(f">> 지목한 {realidx}은 마피아입니다.")
        return realidx

# 똑똑이 경찰
def smartpol(chcarr, citnum, polnum, mafnum):
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
    else:
        chcarr[realidx] = 1

    return (chcarr, citnum, polnum, mafnum)


# 아침
def morning(citnum, polnum, mafnum):
    tot_citizen = citnum + polnum   # 총 시민 수

    # 경찰이 남아있을 때만 경찰 조사 진행
    if polnum > 0:
        pol_res = dumbpol(citnum, polnum, mafnum)
    else:
        pol_res = -1

    # 경찰이 마피아 지목에 성공했을 경우 선택된 마피아 낮에 죽을 확률 남은 시민의 수만큼 증가
    if pol_res >= 0:
        ch_weight = [1]*(tot_citizen+mafnum)    # 초기에는 모두 동일한 가중치 부여
        ch_weight[pol_res] = tot_citizen    # 마피아로 밝혀진 위치의 가중치 높임

        kill = choices(range(0, tot_citizen+mafnum), weights=ch_weight)
        print(f"마피아 밝혀졌을 때 죽는 애는 {kill[0]}")
    # 경찰이 마피아 지목에 실패했거나, 경찰이 존재하지 않을 경우 동일한 확률 부여
    else:
        kill = choices(range(0, tot_citizen+mafnum), weights=[1]*(tot_citizen+mafnum))
        print(f"마피아 안 밝혀졌을 때 죽는 애는 {kill[0]}")


    if 0 <= kill[0] < citnum:   # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    elif citnum <= kill[0] < citnum+polnum:    # 경찰 죽음
        polnum -= 1
        print("경찰이 죽었습니다.")
    else:   # 마피아 죽음
        mafnum -= 1
        print("마피아가 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafnum}명, 경찰 {polnum}명, 총 시민 {citnum+polnum}명 >>")
    return (citnum, polnum, mafnum)

# 저녁
def evening(citnum, polnum, mafnum):
    tot_citizen = citnum + polnum

    kill = choices(range(0, tot_citizen), weights=[1]*(tot_citizen))
    if kill[0] < citnum:    # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    else:   # 경찰 죽음
        polnum -= 1
        print("경찰이 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafnum}명, 경찰 {polnum}명, 총 시민 {citnum+polnum}명 >>")
    return (citnum, polnum, mafnum)

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

while True:
    if checkIfEnd(citizen, police, mafia):
        break

    print("============================")
    
    day += 1

    print(f"{day}번째 낮입니다.")
    (citizen, police, mafia) = morning(citizen, police, mafia)
    if checkIfEnd(citizen, police, mafia):
        break

    print("-----------------------------")

    print(f"{day}번째 밤입니다.")
    (citizen, police, mafia) = evening(citizen, police, mafia)
    if checkIfEnd(citizen, police, mafia):
        break

    