//Program to implement the 0/1 knapsack problem using dynamic programming technique(bottom up approach)

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b) //to find the maximum of the two
{
    if(a>b)
        return a;
    else
        return b;
}

void knapsack(int w[],float p[],int cap,int n)
{
    float v[cap+1][n+1];
    int i,j,item[n];
    float profit=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(i==0 || j==0) //for no items or capacity=0
                v[i][j]=0;
            else if(w[i]>j) //if the item's weight is greater than the knapsack's capacity
                v[i][j]=v[i-1][j]; //retain the the previous value
            else //else calculate the max of the previous value or sum of the present value and the value on moving w[i] steps back in the previous row
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]); 
        }
    }
    i=n; 
    j=cap; 
    while(i>0 && j>0) //to loop from the last element of the table
    {
        if(v[i][j]!=v[i-1][j]) //to check if the previous value is equal to the previous value
        {
            item[i]=1; //to mark the selected item
            j=j-w[i];
        }
        i--;
    }
    printf("\nThe items selected are:\n");
    for(i=1;i<=n;i++)
    {
        if(item[i]==1)
        {
            printf("%d \t ",i);
            profit=profit+p[i]; //to calculate the total profit of the selected items
        }
    }
    printf("\n\nTotal profit= Rs. %0.2f",profit);
}

void main()
{
    int n,cap;
    printf("Enter the total no. of objects:");
    scanf("%d",&n);
    printf("\nEnter the knapsack's capacity:");
    scanf("%d",&cap);
    float p[n];
    int w[n],i;
    printf("\nEnter the weights and the values of each object(%d):\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%f",&w[i],&p[i]);
    }
    knapsack(w,p,cap,n);
}
