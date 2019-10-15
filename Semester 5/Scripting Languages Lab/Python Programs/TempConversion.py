def ctof(c):
    f=(9/5)*c+32
    history.append((str(c)+' deg C to '+str(f)+' deg F'))
    return f

def ftoc(f):
    c=(f-32)*5/9
    history.append((str(f)+' deg F to '+str(c)+' deg C'))
    return c

def ctok(c):
    k=c+273.15
    history.append((str(c)+' deg C to '+str(k)+' K'))
    return k

def ktoc(k):
    c=k-273.15
    history.append((str(k)+' K to '+str(c)+' deg C'))
    return c

def ftok(f):
    k=((f-32)*5/9)+273.15
    history.append((str(f)+' deg F to '+str(k)+' K'))
    return k

def ktof(k):
    f=((9/5)*(k-273.15))+32
    history.append((str(k)+' K to '+str(c)+' deg F'))
    return c

history=[]
while("true"):
    print("\nMenu:\n1.Celcius to fahrenheit\n2.Fahrenheit to celcius\n3.Celcius to kelvin\n4.Kelvin to Celcius\n5.Fahrenheit to Kelvin\n6.Kelvin to Fahrenheit\n7.View history\n-1.exit\nEnter choice:")
    ch=input()
    if ch=='1':
        t=float(input("Enter temp in celcius:"))
        print("Temperature in Fahrenheit: ",ctof(t))
    elif ch=='2':
        t=float(input("Enter temp in fahrenheit:"))
        print("Temperature in Celcius: ",ftoc(t))
    elif ch=='3':
        t=float(input("Enter temp in celcius:"))
        print("Temperature in Kelvin: ",ctok(t))
    elif ch=='4':
        t=float(input("Enter temp in kelvin:"))
        print("Temperature in Celcius: ",ktoc(t))
    elif ch=='5':
        t=float(input("Enter temp in fahrenheit:"))
        print("Temperature in Kelvin: ",ftok(t))
    elif ch=='6':
        t=float(input("Enter temp in kelvin:"))
        print("Temperature in Fahrenheit: ",ktof(t))
    elif ch=='7':
        print("History of conversions:\n",history)
    elif ch=='-1':
        break
    else:
        print("Invalid choice")
