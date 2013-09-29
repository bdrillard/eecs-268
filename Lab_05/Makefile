main: main.o
	g++ -g -o main main.o
main.o: BagInterface.h ArrayBag.h ArrayBag.cpp main.cpp
	g++ -g -c main.cpp
clean:
	rm *.o main
