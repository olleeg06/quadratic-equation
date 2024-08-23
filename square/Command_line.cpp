#include <ctype.h>
#include <string.h>
#include <math.h>
#include "Command_line.hpp"
#include "execute.hpp"
#include "check.hpp"
#include "solution.hpp"
#include <cstdio>
#include <string.h>



    const int functions = 3;

int Command_line(int argc, char *argv[])
{
    double coefficient[number_coefficient] = {};
    double answer[number_answer] = {};
    const char function_1[] = "help";
    const char function_2[] = "test";
    const char function_3[] = "solution";

    int count[functions] = {};

    for(int j = 1; j < argc; j++){

     if (strcmp(argv[j], function_1 ) == 0){
        count[0]++;

    } else if (strcmp(argv[j], function_2 ) == 0){
        count[1]++;

    } else if (strcmp(argv[j], function_3 ) == 0){
        count[2]++;
    }
    }

    
    if (count[0] > 0){
        printf ("-help\n-test\n-solution\n");
    } 

    if (count[1] > 0){
        check_program(key, answer);
    }

    if (count[2] > 0){
        execute_program(coefficient, answer);
    }

    if (count[0] == 0 && count[1] == 0 && count[2] == 0 ){
       printf ("Error!\n-help\n-test\n-solution\n"); 
    }

    return 0;
}