Program: main.o Node.o LinkedList.o Test.o
	g++ -g -Wall -std=c++11 main.o Node.o Test.o LinkedList.o -o Program

main.o: main.cpp Node.h LinkedList.h Test.h
	g++ -g -Wall -std=c++11 -c main.cpp

Node.o: Node.h Node.cpp
	g++ -g -Wall -std=c++11 -c Node.cpp

Test.o: Test.h Test.cpp LinkedList.h
	g++ -g -Wall -std=c++11 -c Test.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -Wall -std=c++11 -c LinkedList.cpp
 
