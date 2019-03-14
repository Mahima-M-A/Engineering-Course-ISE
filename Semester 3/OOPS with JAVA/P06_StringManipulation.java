//Program to perform operations on the strings(extraction,frequency,replacement,rearrangement,comparison,concatenation)

import java.util.Scanner;
class P06_StringManipulation
{
    Scanner sc=new Scanner(System.in);
    public static void main(String[] args)
    {
        P0_StringManipulation ob=new P06_StringManipulation();
        ob.extract();
        ob.frequency();
        ob.replaced();
        ob.rearrange();
        ob.compares();
        ob.concatenate();
    }
    void extract() //To perform extraction
    {
        System.out.println("To perform extraction");
        System.out.println("Enter a string:");
        String str=sc.next();
        System.out.println("Enter the start index of extraction:");
        int n=sc.nextInt();
        System.out.println("Enter the number of characters to be extracted:");
        int m=sc.nextInt();
        if((m+n)>str.length()) //to check if extraction is possible or not
            System.out.println("Cannot extract!"); 
        else
            System.out.println("Extracted part of the string: "+str.substring(n,n+m));
    }
    void frequency() //To find the frequency of a word
    {
        System.out.println("To find the frequency of a word");
        System.out.println("Enter a string:");
        sc.nextLine();
        String str=sc.nextLine();
        System.out.println("Enter a word whose frequency is to be found:");
        String word=sc.nextLine();
        if(str.contains(word))
        {
            System.out.println("The entered string does not contain '"+word+"'"); 
            return;
        }
        int count=0;
        String s[]=str.split(" "); //splits the entered sentence into an array of words
        
        for(String words: s)
        {
            if(words.equalsIgnoreCase(word))
                count++; //counts the frequency of the word
        }
        System.out.println("Frequency of '"+word+"' is:"+count);
    }
    void replaced() //To perform replacement
    {
        System.out.println("To perform replacement");
        String str,word,w;
        System.out.println("Enter a string:");
        str=sc.nextLine();
        System.out.println("Enter a word to be replaced:");
        word=sc.nextLine();
        System.out.println("Enter a word to be replaced with:");
        w=sc.nextLine();
        if(str.contains(word))
        {
            System.out.println("The entered string does not contain '"+word+"' to be replaced"); 
            return;
        }
        System.out.println("The string after relacing '"+word+"' with '"+w+"' :"+str.replace(word, w));
    }
    void rearrange() //To perform rearrangement
    {
        System.out.println("To perform rearrangement");
        System.out.println("Enter a word:");
        String word=sc.next();
        char ch[]=word.toCharArray(); //to convert the word into an array of characters
        for(int i=0;i<word.length()-1;i++) //performing bubble sort based on ascii values of characters
            for(int j=0;j<word.length()-i-1;j++)
                if(ch[i]>ch[i+1])
                {
                    char temp=ch[i+1];
                    ch[i+1]=ch[i];
                    ch[i]=temp;
                }
        System.out.println("Original word: "+word);
        System.out.println("Rearranged word: "+String.valueOf(ch)); //converting array of characters into a string
    }
    void compares() //To compare 2 words
    {
        System.out.println("To compare 2 words");
        System.out.println("Enter 2 words:");
        String word1=sc.next();
        String word2=sc.next();
        if(word1.equalsIgnoreCase(word2))
            System.out.println("They are same!");
        else
            System.out.println("They are different!");
    }
    void concatenate() //To concatenate 2 words
    {
        System.out.println("To concatenate 2 words");
        System.out.println("Enter 2 words:");
        String word1=sc.next();
        String word2=sc.next();
        System.out.println("the concatenated word: "+word1.concat(word2));
    }
}
