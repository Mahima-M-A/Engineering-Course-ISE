/*Program to sort a given set of elements using merge sort,plot a graph for input size v/s time taken to execute 
and find the time efficiency class to which it belongs*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int l,int mid,int r,int b[]) //to sort the elements and simultaneously merge the left and right halves of the array
{
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r) //when both the halves contain elements
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid) //when the right half is empty
        b[k++]=a[i++];
    while(j<=r) //when the left half is empty
        b[k++]=a[j++];
    for(int i=l;i<=r;i++) //to copy the sorted elements back into the original array
        a[i]=b[i];
}

void mergeSort(int a[],int l,int r,int b[])
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(a,l,mid,b);  //to obtain the left halves of the array
        mergeSort(a,mid+1,r,b); //to obtain the right halves of the array
        merge(a,l,mid,r,b); //to sort and merge
    }
}


void main()
{
    int n,x;
    printf("Enter array size:");
    scanf("%d",&n);
    int a[n],b[n]; //b is an additional array used hence this is an out of place algorithm
    for(int i=0;i<n;i++)
    {
        x=rand()%1000;
        a[i]=x;
    }
    clock_t start=clock();
    mergeSort(a,0,n-1,b);
    clock_t end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal time taken: %f",total);
}

/* Input size(n)  -  Time taken(total)
       5000       -     0.000612
       7500       -     0.001308
      10000       -     0.002053
      12500       -     0.002789
      15000       -     0.003381
      17500       -     0.004366
 
The time complexity of this algorithm is found to be nlog n and it belongs to O(nlog n). */
