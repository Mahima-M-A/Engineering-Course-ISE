//Program to sort the elements using bubble sort.plot a graph of input size v/s time taken to sort and to determine the time efficiency class 

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
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])  //comparison - basic operation
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    clock_t end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal time taken: %f",total);
}

/* Input size(n)  -  Time taken(total)
       5000       -     0.046000
       7500       -     0.141000
      10000       -     0.265000
      12500       -     0.422000
      15000       -     0.625000
      17500       -     0.890000
 
The basic operation in this algorithm is the comparison made.
Hence the time complexity is found to be n^2 and it belongs to O(n^2). */
