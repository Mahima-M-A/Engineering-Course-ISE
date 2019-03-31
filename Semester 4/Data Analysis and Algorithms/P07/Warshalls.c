//Program to implement Warshall's algorithm to compute the transitive closure of a directed graph

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int a[n][n];
    printf("\nEnter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=a[i][j]||(a[i][k]&&a[k][j]); //choosing either a direct path or through an intermediate vertex

    printf("\nTransitive Closure:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
