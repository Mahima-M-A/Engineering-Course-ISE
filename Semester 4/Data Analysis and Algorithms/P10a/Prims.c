#include<stdio.h>
int u,v,n,i,j,ne=1;
int min,mincost=0,cost[20][20];
void prims(int source)
{
    int visited[20];
    visited[source]=1;
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("Edge %d:(%d->%d) cost:%d\n",ne++,u,v,min);
            mincost+=min;
            visited[v]=1;
        }
        cost[u][v]=cost[v][u]=999;
    }
}
int main()
{
    int source;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);

    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    printf("Enter the source node\n");
    scanf("%d",&source);
    prims(source);
    printf("Minimum cost=%d\n",mincost);
    return 0;
}
