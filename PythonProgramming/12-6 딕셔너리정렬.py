infile = open("mary.txt", "r")

words = []

for line in infile:
    for word in line.split():
        words.append(word.lower())

countWords = []
onlyWords = []
count = 1

for word in words:
    if word not in onlyWords:
        onlyWords.append(word)
        countWords.append(count)
    else :
        index = onlyWords.index(word)
        countWords[index] += 1

finalDict = {}

for i in range(len(onlyWords)):
    finalDict[onlyWords[i]]=countWords[i]

print(sorted(finalDict.items(), key=lambda t:t[1], reverse=True))   #람다가 문제

infile.close()

