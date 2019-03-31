//Program to implement Floyd's algorithm to compute the All-Pairs-Shortest-Paths

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int a[n][n];
    printf("\nEnter the weighted matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],(a[i][k]+a[k][j])); //to choose the minimum value path

    printf("\nDistance matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

