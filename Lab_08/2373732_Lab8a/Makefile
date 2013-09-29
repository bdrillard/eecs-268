OBJS = main.o PrecondViolatedExcep.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o: LinkedList.h LinkedList.cpp ListInterface.h main.cpp Node.cpp Node.h PrecondViolatedExcep.h
	g++ -c -g main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -c -g PrecondViolatedExcep.cpp
clean:
	rm -f *.o *~
