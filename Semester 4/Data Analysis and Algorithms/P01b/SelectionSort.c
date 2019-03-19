//Program to sort the elements using selection sort.plot a graph of input size v/s time taken to sort and to determine the time efficiency class 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int n,x;
    printf("Enter the array size:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        x=rand()%1000;
        a[i]=x;
    }
    clock_t start=clock();
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min]) //Comparison - Basic operation
            {
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    clock_t end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal time taken: %f",total);
}

/* Input size(n)  -  Time taken(total)
       5000       -     0.016000
       7500       -     0.031000
      10000       -     0.063000
      12500       -     0.125000
      15000       -     0.187000
      17500       -     0.297000
 
The basic operation in this algorithm is the comparison made.
Hence the time complexity is found to be n^2 and it belongs to O(n^2). */
