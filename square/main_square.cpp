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
    const char *function[] = {"help", "test", "solution", "file"}; // чёто поменять 
  
  calculate keys = {0,0,0,0,0};

    reading_functions(argc, argv, function, &keys);
    
     if (keys.function_1 > 0){
        printf ("-help\n-test\n-solution\n-file @name\n");
    } 

    if (keys.function_2 > 0){
        check_program(answer);
    }

    if (keys.function_3 > 0){
        execute_program(coefficient, answer);
    }

    if (keys.function_4 > 0){
        reading_file(coefficient, answer, keys);
    }

    if (keys.function_1 == 0 && keys.function_2 == 0 && keys.function_3 == 0 && keys.function_4 == 0){
       printf ("Error!\n-help\n-test\n-solution\n-file @name\n"); 
    }

    return 0;
}