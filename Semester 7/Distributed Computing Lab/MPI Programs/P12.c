// MPI Program which searches integers between A and B for a value J such that F(J) = C

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int f(int i) //Can be any fuction value
{
    return i * i; 
}

int search(int a, int b, int c, int rank, int size)
{
    int fi,i,j=-1;
    for(i=a+rank;0<i&&i<=b;i+=size)
	{
        fi=f(i);
        if(fi==c){
            j=i;
            break;
        }
    }
    return j;
}


void main(int argc, char* argv[])
{
    int a,b,c,rank,j,size;
    double wtime;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    a=1; b=10000000; c=49;  // C should be a perfect square to get a result 
    
    if(rank==0)
        printf("A=%d,\tB=%d,\tC=%d\n",a,b,c);
    
    wtime=MPI_Wtime();
    j=search(a,b,c,rank,size);
    wtime=MPI_Wtime()-wtime;
    
    if(j!=-1)
        printf("Process %d found J=%d\nVerified F(%d)=%d\nTime taken: %lf\n",rank,j,j,f(j),wtime);
    
    MPI_Finalize();
}