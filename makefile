all : main_square.o decide.o
	g++ main_square.o decide.o -o result

main_square.o : main_square.cpp
	g++ -c main_square.cpp

decide.o : decide.cpp decide.hpp
	g++ -c decide.cpp

clean:
	del main_square.o decide.o