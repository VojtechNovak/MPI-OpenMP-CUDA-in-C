
#include "mpi.h"
#include <cstdio>
#include <vector>
#include <string>

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	std::string header("header\n");

	std::vector<char> data(size, '0' + rank);

	MPI_Datatype dtype;
	MPI_Type_vector(size,1,size+rank,MPI_CHAR,&dtype);
	MPI_Type_commit(&dtype);

	MPI_File MPIfile;

	if (MPI_File_open(MPI_COMM_WORLD, "fileview.txt", MPI_MODE_WRONLY | MPI_MODE_CREATE, MPI_INFO_NULL, &MPIfile)) {
		printf("MPI cannot create file\n");
	} else {
		if (rank == 0) {
			MPI_File_write_at(MPIfile, 0, header.data(), header.size(), MPI_CHAR, MPI_STATUS_IGNORE);
		}
		MPI_File_set_view(MPIfile,header.size(),MPI_BYTE,dtype,"native",MPI_INFO_NULL);
		MPI_File_write_all(MPIfile,data.data(),size,MPI_CHAR,MPI_STATUS_IGNORE);
		MPI_File_close(&MPIfile);
	}

	MPI_Type_free(&dtype);
	MPI_Finalize();
	return 0;
}
