import os,sys
from functools import reduce

wordlen=[]
dic={}

if len(sys.argv)!=2:
    print('Invalid argument list')
    sys.exit()

if not(os.path.exists(sys.argv[1])):
    print('File does not exist')
    sys.exit()

if sys.argv[1].split('.')[1]!='txt':
    print('Invalid file format. Only .txt files are supported')
    sys.exit()

with open(sys.argv[1]) as file:
    for line in file:
        for word in line.split():
            dic[word]=dic.get(word,0)+1

sortedDic=sorted(dic.items(),key= lambda dicItem:dicItem[1], reverse=True)

for i in range(10):
    try:
        wordTuple=sortedDic[i]
        wordlen.append(len(wordTuple[0]))
        print(wordTuple[0],'   length: ',len(wordTuple[0]),'    frequency: ',wordTuple[1])
    except IndexError:
        print('The file contains less than 10 words')

sum=reduce(lambda x,y: x+y,wordlen)
print('Avg of the word lengths: ',sum/len(wordlen))

squares=[x**2 for x in wordlen if x%2==0]
print('Squares of odd word lengths: ',squares)