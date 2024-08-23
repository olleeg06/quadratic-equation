all : main_square.o choice.o check.o execute.o solution.o
	g++ main_square.o choice.o check.o execute.o solution.o -o result

main_square.o : main_square.cpp
	g++ -c main_square.cpp

choice.o : choice.cpp choice.hpp
	g++ -c choice.cpp

check.o : check.cpp check.hpp color.hpp
	g++ -c check.cpp

execute.o : execute.cpp execute.hpp
	g++ -c execute.cpp

solution.o : solution.cpp solution.hpp
	g++ -c solution.cpp

clean:
	del main_square.o choice.o check.o execute.o solution.o result.exe