// MPI program that computes the value of PI using Monto-Carlo Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>
 
int main(int argc, char* argv[])
{
    int niter = 100000;
    int rank, size;
    double x, y;
    int i, count=0;
    double pi;
    int reducedcount, reducedniter;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
 
	srand(time(NULL)+rank);
    for (i=0; i<niter; ++i)
    {
        x = (double)random()/RAND_MAX;
        y = (double)random()/RAND_MAX;
        double z = sqrt((x*x)+(y*y));
        if (z <= 1) {
            count++;
        }
    }
     
 
    MPI_Reduce(&count, &reducedcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&niter, &reducedniter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
     
    if(rank == 0) {
        pi = ((double)reducedcount / (double)reducedniter) * 4.0;
        printf("Value of PI: %f\n", pi);
    }
 
    MPI_Finalize();
    return 0;
}