//Program to implement tower of hanoi problem with 'A'-Source, 'B'-Temporary ,'C'-Destination pegs

#include<stdio.h>

void tower(int n,char src,char temp,char dest)
{
    if(n==1)
        printf("Move disk %d from %c to %c\n",n,src,dest);
    else
    {
        tower(n-1,src,dest,temp);
        printf("Move disk %d from %c to %c\n",n,src,dest);
        tower(n-1,temp,src,dest);
    }
}

void main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    tower(n,'A','B','C');
}
