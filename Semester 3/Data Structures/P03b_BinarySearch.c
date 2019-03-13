//Program to search for a number using binary search technique

#include<stdio.h>

int search(int key,int a[],int low,int high)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(key==a[mid])
        return mid;
    if(key<a[mid])
        return search(key,a,low,mid-1);
    else
        return search(key,a,mid+1,high);
}

void main()
{
    int i,n,a[20],item,pos;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d of elements:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched for:");
    scanf("%d",&item);
    pos=search(item,a,0,n-1);
    if(pos==-1)
        printf("Item not found");
    else
        printf("Item found at %d",pos);
}
