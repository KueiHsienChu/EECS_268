Prog: main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o
	g++ -g -Wall -std=c++11 main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o  -o Prog
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -Wall -std=c++11 -c PreconditionViolationException.cpp
main.o: main.cpp Stack.h Stack.hpp Node.h Node.hpp StackInterface.h AnimalPen.h FarmAnimal.h
	g++ -g -Wall -std=c++11 -c main.cpp
AnimalPen.o: AnimalPen.h AnimalPen.cpp FarmAnimal.h Cow.h Chicken.h CyberChicken.h
	g++ -g -Wall -std=c++11 -c AnimalPen.cpp
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -Wall -std=c++11 -c FarmAnimal.cpp
Cow.o: Cow.h Cow.cpp FarmAnimal.h
	g++ -g -Wall -std=c++11 -c Cow.cpp
Chicken.o: Chicken.h Chicken.cpp
	g++ -g -Wall -std=c++11 -c Chicken.cpp
CyberChicken.o: CyberChicken.h CyberChicken.cpp
	g++ -g -Wall -std=c++11 -c CyberChicken.cpp
clean:
	rm *.o Prog
