Prog: Test.o main.o
	g++ -g -Wall -std=c++11 main.o Test.o -o Prog
Test.o: Test.h Test.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -Wall -std=c++11 -c Test.cpp
main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o Prog 
