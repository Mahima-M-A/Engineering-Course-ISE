class Student:
    def __init__(self,name,age,marks):
        self.name=name
        self.age=age
        self.marks=marks
    def details(self):
        print('\nEntered Details:')
        print('Name: ',self.name)
        print('Age: ',self.age)
        print('Marks obtained in:')
        for i in range(3):
            print('Sub'+str(i+1)+': ',self.marks[i])
    def accept(self):
        self.name=input('\nEnter name:')
        self.age=input('Enter age:')
        print('Enter marks obtained in:')
        for i in range(3):
            self.marks.append(int(input('Sub'+str(i+1)+': ')))

ob1=Student('abc','23',[90,85,89])
ob1.details()
ob2=Student('','',[])
ob2.accept()
ob2.details()