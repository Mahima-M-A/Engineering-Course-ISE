l=[]
print("Enter 5 elements:")
for i in range(5):
    l.append(int(input()))

print("Maximum value: ",max(l))
print("Minimum value: ",min(l))

print("Inserting a new element 100 into the list")
l.append(100)
print(l)

print("Removing an existing element(here 100) from the list ")
l.remove(100)
print(l)

ele=int(input("Enter an element to be found:"))
if ele in l:
    print(ele," is present at position ",l.index(ele))
else:
    print(ele," is not present in the list")