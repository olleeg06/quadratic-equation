#include <ctype.h>
#include <string.h>
#include <math.h>
#include "Command_line.hpp"
#include "check.hpp"
#include "solution.hpp"
#include <cstdio>





int main(int argc, char *argv[]) {

    double coefficient[number_coefficient] = {};
    double answer[number_answer] = {};
    const char *function[] = {"help", "test", "solution", "file"};
    char *file_name[] = {};

    int calculate[number_functions] = {};

    reading_functions(argc, argv, function, calculate, file_name);
    
     if (calculate[0] > 0){
        printf ("-help\n-test\n-solution\n-file @name\n");
    } 

    if (calculate[1] > 0){
        check_program(answer);
    }

    if (calculate[2] > 0){
        execute_program(coefficient, answer);
    }

    if (calculate[3] > 0){
        reading_file(coefficient, answer, file_name);
    }

    if (calculate[0] == 0 && calculate[1] == 0 && calculate[2] == 0 && calculate[3] == 0){
       printf ("Error!\n-help\n-test\n-solution\n-file @name\n"); 
    }

    return 0;
}