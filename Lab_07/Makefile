main: main.o Manager.o
	g++ -g -o main main.o Manager.o
main.o: main.cpp Manager.h
	g++ -c -g main.cpp
Manager.o: Manager.h Manager.cpp ArrayStack.h
	g++ -c -g Manager.cpp
clean:
	rm -f *.o *~ 
