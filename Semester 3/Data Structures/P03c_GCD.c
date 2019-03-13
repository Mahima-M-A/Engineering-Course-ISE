//Program to calculate gcd of 2 numbers

#include<stdio.h>

int gcd(int m,int n)
{
    if(n==0)
        return m;
    if(m<n)
        return gcd(n,m);
    return gcd(n,m%n);
}

void main()
{
    int m,n,res;
    printf("Enter values of m,n:");
    scanf("%d%d",&m,&n);
    res=gcd(m,n);
    printf("gcd(%d,%d)=%d",m,n,res);
}
