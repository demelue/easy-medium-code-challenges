class Employee(object):

    percent_raise = 1.0

    def __init__(self, name, pay):
        self.name = name
        self.pay = pay

    def employee_promotion(self):
        self.pay *= self.percent_raise

    def employee_salary(self):
        print(self.pay)

    def employee_name(self):
        print("My name is " + self.name)
    @classmethod
    def create_employee(cls, employee_str):
        pass

    @staticmethod
    def sample_static_method(count):
        for i in range(count):
            print(i)

class Developer(Employee):
    percent_raise = 2.0
    def __init__(self, name, pay, lang):
        super().__init__(name, pay)
        self.lang = lang

    def programming(self):
        print("I program in " + self.lang)


class Engineer(Developer):
    percent_raise = 4.0
    def __init__(self, name, pay, lang):
        super().__init__(name, pay, lang)


class Others(Employee):

    def __init__(self, name, pay, business_model):
        super().__init__(name, pay)
        self.business_model = business_model

    def programming(self, product):
        print("I can create a " + self.business_model + " for a " + product)

if __name__ == "__main__":
    dev = Developer("John", 15000, "python")
    engr = Engineer("Paul", 20000, "C/C++")
    business = Others("Peter", 10000, "Reverse P&L")

    dev.employee_promotion()
    dev.employee_salary()
    dev.programming()

    engr.employee_promotion()
    engr.employee_salary()
    engr.programming()

    business.employee_promotion()
    business.employee_salary()
    business.programming("Watch")

    # print(business.percent_raise)
