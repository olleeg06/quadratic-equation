#include <ctype.h>
#include <string.h>
#include <math.h>
#include "execute.hpp"
#include <cstdio>
#include "solution.hpp"
#include "check.hpp"


int input_coefficient (double *coefficient);

int execute_program (double *coefficient, double *answer) 
    {
    if (input_coefficient(coefficient) == number_coefficient)
    {
    show_equation(coefficient);
    double discriminant = count_discriminant (coefficient);   
    solver_square (coefficient, discriminant, answer);
    show_answers(coefficient, answer, discriminant);
    } else {
        printf("Error! You did not enter numbers. Restart the program.");
    }
    return 0;
}

int input_coefficient (double *coefficient)
{
    printf ("Enter the coefficients of the quadratic equation:\n");
    return scanf ("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}
