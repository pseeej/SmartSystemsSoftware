import pickle

infile = open("mary.txt", "r")

freqs = {}

for line in infile:
    for char in line.strip().split():
        if char in freqs:
            freqs[char]+=1
        else :
            freqs[char] = 1
pickle.dump(freqs, open("save.p", "wb"))
freqs = pickle.load(open("save.p", "rb"))

print(freqs)
infile.close()
