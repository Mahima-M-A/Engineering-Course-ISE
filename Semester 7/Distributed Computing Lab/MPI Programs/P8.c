// MPI program to compute dot product of two vectors using block-striped partitioning with uniform data distribution

#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<string.h>
#define vectorsize 6

void main(int argc, char **argv)
{
    int  rank, size, scatterSize;
    int C[vectorsize], result;
    int A[vectorsize] = {1, 1, 1, 1, 1, 1};
    int B[vectorsize] = {2, 2, 2, 2, 2, 2};
    
    int vecsize = vectorsize;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(vecsize % size != 0)
    {
        printf("\nDistribution cannot be uniform\n");
        exit(0);
    }
    MPI_Bcast(&vecsize, 1, MPI_INT, 0, MPI_COMM_WORLD);

    scatterSize = vecsize / size;
    
    int buffA[scatterSize], buffB[scatterSize], buffC;

    MPI_Scatter(A, scatterSize, MPI_INT, buffA, scatterSize, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, scatterSize, MPI_INT, buffB, scatterSize, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i = 0; i < scatterSize; i++)
        buffC += buffA[i] * buffB[i];

    MPI_Reduce(&buffC, &result, 1, MPI_REAL, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0)
        printf("\nDot product of the two vectors: %d calculated by %d processes\n", result, size);

    MPI_Finalize();
}