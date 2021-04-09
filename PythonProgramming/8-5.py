class Employee:
    emp_cnt = 0
    employees = {}
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
