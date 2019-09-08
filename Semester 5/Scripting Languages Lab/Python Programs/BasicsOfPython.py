#To print
print("Hello World!")

#Datatypes of variables need not be specified
a=15
b=5.6
c='abc'
print("Name: ",c)
print("Height: ",b)
print("Age: ",a)

#Multiple values can be assigned in the same line
a,b,c=65,5.4,'pqr'
print("Name: ",c)
print("Height: ",b)
print("Age: ",a)

#The same variables can be updated with values of different datatypes
a,b,c='xyz',10,4.2
print("Name: ",a)
print("Height: ",c)
print("Age: ",b)

#String manipulation
str='Hello World'
print(str)
print('Length: ',len(str))
print(str*2)
print(str+'!')
print(str[0]) #first character
#substrings
print(str[1:4])
print(str[3:])
print('On splitting: ',str.split(" "))
print('On replacement: ',str.replace(" World","!"))

#To return the datatype of a variable
x=1
y=3.5e10
z=-5j
p='a'
print(type(x)) #returns class<int>
print(type(y)) #returns class<float>
print(type(z)) #returns class<complex>
print(type(p)) #returns class<str>

#Lists(mutable)
list1=['a',1.2,3]
list2=[7.5,'xyz']
print(list1)
print(list1*2) #to print its values twice
print(list1[2]) #to access the third value
#to access a part of the list
print(list1[0:2])
print(list1[1:])
print(list1+list2) #to combine

#Tuples(immutable)
t1=('a',1.2,3)
t2=(6,'p')
print(t1)
print(t1+t2) #to combine
print(t2*2) #to print its values twice
#t1[1]=6.5  (error - can not reassign to a tuple)
print(t2[1]) #to access the second value

#Dictionary(Key-Value Pairs)
dic={"int":1, "string":"abcd"}
print(dic)
print(dic["int"]) #returns value of key "int"
print(dic.get("string")) #returns value of key "string"

#Conditional Statements(indentation indicates the blocks of statements)
x=-2
if x>0:
  print("Posiitve")
elif x<0:
  print("Negative")
  x*=x #x=4 (here onwards)
else:
  print("Zero")

#Rewriting the above statements using nested if
if x>0:
  print("Positive")
else:
  if x<0:
    print("Negative")
  else:
    print("Zero")
