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

#Looping statements(indentation indicates the blocks of statements)
#for-loop and lists
list1=["abc","aa","cats","dog"]
evenList=[]
oddList=[]
for str in list1:
	if len(str)%2==0:
		evenList.append(str)
	else:
		oddList.append(str)
print("Even List: ",evenList)
print("Odd List: ",oddList)

#for-loop and dictionaries
dic={"is20":"tom","is33":"harry","is31":"hand","is21":"finch","is50":"sam"}
print(dic)

dic["is22"]="ram"
print("After additions: ",dic)

usn=[]
for key,value in dic.items():
	if value[0]=='h':
		usn.append(key)

for i in usn:
	del dic[i]

print("Modified dictionary: ",dic)

name=list(dic.values())
name.sort()
print("Sorted names: ",name)

#functions
l1=[1,3,2,4,5]
l2=[8,7,9]
l3=l2.copy() #to copy the list
l4=[]
l5=[]
def addToList(l1,l2):
	l4=l1+l2
	return l4

def rev(l2):
	l2.reverse()
	return l2

def addRev(l1,l3):
	l5=addToList(l1,rev(l3))
	return l5

print("On adding 2 lists: ",addToList(l1,l2))
print("on reversing a list: ",rev(l2))
print("On adding a reversed list to another list: ",addRev(l1,l3))
