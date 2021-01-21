// MPI Program for communication among two processes.

#include<stdio.h>
#include<mpi.h>
#include<string.h>
#define BUFFER_SIZE 32

int main(int argc, char* argv[])
{
	int rank,numprocs,tag=0,root=3,temp=1;
	char msg[BUFFER_SIZE];
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	if(rank==3)
	{
		strcpy(msg,"Hello");
		for(temp=0;temp<numprocs;temp++)
		{
			if(temp!=3)
			{
				MPI_Send(msg,BUFFER_SIZE,MPI_CHAR,temp,tag,MPI_COMM_WORLD);
			}
		}
	}
	else
	{
		MPI_Recv(msg,BUFFER_SIZE,MPI_CHAR,root,tag,MPI_COMM_WORLD,&status);
		printf("\nProcess with rank %d sent '%s' to process with rank %d\n", root, msg, rank);
	}
	MPI_Finalize();
}
