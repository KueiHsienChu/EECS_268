Prog: Test.o main.o PreconditionViolationException.o
	g++ -g -Wall -std=c++11 main.o Test.o PreconditionViolationException.o -o Prog
Test.o: Test.h Test.cpp Stack.h Stack.hpp Node.h Node.hpp StackInterface.h PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11 -c Test.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11 -c PreconditionViolationException.cpp
main.o: main.cpp Stack.h Stack.hpp Node.h Node.hpp StackInterface.h 
	g++ -g -Wall -std=c++11 -c main.cpp
clean:
	rm *.o Prog 
