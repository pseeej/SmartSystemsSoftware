infile = open("mary.txt", "r")

freqs = {}

for line in infile:
    for char in line.strip().split():
        if char in freqs:
            freqs[char]+=1
        else :
            freqs[char] = 1
print(freqs)

print(sorted(freqs.items(), key=lambda t : t[1], reverse=True))

infile.close()
