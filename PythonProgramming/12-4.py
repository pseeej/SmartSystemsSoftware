infile = open("mary.txt", "r")

numlist = []
all_list = []
reallist = []

for line in infile:
    line = line.rstrip()
    word_list = line.split()
    for word in word_list:
        all_list.append(word)     #모든 단어 다 real_word_list에 리스트로 넣어버렸음

for i in range(len(all_list)):
    numlist.append(0)        #real_word_list 요소 개수만큼 count_list의 요소 0으로 넣어둠

'''for k in range()'''

infile.close
