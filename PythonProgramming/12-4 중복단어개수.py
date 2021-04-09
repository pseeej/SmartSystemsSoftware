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
        index = onlyWords.index(word)      #얘만 잘 해결하면 돼
        countWords[index] += 1

for i in range(len(onlyWords)):
    print((onlyWords[i], countWords[i]))
