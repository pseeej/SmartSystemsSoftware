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





#이게 해답임ㅋ 떼닝 기억 반 답지 반,,, 흑흑
file = open('emp.txt', 'r', encoding='UTF-8')
Employees = []
for line in file:
    data = line.split()
    emp = Employee(data[0], data[1])
    Employees.append(emp)


