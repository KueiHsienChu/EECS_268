Lab01: Dice.o Pokemon.o Colosseum.o main.o
	g++ -g -Wall -o Lab01 Colosseum.o Dice.o Pokemon.o main.o

Dice.o: Dice.cpp Dice.h
	g++ -c -Wall -g Dice.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -c -Wall -g Pokemon.cpp

Colosseum.o: Colosseum.cpp Colosseum.h Dice.h Pokemon.h
	g++ -c -Wall -g Colosseum.cpp

main.o: main.cpp Colosseum.h Pokemon.h
	g++ -c -Wall -g main.cpp 

clean:
	rm Lab01 *.o

