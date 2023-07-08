
#include "mpi.h"
#include <stdio.h>
#include <vector>
#include <sstream>

/*
 *   ------------------- > columns
 *  |
 *  |  up    (me.row - 1)
 *  |  ^
 *  |  me
 *  |  v
 *  |  down  (me.row + 1)
 *  |
 *  v rows
 */

#define FROM_UP_TO_DOWN 0
#define FROM_DOWN_TO_UP 1

struct Grid {
	Grid(int rows, int cols): vals{} { resize(rows, cols); }
	~Grid() { if (vals) delete[] vals; }

	const double& operator()(int r, int c) const { return vals[r * cols + c]; }
	double& operator()(int r, int c) { return vals[r * cols + c]; }

	void resize(int rows, int cols)
	{
		if (vals) delete vals;
		this->rows = rows;
		this->cols = cols;
		this->vals = new double[rows * cols];
	}

	// first rows
	double* to_up()
	{
		return vals;
	}

	// last row
	double* to_down()
	{
		return vals + rows * cols - cols;
	}

	int rows, cols;
	double *vals;

	Grid(const Grid &m) = delete;
	Grid(const Grid &&m) = delete;
	Grid& operator=(const Grid &m) = delete;
	Grid& operator=(const Grid &&m) = delete;
};


int main(int argc, char *argv[])
{
	int length = 10, iterations = 10;
	if (argc > 1) {
		std::istringstream( argv[1] ) >> length;
	}
	if (argc > 2) {
		std::istringstream( argv[2] ) >> iterations;
	}

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	Grid prev(length, length), next(length, length);
	std::vector<double> halo_up(length), halo_down(length);

	MPI_Request req[4];

	double start = MPI_Wtime();
	for (int i = 0; i < iterations; ++i) {
		// compute next values

		MPI_Isend(prev.to_down()  , prev.cols, MPI_DOUBLE, rank + 1, FROM_UP_TO_DOWN, MPI_COMM_WORLD,&req[0]);
		MPI_Irecv(halo_down.data(), prev.cols, MPI_DOUBLE, rank + 1, FROM_DOWN_TO_UP, MPI_COMM_WORLD, &req[1]);
		MPI_Isend(prev.to_up()    , prev.cols, MPI_DOUBLE, rank - 1, FROM_DOWN_TO_UP, MPI_COMM_WORLD, &req[2]);
		MPI_Irecv(halo_up.data()  , prev.cols, MPI_DOUBLE, rank - 1, FROM_UP_TO_DOWN, MPI_COMM_WORLD, &req[3]);

		MPI_Waitall(4, req, MPI_STATUSES_IGNORE);

		for (int i = 0; i < length; ++i) {
			prev.to_down()[i] = halo_down[i];
			prev.to_up()[i] = halo_up[i];
		}
	}
	double end = MPI_Wtime();

	if (rank == 0) {
		printf("length: %d, iterations: %d, total duration: %fs, iteration duration: %fs\n", length, iterations, end - start, (end - start) / iterations);
	}

	MPI_Finalize();
}
