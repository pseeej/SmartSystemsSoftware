from random import choices

def morning(mafnum, citnum):
    kill = choices(range(0, citnum+mafnum), weights=[1]*(citnum+mafnum))
    if kill[0] < mafnum:
        mafnum -= 1
        print("마피아가 죽었습니다.")
    else:
        citnum -= 1
        print("시민이 죽었습니다.")

    print(f"<< 현재 인원 마피아 {mafia}명, 시민{citnum}명 >>")
    return (mafnum, citnum)

def evening(mafia, citnum):
    print("시민이 죽었습니다.")
    print(f"<< 현재 인원 마피아 {mafia}명, 시민{citnum-1}명 >>")
    return (mafia, citnum-1)

def checkIfEnd(mafnum, citnum):
    if mafnum >= citnum:
        print()
        print(f"마피아 {mafnum}명과 시민 {citnum}명으로 마피아가 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    elif mafnum == 0:
        print()
        print(f"마피아 {mafnum}명과 시민 {citnum}명으로 시민이 이겼습니다.")
        print("게임을 종료합니다.")
        return 1
    else:
        return 0
    

mafia = int(input("마피아 수를 입력하시오. "))
citizen = int(input("시민의 수를 입력하시오. "))

day = 0

while True:
    if checkIfEnd(mafia, citizen):
        break

    print("============================")
    
    day += 1

    print(f"{day}번째 낮입니다.")
    (mafia, citizen) = morning(mafia, citizen)
    if checkIfEnd(mafia, citizen):
        break

    print("-----------------------------")

    print(f"{day}번째 밤입니다.")
    (mafia, citizen) = evening(mafia, citizen)
    if checkIfEnd(mafia, citizen):
        break

    
