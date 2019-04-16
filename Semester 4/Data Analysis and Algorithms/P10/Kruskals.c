//Program to find the minimum spanning tree(MST) from the given undirected graph entered as a cost matrix using Kruskal's algorithm

#include<stdio.h>
int cost[20][20];
void kruskals(int n) //to find the MST edges
{
    int i,j,min,a,u,b,v,parent[20]={0},ne=1,min_cost=0;
    printf("The edges of the minimum spanning tree are: \n ");
    while(ne<n) //loops until all the vertices of the graph are visited 
    {
        min=999;
        //to find the edge with the least value
        for(i=1;i<=n;i++) 
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;

                }
            }
        //to check if the minimum edge found is going to make a cycle or not
        while(parent[u])
            u=parent[u];
        while(parent[v])
            v=parent[v];
        if(u!=v) //satisfied only if the edge doesn't form a cycle 
        {
            printf("\nEdge %d:(%d -> %d) =%d \n",ne++,a,b,min);
            min_cost+=min;
            parent[b]=u;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost is %d \n ",min_cost);
}
void main()
{
    int n,i,j;
    printf("Number of vertices: \n ");
    scanf("%d",&n);
    printf("Enter the cost matrix \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
                cost[i][j]=999;
        }
    kruskals(n); //calls the function
}
