infile = open("phones.txt", "r")

for line in infile.readlines():
    print(line.strip())

infile.close()
