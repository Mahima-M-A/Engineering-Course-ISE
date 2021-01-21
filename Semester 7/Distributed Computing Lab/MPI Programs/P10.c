// Program which creates new communicators involving a subset of initial set of MPI processes in the default communicator MPI_COMM_WORLD

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<time.h>

void main(int argc, char* argv[])
{

    MPI_Comm even_comm_id, odd_comm_id;
    MPI_Group even_group_id, odd_group_id, world_group_id;
    int even_id, even_id_sum, even_p, i, j, rank, size, odd_id, odd_id_sum, odd_p;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    if(rank == 0) {
        printf("\nCommunicatorMPI: Master process\n");
        printf("The number of processes is %d.\n",size);
    }
    
    printf("Process %d says 'Hello World!'\n", rank);
    
    MPI_Comm_group(MPI_COMM_WORLD, &world_group_id);
    
    even_p = (size+1)/2;
    int even_rank[even_p];
    j = 0;
    
	for(i=0; i<size; i+=2)
        even_rank[j++] = i;
    MPI_Group_incl(world_group_id, even_p, even_rank, &even_group_id);
    MPI_Comm_create(MPI_COMM_WORLD, even_group_id, &even_comm_id);
    
    odd_p = size/2;
    int odd_rank[odd_p];
    j = 0;
    
	for(i=1; i<size; i+=2)
        odd_rank[j++] = i;
    MPI_Group_incl(world_group_id, odd_p, odd_rank, &odd_group_id);
    MPI_Comm_create(MPI_COMM_WORLD, odd_group_id, &odd_comm_id);
    
    if(rank%2 != 0)
	{
        MPI_Comm_rank(odd_comm_id, &odd_id);
        even_id = -1;
    }
    
    if(rank%2 == 0)
	{
        MPI_Comm_rank(even_comm_id, &even_id);
        odd_id = -1;
    }
    
    if(even_id != -1)
        MPI_Reduce(&rank, &even_id_sum, 1, MPI_INT, MPI_SUM, 0, even_comm_id);
    
    if(even_id == 0)
        printf("Number of processes in even communicator=%d\n Sum of global ID's in even communicator is :%d\n", even_p, even_id_sum);
    
    if(odd_id != -1)
        MPI_Reduce(&rank, &odd_id_sum, 1, MPI_INT, MPI_SUM, 0, odd_comm_id);
    
	if(odd_id == 0)
        printf("Number of processes in odd communicator=%d\n Sum of global ID's in odd communicator is : %d\n", odd_p, odd_id_sum);
    
    MPI_Finalize();
    
}
