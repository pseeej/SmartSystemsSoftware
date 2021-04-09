scores = []
sum = 0

for i in range(5):
    score = int(input("점수를 입력하세요 : "))
    scores.append(score)
    sum += score

avg = sum/5

print("평균 = ", avg)

good = 0

for k in range(5):
    if (avg <= scores[k]):
        good += 1

print("평균 이상의 학생 수 = ", good)
