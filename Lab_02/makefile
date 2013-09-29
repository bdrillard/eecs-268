all: translator
translator: main.o Translator.o
	g++ -g main.o Translator.o -o translator
main.o: Translator.h main.cpp
	g++ -g -c main.cpp
Translator.o: Translator.cpp Translator.h TranslationTable.h KeyValuePair.h
	g++ -g -c Translator.cpp
clean:
	rm *.o 
