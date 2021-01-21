// MPI program to compute Matrix-Matrix Multiplication using self-scheduling algorithm.

#include<stdio.h>
#include<mpi.h>
#include<sys/time.h>
#define N 4 //Size of matrix

MPI_Status status;
double a[N][N], b[N][N], c[N][N];

int main(int argc, char* argv[])
{
        int size, rank, nworkers, src, dest, rows, offset, i, j, k;
        struct timeval start, stop;
        
		MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        
		nworkers = size-1;
        if(rank==0)
		{
            for(i=0; i<N; i++)
                for(j=0; j<N; j++)
				{
                	a[i][j]=1.0;
                    b[i][j]=2.0;
                }
            double t1 = MPI_Wtime();
            rows = N/nworkers;
            offset = 0;
            for(dest=1; dest<=nworkers; dest++)
			{
                MPI_Send(&offset, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
                MPI_Send(&rows, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
                MPI_Send(&a[offset][0], rows*N, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
                MPI_Send(&b, N*N, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
                offset=offset+rows;
            }
            for(i=1; i<=nworkers; i++)
			{
                src=i;
                MPI_Recv(&offset, 1, MPI_INT, src, 2, MPI_COMM_WORLD, &status);
                MPI_Recv(&rows, 1, MPI_INT, src, 2, MPI_COMM_WORLD, &status);
                MPI_Recv(&c[offset][0], rows*N, MPI_DOUBLE, src, 2, MPI_COMM_WORLD, &status);
            }
            double t2 = MPI_Wtime();
            printf("Result matrix:\n");
            for(i=0; i<N; i++)
			{
                for(j=0; j<N; j++)
                	printf("%6.2f ", c[i][j]);
                printf("\n");
            }
            printf("Time = %f\n\n",(t2-t1));
        }
        if(rank>0)
		{
            src=0;
            MPI_Recv(&offset, 1, MPI_INT, src, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(&rows, 1, MPI_INT, src, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(&a, rows*N, MPI_DOUBLE, src, 1, MPI_COMM_WORLD, &status);
            MPI_Recv(&b, N*N, MPI_DOUBLE, src, 1, MPI_COMM_WORLD, &status);
            for(k=0; k<N; k++)
            	for(i=0; i<rows; i++)
				{
                	c[i][k]=0.0;
                    for(j=0; j<N; j++)
                    	c[i][k]=c[i][k]+a[i][j]*b[j][k];
                }
            MPI_Send(&offset, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
            MPI_Send(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
            MPI_Send(&c, rows*N, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
        }
        MPI_Finalize();
}
