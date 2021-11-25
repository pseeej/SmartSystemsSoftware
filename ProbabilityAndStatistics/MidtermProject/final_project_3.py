from random import choices

# 의사
def medic(citnum, docnum, mafnum):
    # 모두 동일한 비율로 살림
    heal = choices(range(0, citnum+docnum+mafnum), weights=[1]*(citnum+docnum+mafnum))

    return heal

# 아침
def morning(citnum, docnum, mafnum):
    tot_citizen = citnum + docnum

    # 랜덤하게 죽일 사람의 idx 뽑아내기
    kill = choices(range(0, tot_citizen+mafnum), weights=[1]*(tot_citizen+mafnum))    

    if 0 <= kill[0] < citnum:   # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    elif citnum <= kill[0] < tot_citizen:    # 의사 죽음
        docnum -= 1
        print("경찰이 죽었습니다.")
    else:   # 마피아 죽음
        mafnum -= 1
        print("마피아가 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafnum}명, 시민{citnum+docnum}명 >>")
    return (citnum, docnum, mafnum)

# 저녁
def evening(citnum, docnum, mafnum):
    tot_citizen = citnum + docnum

    kill = choices(range(0, tot_citizen), weights=[1]*(tot_citizen))
    heal = medic(citnum, docnum, mafnum)

    if docnum > 0 and heal == kill[0]:
        print("아무도 죽지 않았습니다.")
        print(f"<< 현재 인원 마피아 {mafnum}명, 시민{citnum+docnum}명 >>")
        return (citnum, docnum, mafnum)

    if kill[0] < citnum:    # 일반 시민 죽음
        citnum -= 1
        print("시민이 죽었습니다.")
    else:   # 의사 죽음
        docnum -= 1
        print("의사가 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafnum}명, 시민{citnum+docnum}명 >>")
    return (citnum, docnum, mafnum)

# 승패 확인 위한 함수
def checkIfEnd(citnum, mafnum):
    # 마피아 수가 시민의 수보다 크거나 같으면 마피아의 승
    if mafnum >= citnum:
        print()
        print(f"마피아 {mafnum}명과 시민 {citnum}명으로 마피아가 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    # 마피아가 모두 제거되었을 경우 시민의 승
    elif mafnum == 0:
        print()
        print(f"마피아 {mafnum}명과 시민 {citnum}명으로 시민이 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    # 이외의 경우, 게임 계속 진행.
    else:
        return 0
    

mafia = int(input("마피아 수를 입력하시오. "))
doctor = int(input("의사의 수를 입력하시오. "))
citizen = int(input("시민의 수를 입력하시오. "))

day = 0

while True:
    if checkIfEnd(citizen, mafia):
        break

    print("============================")
    
    day += 1

    print(f"{day}번째 낮입니다.")
    (citizen, doctor, mafia) = morning(citizen, doctor, mafia)
    if checkIfEnd(citizen+doctor, mafia):
        break

    print("-----------------------------")

    print(f"{day}번째 밤입니다.")
    (citizen, doctor, mafia) = evening(citizen, doctor, mafia)
    if checkIfEnd(citizen+doctor, mafia):
        break


    