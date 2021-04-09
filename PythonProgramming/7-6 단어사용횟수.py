def process(w):
    output = ""
    for ch in w:
        if(ch.isalpha()):
            output+=ch
    return output.lower()
words = set()

fname = input("입력 파일 이름 : ")
file = open(fname, "r")

for line in file:
    lineWords = line.split()
    for word in lineWords:
        words.add(process(word))

print("사용된 단어의 개수 = ", len(words))
print(words)

fname = input("파일 이름 : ")
file = open(fname, "r")

table = dict()
for line in file:
    words = line.split()
    for word in words:
        if word not in table:
            table[word]=1
        else:
            table[word]+=1
print(table)
