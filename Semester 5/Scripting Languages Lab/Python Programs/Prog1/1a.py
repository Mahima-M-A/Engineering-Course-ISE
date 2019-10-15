#function to remove duplicates from the list
def remDup(l1):
    for i in l1:
        if i not in l2:
            l2.append(i)
    return l2

l1=[]
l2=[]
n=int(input("Enter list size: "))
print("Enter ",n," elements:")
for i in range(n):
    l1.append(int(input()))

print("List of elements after removing the duplicates: ",remDup(l1))

l3=[n for n in l2 if n%2==0]
print("List of even numbers present in the entered list: ",l3) #after removing duplicates

print("Reverse of the entered list: ",l2[::-1]) #after removing duplicates
