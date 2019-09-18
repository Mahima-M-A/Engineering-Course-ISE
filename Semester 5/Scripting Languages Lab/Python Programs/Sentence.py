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
n=0
s=[]

while c<3:
	sen=input("Enter a sentence: ")
	s.append(sen)
	c+=1
s1=sorted(s,key=lambda word: sum(ch in 'AEIOUaeiou' for ch in word),reverse=True)
for sen in s1:
    ob=Reverse(sen)
    ob.rev()
