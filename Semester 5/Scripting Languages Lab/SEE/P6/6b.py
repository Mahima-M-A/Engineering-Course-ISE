class Reverse:
    def __init__(self,sen):
        self.sen=sen
    def rev(self):
        s=self.sen
        words=s.split()
        words.reverse()
        for w in words:
            print(w,end=' ')
        print()

c=0
sen=[]
while c<3:
    sen.append(input("Enter a sentence:"))
    c+=1

s1=sorted(sen,key=lambda word: sum(ch in 'AEIOUaeiou' for ch in word), reverse=True)

for s in s1:
    ob=Reverse(s)
    ob.rev()