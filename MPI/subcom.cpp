
#include "mpi.h"

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// divide processes to a grid
	int dims[2] = { 0, 0 };
	MPI_Dims_create(size, 2, dims);
	int ROWS = dims[0], COLS = dims[1];

	int row = rank / COLS;
	int col = rank % COLS;

	if (rank == 0) {
		for (int r = 0, rr = 0; r < ROWS; ++r) {
			for (int c = 0; c < COLS; ++c, ++rr) {
				printf("%2d ", rr);
			}
			printf("\n");
		}
	}
	MPI_Barrier(MPI_COMM_WORLD);

	struct COMM {
		int rank, size;
		MPI_Comm comm;
	};

	// create sub-communicators for each row / column
	COMM row_comm, col_comm;
       	int key = 0;
	MPI_Comm_split(MPI_COMM_WORLD,row,key,&row_comm.comm);
	MPI_Comm_split(MPI_COMM_WORLD,col,key,&col_comm.comm);

	// get rank and size for new communicators
	MPI_Comm_rank(row_comm.comm,&row_comm.rank);
	MPI_Comm_size(row_comm.comm,&row_comm.size);
	MPI_Comm_rank(col_comm.comm,&col_comm.rank);
	MPI_Comm_size(col_comm.comm,&col_comm.size);

	// compute sum of all global ranks within each row/column
	int row_sum, col_sum;
	MPI_Allreduce(&row_comm.rank,&row_sum,1,MPI_INT,MPI_SUM,row_comm.comm);
	MPI_Allreduce(&col_comm.rank,&col_sum,1,MPI_INT,MPI_SUM,col_comm.comm);

	printf("COMM_WORLD[%2d], ROW_COMM[%2d], COL_COMM[%2d], ROW_SUM=%d, COL_SUM=%d\n", rank, row_comm.rank, col_comm.rank, row_sum, col_sum);

	MPI_Finalize();
	return 0;
}
