class BankAccount:
    def __init__(self):
        self.__balance = 0
    def withdraw(self, outamount):
        self.__balance -= outamount
        print("통장에서 %d가 출금되었음." %outamount)
        return self.__balance
    def deposit(self, inamount):
        self.__balance += inamount
        print("통장에 %d가 입금되었음." %inamount)
        return self.__balance

a = BankAccount()
a.deposit(100)
a.withdraw(10)
