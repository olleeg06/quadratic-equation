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


    const int number_functions = 4;


int reading_functions(int argc, char *argv[], const char *function[], int count[number_functions]);

int reading_file(double *coefficient, double *answer);


int read_command_line(int argc, char *argv[])
{
    double coefficient[number_coefficient] = {};
    double answer[number_answer] = {};
    const char *function[] = {"help", "test", "solution", "file"};

    int count[number_functions] = {};

    reading_functions(argc, argv, function, count);
    
    
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



int reading_functions(int argc, char *argv[], const char *function[], int count[number_functions])
    {

    for(int j = 1; j < argc; j++){

     if (strcmp(argv[j], function[0] ) == 0){
        count[0]++;

    } else if (strcmp(argv[j], function[1] ) == 0){
        count[1]++;

    } else if (strcmp(argv[j], function[2] ) == 0){
        count[2]++;

    } else if (strcmp(argv[j], function[3]) == 0){
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
    if (file == NULL) {
        printf("Error opening file");
    } else {
    for (int i = 1;fscanf(file, "%lf%lf%lf", 
           &coefficient[0], &coefficient[1], &coefficient[2]) != EOF; i++) {
 
        double discriminant = count_discriminant (coefficient);   
        solver_square (coefficient, discriminant, answer);
        printf("Equation number %d:\n", i);
        show_answers(coefficient, answer, discriminant);}
}
return 0;
}