#include <ctype.h>
#include <string.h>
#include <math.h>
#include "solution.hpp"
#include <cstdio>
#include "check.hpp"


int formula_square (double *answer, double *coefficient, double discriminant); 
int formula_linear (double *x, double *coefficient); 




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






int solver_square (double *coefficient, double discriminant, double *answer)
{
    if (coefficient[0] != 0 && discriminant >= 0)
    {
        formula_square (answer, coefficient, discriminant);

    } else if (coefficient[0] == 0)
    {
        formula_linear (&answer[0], coefficient);
    } 
    return 0;
}


int compare_epsilon(double argument)
{
    double const epsilon = 1e-4;
    if (fabs(argument) <= epsilon)
        return 1;
    else 
        return 0;
}

int show_equation (double *coefficient)
{                              
    printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
    return 0;
}      

double count_discriminant (double *coefficient) 
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}


int formula_square (double *answer, double *coefficient, double discriminant)
{
    double x_11 = 0, x_22 = 0;
    x_11 = (double) (-coefficient[1] + sqrt(discriminant) ) / ( 2 * coefficient[0] );
    x_22 = (double) (-coefficient[1] - sqrt(discriminant) ) / ( 2 * coefficient[0] );
    if (x_11 > x_22)
    {
        answer[0] = x_11;
        answer[1] = x_22;
    } else 
    {
        answer[0] = x_22;
        answer[1] = x_11;
    }
    return 0;
}

int formula_linear (double *x, double *coefficient)
{
    *x = (double) -coefficient[2] / coefficient[1];
    return 0;
}

int show_answers (double *coefficient, double *answer, double discriminant)
{
      if (coefficient[0] != 0 && !(compare_epsilon(discriminant)) && (discriminant >= 0))
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg\n", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && compare_epsilon(discriminant) && (discriminant >= 0) || coefficient[0] == 0 && coefficient[1] != 0) 
    {
        printf ("solutions to the equation: solution = %lg\n", answer[0]);

    } else if (coefficient[0] == 0 && coefficient[1] == 0 && coefficient[2] == 0){
        printf ("solutions to the equation: infinite number of roots\n");
    } else {
        printf ("Error! No valid values\n");

    }
    return 0;
}