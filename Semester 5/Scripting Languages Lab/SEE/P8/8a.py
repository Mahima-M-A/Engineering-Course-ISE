def atomic():
    elements={'H':'hydrogen','O':'oxygen','N':'nitrogen','Si':'silicon','He':'helium'}
    print('Atomic elements list: ',elements)
    ele=input("Enter a new Symbol: ")
    name=input("Enter its name: ")
    elements[ele]=name
    ele=input("Enter an existing symbol: ")
    name=input("Enter its name: ")
    elements[ele]=name
    print('New list: ',elements)
    print('No. of elements present in the list: ',len(elements))
    ele=input("Enter an element's symbol to be found: ")
    if ele in elements:
        print(ele,' is present')
    else:
        print(ele,' is not present')

atomic()