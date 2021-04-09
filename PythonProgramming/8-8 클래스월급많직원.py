class Employee:
    emp_cnt = 0
    max_salary = 0
    max_name = ''
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

    def get_employee_with_max_salary(self):
        if (int(Employee.get_salary())>Employee.max_salary) :
            Employee.max_salary = Employee.get_salary()
            Employee.max_name = Employee.get_name()
        return Employee.max_name

file = open('emp.txt', 'r', encoding='UTF-8')
Employees = []
for line in file:
    data = line.split()
    emp = Employee(data[0], data[1])
    Employees.append(emp)

print(get_employee_with_max_salary(Employee))
