Prog: main.o MazeCreationException.o MazeReader.o MazeWalker.o Position.o Test.o
	g++ -g -Wall -std=c++11 main.o MazeCreationException.o MazeReader.o MazeWalker.o Position.o Test.o
	
main.o: main.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -g -Wall -std=c++11 -c main.cpp
	
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -Wall -std=c++11 -c MazeCreationException.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -Wall -std=c++11 -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -Wall -std=c++11 -c MazeWalker.cpp
	
Position.o: Position.h Position.cpp
	g++ -g -Wall -std=c++11 -c Position.cpp
	
Test.o: Test.h Test.cpp ArrayHelper.h Arrayhelper.hpp
	g++ -g -Wall -std=c++11 -c Test.cpp
	
clean:
	rm *.o Prog
