def atomic():
	elements={'H':'hydrogen','He':'helium','Li':'lithium','Be':'beryllium','B':'boron'}
	print('Atomic elements dictionary:\n',elements)
	print('\nTotal number of elements present: ',len(elements))
  
	sym=input("\nEnter a new element's symbol: ")
	name=input("Enter it's name: ")
	elements[sym]=name
  
	sym=input("\nEnter an existing element's symbol: ")
	name=input("Enter a name: ")
	elements[sym]=name
  
	print('Atomic elements dictionary after additions:\n',elements)
	print('\nTotal number of elements present: ',len(elements))
  
	ele=input("\nEnter the element's symbol to be searched for: ")
	if ele in elements.keys():
		print(ele,' is present')
	else:
		print(ele,' is not found')
