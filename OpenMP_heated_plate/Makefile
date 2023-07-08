main: main.o heated_plate.o
	icc -DNOALIAS -O3  -qopenmp -g -lgomp main.o heated_plate.o -o main
main.o: src/main.cpp src/heated_plate.h
	icc -DNOALIAS -O3 -qopenmp -g -lgomp -c src/main.cpp
heated_plate.o: src/heated_plate.cpp src/heated_plate.h
	icc -DNOALIAS -O3 -qopenmp -g -lgomp -c src/heated_plate.cpp
