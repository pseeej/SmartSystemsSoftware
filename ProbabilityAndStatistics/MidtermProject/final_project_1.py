from random import choices

# 아침
def morning(citnum, mafnum):
    # 랜덤하게 죽일 사람의 idx 뽑아내기
    kill = choices(range(0, citnum+mafnum), weights=[1]*(citnum+mafnum))    

    # idx가 0 ~ 시민 수-1 = 시민. 시민 수 ~ 시민+마피아 수-1 = 마피아
    if kill[0] >= citnum:
        mafnum -= 1
        print("마피아가 죽었습니다.")
    else:
        citnum -= 1
        print("시민이 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafnum}명, 시민{citnum}명 >>")
    return (citnum, mafnum)

# 저녁
def evening(citnum, mafnum):
    # 밤에는 마피아가 사람을 죽이므로 당연히 시민이 죽을 것이라 예상.

    print("시민이 죽었습니다.")
    print(f"<< 현재 인원 마피아 {mafnum}명, 시민{citnum-1}명 >>")
    return (citnum-1, mafnum)

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
citizen = int(input("시민의 수를 입력하시오. "))

day = 0

while True:
    if checkIfEnd(citizen, mafia):
        break

    print("============================")
    
    day += 1

    print(f"{day}번째 낮입니다.")
    (citizen, mafia) = morning(citizen, mafia)
    if checkIfEnd(citizen, mafia):
        break

    print("-----------------------------")

    print(f"{day}번째 밤입니다.")
    (citizen, mafia) = evening(citizen, mafia)
    if checkIfEnd(citizen, mafia):
        break


    