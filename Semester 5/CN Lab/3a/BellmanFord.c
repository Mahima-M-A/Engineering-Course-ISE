#include <stdio.h>
#include <stdlib.h>
int S;
int parent(int v,int p[20]){
    if(p[v]==S)
        return S;
    printf(" %d <-",p[v]);
    return parent(p[v],p);
}
int bf(int G[20][20] , int V, int E, int edge[20][2]){
    int i,j,u,v,k,distance[20],p[20],flag=1;
    for(i=0;i<V;i++){
        distance[i] = 1000 ;
        p[i] = -1 ;
    }
    printf("Enter source: ");
    scanf("%d",&S);
    distance[S]=0 ;
    for(i=0;i<V-1;i++){
        for(k=0;k<E;k++){
            u = edge[k][0];
            v = edge[k][1];
            if(distance[u]+G[u][v] < distance[v]){
                distance[v] = distance[u] + G[u][v] ;
                p[v]=u;
            }
        }
    }
    for(k=0;k<E;k++){
        u = edge[k][0] ;
        v = edge[k][1] ;
        if(distance[u]+G[u][v] < distance[v])
            flag = 0 ;
    }
    if(flag){
        printf("\nFrom source vertex %d to:\n",S);
        for(i=0;i<V;i++){
            if(i!=S){
                printf("Vertex %d -> cost = %d\n",i,distance[i]);
                printf("path: %d <-",i);
                printf(" %d\n",parent(i,p));
            }
        }
    }
    return flag;
}

int main(){
    int V,edge[20][2],G[20][20],i,j,k=0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0){
                edge[k][0]=i;
                edge[k++][1]=j;
            }
        }

    if(bf(G,V,k,edge))
        printf("\nNo negative weight cycle\n");
    else 
        printf("\nNegative weight cycle exists\n");
    return 0;
}
