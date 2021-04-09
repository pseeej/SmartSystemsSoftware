saving = 1000

year = 0
rate = 0.07

while saving <= 2000 :
    saving = saving*(1+rate)
    year += 1

print(year)
