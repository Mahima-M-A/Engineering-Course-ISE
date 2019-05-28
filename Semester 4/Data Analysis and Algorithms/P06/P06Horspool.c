//Program to implement string matching using horspool technique and print the starting position of the found pattern

#include<stdio.h>
int* shiftTable(char p[]) //to construct the shift table for the pattern to be found
{
    static int table[128];
    int m=strlen(p);
    for(int i=0;i<128;i++)
        table[i]=m; //initialize all the ascii values with the size of the pattern 
    for(int i=0;i<=m-2;i++)
    {
       table[p[i]]=m-1-i; //finding the value each character present inthe pattern
    }
    return table;
}

int horspool(char p[],char t[]) //to find the pattern in the text
{
    int m=strlen(p),n=strlen(t);
    int *s=shiftTable(p);
    int i=m-1,k;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && p[m-1-k]==t[i-k])
        {
            k=k+1;
        }
        if(k==m)
            return i-m+1;
        else
            i=i+s[t[i]];
    }
    return -1;
}
void main()
{
    char p[100],t[200];
    printf("Enter a text:\n");
    gets(t);
    printf("\nEnter a pattern to be found: ");
    gets(p);
    int pos=horspool(p,t); //calls the horspool() 
    if(pos==-1)
        printf("\n%s is not found",p);
    else
        printf("\n%s is found at position %d",p,pos);
}
