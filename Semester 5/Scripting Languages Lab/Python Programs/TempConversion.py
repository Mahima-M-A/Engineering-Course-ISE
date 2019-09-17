def ctof():
	c=float(input("Enter temperature in celcius: "))
	f=(9/5)*c+32
	print("temperature in fahrenheit: ",f)

def ctok():
	c=float(input("Enter temperature in celcius: "))
	k=c+273.15
	print("temperature in kelvin: ",k)

while "true":
	print("Conversions:\n1. To fahrenheit\n2. To kelvin\n-1. To exit:")
	ch=input("Enter choice: ")
	if ch=='1':
		ctof()
	elif ch=='2':
		ctok()
	elif ch=='-1':
		break
	else:
		print("Invalid choice!")
