//Program to sort the elements using quick sort, plot the graph for input size v/s time taken and find the time efficiency class.
//In this program we consider the first element as the pivot element initially

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[],int low,int high) /*to partition the array into two halves(one to the left of the pivot element 
and the other to its right) which implies that we are positioning the the pivot element to its actual position*/
{
    int key=a[low],i=low+1,j=high;
    while(i<=j)
    {
        while(a[i]<=key)
            i++;
        while(a[j]>key)
            j--;
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j; //the true position of the pivot element
}

void qs(int a[],int low,int high)
{
    if(low<=high)
    {
        int pos=partition(a,low,high); //the position(true position) of the pivot element
        qs(a,low,pos-1); //to obtain the left half
        qs(a,pos+1,high); //to obtain the right half
    }
}

void main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    clock_t start=clock();
    qs(a,0,n-1);
    clock_t end=clock();
    double total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal time taken= %f",total);
}

/* Input size(n)  -  Time taken(total)
       2500       -     0.000452
       5000       -     0.000954
       7500       -     0.001480
      10000       -     0.002057
      12500       -     0.002573
      17500       -     0.004366
 
The time complexity(best and average cases) of this algorithm is found to be nlog n and it belongs to O(nlog n)
and n^2 for the worst case and it belongs to O(n^2).*/
