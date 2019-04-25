/*Program to sort a set of elements using heap sort, plot a graph for input size v/s time taken to execute and 
find its time efficiency class*/

#include<stdio.h>
#include <stdlib.h>
#include<time.h>

void heapify(int a[],int n) //to heapify the elements
{
    int i,k,j,v,heap;
    for(i=n/2;i>=1;i--) //to consider only the parental nodes
    {
        k=i;
        v=a[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n)
                if(a[j]<a[j+1])
                    j+=1;
            if(v>=a[j])
                heap=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }

}

void heapSort(int a[],int n) //to sort the heapified node elements in ascending order
{
    int i,size=n;
    for(i=1;i<=n;i++)
    {
        int temp=a[size];
        a[size]=a[1];
        a[1]=temp;
        size-=1;
        heapify(a,size);
    }
}

void main()
{
    int n,i,t,size;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    int a[n];
    for(i=1;i<=n;i++)
    {
        int x=rand()%1000;
        a[i]=x;
    }
    clock_t start1=clock();
    heapify(a,n);
    clock_t end1=clock();
    printf("\nAfter heapification:\n");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    clock_t start2=clock();
    heapSort(a,n);
    clock_t end2=clock();
    double total=(double)((end1-start1)+(end2-start2))/CLOCKS_PER_SEC;
    printf("\nSorted elements:\n");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("\nTotal time taken= %f",total);
}


/* Input size(n)  -  Time taken(total)
       2500       -     0.031000
       5000       -     0.175000
       7500       -     0.375000
      10000       -     0.672000
      12500       -     0.968000
      15000       -     1.374000
 
 The time complexity is found to be nlog n and it belongs to O(nlog n). */
