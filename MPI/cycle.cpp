
#include "mpi.h"
#include <vector>
#include <sstream>

int main(int argc, char **argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int length = 10;

        if (argc > 1) {
		std::istringstream( argv[1] ) >> length;
	}

	std::vector<int> sdata(length), rdata(length);
	int right = (rank + 1) % size;
	int left  = (rank - 1 + size) % size;
        if (rank) {
         MPI_Ssend(sdata.data(),length,MPI_INT,right,0,MPI_COMM_WORLD);
         MPI_Recv (rdata.data(), length, MPI_INT, left , 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else{
        MPI_Recv(rdata.data(),length,MPI_INT,left,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	MPI_Ssend(sdata.data(), length, MPI_INT, right, 0, MPI_COMM_WORLD);
        }
        MPI_Finalize();
	return 0;
}
