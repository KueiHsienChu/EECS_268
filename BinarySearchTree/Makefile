Prog: Test.o main.o
	g++ -g -Wall -std=c++11 main.o Test.o -o Prog
Test.o: Test.h Test.cpp Node.h Node.hpp BSTI.h BinarySearchTree.h BinarySearchTree.hpp 
	g++ -g -Wall -std=c++11 -c Test.cpp
main.o: main.cpp Node.h Node.hpp BinarySearchTree.h BinarySearchTree.hpp BSTI.h
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o Prog 
