
#include "mpi.h"
#include <cstdio>

int main(int argc, char **argv)
{
	int rank, size, required = MPI_THREAD_MULTIPLE, provided;
	MPI_Init_thread(&argc,&argv,MPI_THREAD_MULTIPLE,&provided);

	if (provided < required) {
		printf("your MPI library does not support required threading level\n");

	}
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("threaded hello world from rank %d / %d\n", rank, size);

	MPI_Finalize();
	return 0;
}
