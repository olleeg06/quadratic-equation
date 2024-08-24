#include <ctype.h>
#include <string.h>
#include <math.h>
#include "Command_line.hpp"
#include "check.hpp"
#include "execute.hpp"
#include "solution.hpp"
#include <cstdio>
#include <string.h>


equations key[total_tests] =
    {
        {{      1,        2,     -8}, {       2,        -4}},
        {{     -5,       10,     40}, {       4,        -2}},
        {{      4,        7,    -15}, {    1.25,        -3}},
        {{ 48.755, -100.343,      5}, { 2.00701, 0.0510977}},
        {{-0.1543,    5.134, -1.851}, {32.90831,  0.364531}}
    };


    const int functions = 4;


int reading_functions(int argc, char *argv[], const char function_1[], const char function_2[], const char function_3[],
                      const char function_4[], int count[functions]);

int reading_file(double *coefficient, double *answer);


int Command_line(int argc, char *argv[])
{
    double coefficient[number_coefficient] = {};
    double answer[number_answer] = {};
    const char function_1[] = "help";
    const char function_2[] = "test";
    const char function_3[] = "solution";
    const char function_4[] = "file";

    int count[functions] = {};

    reading_functions(argc, argv, function_1, function_2, function_3, function_4, count);
    
    
    if (count[0] > 0){
        printf ("-help\n-test\n-solution\n");
    } 

    if (count[1] > 0){
        check_program(key, answer);
    }

    if (count[2] > 0){
        execute_program(coefficient, answer);
    }

    if (count[3] > 0){
        reading_file(coefficient, answer);
    }

    if (count[0] == 0 && count[1] == 0 && count[2] == 0 && count[3] == 0){
       printf ("Error!\n-help\n-test\n-solution\n-file\n"); 
    }

    return 0;
}


int reading_functions(int argc, char *argv[], const char function_1[], const char function_2[], const char function_3[],
                      const char function_4[], int count[functions])
    {

    for(int j = 1; j < argc; j++){

     if (strcmp(argv[j], function_1 ) == 0){
        count[0]++;

    } else if (strcmp(argv[j], function_2 ) == 0){
        count[1]++;

    } else if (strcmp(argv[j], function_3 ) == 0){
        count[2]++;

    } else if (strcmp(argv[j], function_4) == 0){
        count[3]++;
    }
    }

return 0;

}


int reading_file(double *coefficient, double *answer) {
    FILE *file;
    struct coefficientss{
        double coefficient[number_coefficient];
    };

    file = fopen("coefficients_square.txt", "r");
    int i = 1;
    while (fscanf(file, "%lf%lf%lf", 
           &coefficient[0], &coefficient[1], &coefficient[2]) != EOF) {
 
        double discriminant = count_discriminant (coefficient);   
        solver_square (coefficient, discriminant, answer);
        printf("Equation number %d:\n", i);
        show_answers(coefficient, answer, discriminant);
        i++;
}
return 0;
}