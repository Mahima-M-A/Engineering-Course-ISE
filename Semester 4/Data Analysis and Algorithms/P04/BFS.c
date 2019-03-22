//Program to find all the reachable vertices from the given source vertex of a digraph(entered in the form of an adjacency matrix)

#include<stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;


void bfs(int v)
{
 for(i = 1; i <= n; i++)
 	if(a[v][i] && !visited[i]) //checks if the vertex is already visited or not
 	  q[++r] = i; //the vertex gets added to the q if it wasn't visited earlier

 if(f <= r) //checks if the are any elements in the q or not
 {
 	visited[q[f]] = 1; //marks the elements off the queue as visited vertices
 	bfs(q[f++]); //calls the bfs() and passes the element which is popped from the queue as the next source
 }
}

int main()
{
 int v;
 printf("Enter the number of vertices:");
 scanf("%d", &n);
 for(i=1; i <= n; i++) //to initialize q and visited arrays
 {
 	q[i] = 0;
 	visited[i] = 0;
 }
 printf("\nEnter the adjacency matrix:\n");
 for(i=1; i<=n; i++)
 	for(j=1;j<=n;j++)
 		scanf("%d", &a[i][j]);
 printf("\nEnter the starting vertex:");
 scanf("%d", &v);
 bfs(v); //call the bfs() and pass the source vertex
 printf("\nThe nodes which are reachable from %d are:\n",v);
 for(i=1; i <= n; i++)
 	if(visited[i])
 		printf("%d\n", i); //prints all the vertices that are reachable from the source vertex

	return 0;
}
