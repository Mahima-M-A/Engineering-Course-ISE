l1=['is21','tim','tom','is18','293fn','fin4']

print(l1[1::2]) #to print strings in even position

#to convert every third string to uppercase
for i in range(2,len(l1),3):
	print(l1[i].upper())

#to reverse every string of the list
for str in l1:
	print(str[::-1])

#to extract numbers from all strings
for s in l1:
	n=''.join(filter(lambda i:i.isdigit(),s))
	if n=='':
		print('There are no numbers in ',s)
	else:
		print(n)
