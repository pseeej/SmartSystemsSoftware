class ScoreManager:
    global scores
    scores = []
    def __init__(self):
        self.__menu = 0
    def enteringmenu(self, menu):
            if menu == 1:
                score = int(input("성적을 입력하세요. 종료하려면 -1을 입력하세요 : "))
                while (score!=-1):
                    scores.append(score)
                    score = int(input("성적을 입력하세요. 종료하려면 -1을 입력하세요 : "))
            if menu == 2:
                students = len(scores)
                score = 0
                sum = 0
                for score in scores:
                    sum += score
                average = sum / students
                print("평균 점수는 %d점입니다." %average)
            if menu==3:
                students = len(scores)
                print("학생 수는 %d명입니다." %students)


print("학생성적관리 프로그램이 시작되었습니다.")
while True:
    menu = int(input("메뉴를 입력하시오 : "))
    a = ScoreManager()
    a.enteringmenu(menu)
