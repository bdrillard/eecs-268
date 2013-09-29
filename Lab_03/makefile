all: plotter
plotter: main.o Manager.o Point2DArray.o
	g++ -g main.o Manager.o Point2DArray.o -o plotter
main.o: Manager.h main.cpp
	g++ -g -c main.cpp
Manager.o: Manager.h Manager.cpp Point2DArray.h Point2DArray.cpp
	g++ -g -c Manager.cpp
Point2DArray.o: Point2DArray.h Point2DArray.cpp
	g++ -g -c Point2DArray.cpp
clean:
	rm *.o
