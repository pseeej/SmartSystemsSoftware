import os.path

outfile = open("phones.txt", "w")

if os.path.isfile("phones.txt"):       #os.path.isfile~
    print("동일한 이름의 파일이 이미 존재합니다.")
else:
    outfile.write("홍길동 010-1234-5678")
    outfile.write("김철수 010-1234-5679")
    outfile.write("김영희 010-1234-5680")
    outfile.close()
