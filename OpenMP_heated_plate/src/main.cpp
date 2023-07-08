#include "heated_plate.h"
#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[])
{
auto begin = std::chrono::high_resolution_clock::now();

	int M = 128;
	int N = 512;
	double epsilon = 0.01;
	const char* output_filename = "output.txt";

	//Check args
	if (argc < 2) {
		printf("USAGE:\theatedplate 0 (tiny)\n\theatedplate 1 (small)\n\theatedplate 2 (large)\n");
		return 0;
	}

	// Read Input
	int type = atoi(argv[1]);
	//tiny
	if (type == 0) {
		M = 128;
		N = 512;
		epsilon = 0.01;
	}
	//small
	if (type == 1) {
		M = 256;
		N = 1024;
		epsilon = 0.001;
	}    
	//large
	if (type == 2) {
		M = 1024;
		N = 2048;
		epsilon = 0.001;
	}

	solve(M, N, epsilon, output_filename);
auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    printf("Total run time: %.3f seconds.\n", elapsed.count() * 1e-9);
	return 0;
}