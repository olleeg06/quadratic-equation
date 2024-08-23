all : main_square.o Command_line.o check.o solution.o
	g++ main_square.o Command_line.o check.o solution.o -o result

main_square.o : main_square.cpp
	g++ -c main_square.cpp

Command_line.o : Command_line.cpp Command_line.hpp
	g++ -c Command_line.cpp

check.o : check.cpp check.hpp color.hpp
	g++ -c check.cpp

solution.o : solution.cpp solution.hpp
	g++ -c solution.cpp

clean:
	del main_square.o Command_line.o check.o solution.o result.exe