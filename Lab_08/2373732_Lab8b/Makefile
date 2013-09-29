main: main.o Manager.o PrecondViolatedExcep.o
	g++ -g -o main main.o Manager.o PrecondViolatedExcep.o
main.o: main.cpp Manager.h
	g++ -g -c main.cpp
Manager.o: Manager.h Manager.cpp LinkedStack.h LinkedList.h
	g++ -g -c Manager.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -g -c PrecondViolatedExcep.cpp
clean:
	rm -rf *.o *~
