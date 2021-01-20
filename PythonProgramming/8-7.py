class Employee:
    emp_cnt = 0
    def __init__(self, name=None, salary=0):
        self.name = name
        self.salary = salary
        Employee.emp_cnt += 1

    def get_name(self):
        return self.name

    def get_salary(self):
        return self.salary

    def get_tot_cnt(self):
        return Employee.emp_cnt

file = open("emp.txt", "rt", encoding='UTF8')

Employees = list()

for line in file:
    data = line.split()
    emp = Employee(data[0], data[1])
    Employees.append(emp)

high = Employees[0].get_salary()
for k in Employees:
    if(k.get_salary()>high):
        high = k.get_salary()
        high_name = k.get_name()

print(high_name)
