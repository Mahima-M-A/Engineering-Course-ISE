//Program to find the order in which all the nodes of a graph are traversed using Depth First Search(DFS) traversal

#include<stdio.h>
#include<stdlib.h>

int n,count=0,a[20][20],visited[20];

void dfs(int v) //to traverse
{
    int i;
    count+=1;
    printf("%c  ",v+64);
    visited[v]=count;
    for(i=1;i<=n;i++)
        if(a[v][i] && !visited[i]) //to check if there is a direct edge and the vertex is not visited
            dfs(i);
}

void main()
{
    int i,j,s;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("\nEnter the source node: ");
    scanf("%d",&s);
    if(s>0 && s<=n) //to check if the source node is present in the graph or not
    {
        printf("\nThe order in which the vertices were visited is:\n");
        for(i=s;i<=n;i++)
            if(!visited[i])
            {
                dfs(i); //call the function for the vertex which isn't visited
                printf("\n");
            }
        for(i=1;i<s;i++)
            if(!visited[i])
            {
                dfs(i); //call the function for the vertex which isn't visited
                printf("\n");
            }
    }
    else
        printf("\nSource node not found!");
}
