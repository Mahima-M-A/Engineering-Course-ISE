class Reverse:
	def __init__(self,sen):
		self.sen=sen
	def rev(self):
		s=self.sen
		w=s.split(" ")
		w.reverse()
		for str in w:
			print(str,end=" ")
		print()

c=0
s=[]

#to input 3 sentences
while c<3:
	sen=input("Enter a sentence: ")
	s.append(sen) #to create a list of the entered sentences
	c+=1

#to sort the entered sentences in descending order based on the number of vowels in each of them 
s1=sorted(s,key=lambda word: sum(ch in 'AEIOUaeiou' for ch in word),reverse=True)

#to reverse the words in each of the sentences
for sen in s1:
    ob=Reverse(sen) #to create an instance class Reverse
    ob.rev() #to call the rev() present in the class
