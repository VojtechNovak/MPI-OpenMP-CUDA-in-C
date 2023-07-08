
#include "mpi.h"
#include <cstdio>
#include <vector>
#include <string>

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int i[2];

	i[0] = rank;
	i[1] = 10 * rank;

	MPI_Datatype mytype;
	MPI_Type_contiguous(2,MPI_INT,&mytype);
	MPI_Type_commit(&mytype);

	int data = rank;
	int next = (rank + 1) % size;
	int prev = (rank - 1 + size) % size;

	MPI_Request req[2];
	MPI_Isend(&i, 1, mytype, next, 0, MPI_COMM_WORLD, req + 0);
	MPI_Irecv(&i, 1, mytype, prev, 0, MPI_COMM_WORLD, req + 1);

	MPI_Waitall(2, req, MPI_STATUSES_IGNORE);

	printf("rank[%d]: %d, %d\n", rank, i[0], i[1]);

	MPI_Type_free(&mytype);
	MPI_Finalize();
	return 0;
}
