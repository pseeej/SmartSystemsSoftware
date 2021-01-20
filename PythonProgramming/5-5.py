#get_filtered

def get_filtered (data, filter):
    changed = ""
    for i in range(len(data)):
        if data[i] not in filter :
               changed += data[i]

    return changed

x = input("문장을 입력하세요 : ")
y = "$?#!_-.'"

print(get_filtered(x, y))
