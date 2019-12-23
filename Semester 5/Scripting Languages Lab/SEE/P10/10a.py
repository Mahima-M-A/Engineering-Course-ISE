from functools import reduce
l1=[2,3,4,1,5]
print(l1)
l2=[x*3 for x in l1]
print(l2)
suml1=reduce(lambda x,y: x+y, l1)
suml2=reduce(lambda x,y: x+y, l2)
print('Sum of l1: ',suml1)
print('Sum of l2: ',suml2)