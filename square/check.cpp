#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include "check.hpp"
#include "solution.hpp"
#include "color.hpp"
#include "Command_line.hpp"

equations key[total_tests] =
    {
        {{      1,        2,     -8}, {       2,        -4}},
        {{     -5,       10,     40}, {       4,        -2}},
        {{      4,        7,    -15}, {    1.25,        -3}},
        {{ 48.755, -100.343,      5}, { 2.00701, 0.0510977}},
        {{-0.1543,    5.134, -1.851}, {32.90831,  0.364531}}
    };


int check_program ( double *answer)
{   

    int correct = 0;

    for (int i = 0; i < total_tests; i++){ 

        double discriminant = count_discriminant (key[i].coefficient);   
        solver_square (key[i].coefficient, discriminant, answer);

        double option_1 = fabs(key[i].answer_supposed[0] - answer[0]);
        double option_2 = fabs(key[i].answer_supposed[1] - answer[1]);

        if (compare_epsilon (option_1) && compare_epsilon (option_2) )
        {
            printf(COLOR_GREEN "Test %d is OK\n" RESET_ALL, i+1);
            correct++;
        } else 
        {
            printf(COLOR_RED "Test %d is Error\n The answers you should get are: solution_1 = %lg, solution_2 = %lg\n"
                             "The answers you got: solution_1 = %lg, solution_2 = %lg\n" RESET_ALL,
                             i+1, key[i].answer_supposed[0], key[i].answer_supposed[1], answer[0], answer[1]);
        }
        
    }
    printf("Test passed %d equations out of %d\n", correct, total_tests);
        return 0;
    }