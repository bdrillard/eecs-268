all: bag

bag: main.o Manager.o
	g++ -g -std=c++11 main.o Manager.o -o bag

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

manager.o: Manager.cpp
	g++ -c -g -std=c++11 Manager.cpp

clean:
	rm bag *.o 
