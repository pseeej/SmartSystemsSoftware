class Employee:
    emp_cnt = 0
    def __init__(self, name='NULL', salary = 0):
        self.__name = name
        self.__salary = salary
        Employee.emp_cnt += 1
    def get_name(self):
        return self.__name
    def get_salary(self):
        return self.__salary
    def get_tot_cnt(self):
        return Employee.emp_cnt

file = open('emp.txt', 'r', encoding='UTF-8')
Employees = []
for line in file:
    data = line.split()
    emp = Employee(data[0], data[1])
    Employees.append(emp)


#이것도 정답... 이건 걍 내 지식이 아닌 거나 다름없음ㅋ
max_salary = 0
max_name = ""
for emp in Employees:
    if int(emp.get_salary())>max_salary :
        max_salary = int(emp.get_salary())
        max_name = emp.get_name()
print(max_name)

