class Rectangle:
    def __init__(self,length,breadth):
        self.length=length
        self.breadth=breadth
    def area(self):
        return self.length*self.breadth

l=int(input("Enter length: "))
b=int(input("Enter breadth: "))
ob=Rectangle(l,b)
print('Area of rectangle: ',ob.area())