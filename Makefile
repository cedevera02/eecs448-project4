prog: main.o Account.o Executive.o Restaurant.o UI.o
	g++ -std=c++11 -g -Wall main.o Account.o Executive.o Restaurant.o UI.o

main.o: main.cpp Account.h Executive.h Restaurant.h UI.h
	g++ -std=c++11 -g -Wall -c main.cpp

Account.o: Account.h Account.cpp
	g++ -std=c++11 -g -Wall -c Account.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Restaurant.o: Restaurant.h Restaurant.cpp
	g++ -std=c++11 -g -Wall -c Restaurant.cpp

UI.o: UI.h UI.cpp
	g++ -std=c++11 -g -Wall -c UI.cpp

clean:
	rm *.o prog