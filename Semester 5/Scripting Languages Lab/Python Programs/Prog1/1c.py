#Program to find the maximum of 'n' numbers using recursive function
def maximum(l):
    if len(l)==1:
        return l[0]
    else:
        return max(l[0],maximum(l[1:]))

l1=[]
print("Enter 5 numbers:")
for i in range(5):
	l1.append(int(input()))

print("The maximum number is: ",maximum(l1))
