
#include "mpi.h"
#include <cstdio>
#include <string>

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_File MPIfile;
                 if (MPI_File_open(MPI_COMM_WORLD, "offset.txt", MPI_MODE_WRONLY | MPI_MODE_CREATE, MPI_INFO_NULL, &MPIfile)) {
		printf("MPI cannot create file\n");
	} else {
		char c = '0' + rank;
		for (int i = 0; i < 10; ++i) {
			   MPI_File_write_at_all(MPIfile,rank + size* i,&c, 1, MPI_CHAR,MPI_STATUS_IGNORE);
			 		}
          MPI_File_close(&MPIfile);
	}

	MPI_Finalize();
	return 0;
}
