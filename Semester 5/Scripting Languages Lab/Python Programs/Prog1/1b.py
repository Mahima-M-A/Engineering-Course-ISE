#Program to find the frequency of the words present in a given file
import os,sys

if(len(sys.argv)!=2):
    print("Invalid arguments")
    sys.exit()

if(not(os.path.exists(sys.argv[1]))):
    print("File path does not exist")
    sys.exit()

if(sys.argv[1].split(".")[1]!="txt"):
    print("Invalid file format. Only TXT files are allowed.")
    sys.exit()

dic={}
with open(sys.argv[1]) as file:
    for line in file:
        for word in line.split():
            dic[word]=dic.get(word,0)+1

print("Frequency of the words present in the file:")
for k,v in dic.items():
    print(k,' - ',v)
