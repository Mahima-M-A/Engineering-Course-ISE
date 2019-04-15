//Program to find the minimum spanning tree(MST) from the given undirected graph entered as a cost matrix

#include<stdio.h>
int u,v,n,i,j,ne=1;
int min,mincost=0,cost[20][20];
void prims(int source)
{
    int visited[20];
    visited[source]=1; //since source vertex is the first to be visited
    while(ne<n) //until all the vertices are visited
    {
        min=999; 
        //to find the edge with the least value
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min) //to check if it is less than the min value
                    if(visited[i]!=0) //and if it is not visited
                    {
                        min=cost[i][j]; //the present value becomes the min
                        u=i; //store the start vertex of the edge
                        v=j; //store the end vertex of the edge
                    }
        if(visited[u]==0 || visited[v]==0) //if either of the vertices of the found edge hasn't been visited
        {
            printf("Edge %d:(%d->%d) cost:%d\n",ne++,u,v,min); //display the edge
            mincost+=min; //add it value to the total cost
            visited[v]=1; //mark it visited
        }
        cost[u][v]=cost[v][u]=999; //make changes to the cost matrix so that it is no more the edge with min value
    }
}
int main()
{
    int source;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the cost matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) 
                cost[i][j]=999; //to enable the calculation if there is no direct edge b/w the vertices
        }
    printf("Enter the source node\n");
    scanf("%d",&source);
    prims(source); //call the function
    printf("Minimum cost=%d\n",mincost);
    return 0;
}
