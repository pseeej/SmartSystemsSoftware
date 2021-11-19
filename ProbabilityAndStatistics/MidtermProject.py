from random import randint

def morning(mafnum, citnum):
    kill = randint(0, citnum+mafnum)
    if kill < mafnum:
        mafnum -= 1
        print("마피아가 죽었습니다.")
    else:
        citnum -= 1
        print("시민이 죽었습니다.")
    
    return (mafnum, citnum)

# def evening(citnum):


mafia = int(input("마피아 수를 입력하시오. "))
citizen = int(input("시민의 수를 입력하시오. "))

while True:
    (mafia, citizen) = morning(mafia, citizen)
    
