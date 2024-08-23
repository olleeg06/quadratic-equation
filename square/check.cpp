#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include "check.hpp"
#include "solution.hpp"
#include "color.hpp"



int check_program (struct equations *key, double *answer)
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
    printf("Test passed %d equations out of %d", correct, total_tests);
        return 0;
    }