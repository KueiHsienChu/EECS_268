Prog: Test.o main.o
	g++ -g -Wall -std=c++11 main.o Test.o Prog
Test.o: Test.h Test.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 Test.cpp
main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 main.cpp

clean:
	*.o Prog
