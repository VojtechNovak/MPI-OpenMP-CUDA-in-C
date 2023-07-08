main: main.o heated_plate.o
	g++ -g main.o -lgomp heated_plate.o -o main
main.o: main.cpp heated_plate.h
	g++ -g -c -lgomp main.cpp
heated_plate.o: heated_plate.cpp heated_plate.h
	g++ -g -c -lgomp heated_plate.cpp
