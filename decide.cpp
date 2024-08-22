#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include "decide.hpp"

#define COLOR_GREEN        "\x1b[32m"
#define RESET_ALL          "\x1b[0m"
#define COLOR_RED          "\x1b[31m"


int compare_epsilon(double argument);
int input_coefficient (double coefficient[number_coefficient]);
int show_equation (double coefficient[number_coefficient]); 
int solver_square (double coefficient[number_coefficient], double discriminant, double answer[number_answer]); 
int formula_square (double *answer, double *coefficient, double discriminant); 
int formula_linear (double *x, double coefficient[number_coefficient]); 
int show_answers (double coefficient[number_coefficient], double answer[number_answer], double discriminant); 
double count_discriminant (double coefficient[number_coefficient]); 





int input_selection()
{
    int check = -1;
    printf("Do you want to check the program before executing it? (if yes to '1', if no to '0')\n");
    scanf("%d", &check);
    return check;
    
}

int execute_program (double coefficient[number_coefficient], double answer[2]) 
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



int check_program (struct equations key[total_tests], double answer[number_answer])
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

int compare_epsilon(double argument)
{
    double const epsilon = 1e-4;
    if (fabs(argument) <= epsilon)
        return 1;
    else 
        return 0;
}



int input_coefficient (double coefficient[number_coefficient])
{
    printf ("Enter the coefficients of the quadratic equation:\n");
    return scanf ("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}

int show_equation (double coefficient[number_coefficient])
{                              
    printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
    return 0;
}      

double count_discriminant (double coefficient[number_coefficient]) 
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}

int solver_square (double coefficient[number_coefficient], double discriminant, double answer[number_answer])
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

int formula_linear (double *x, double coefficient[number_coefficient])
{
    *x = (double) -coefficient[2] / coefficient[1];
    return 0;
}

int show_answers (double coefficient[number_coefficient], double answer[number_answer], double discriminant)
{
      if (coefficient[0] != 0 && !(compare_epsilon(discriminant)) && (discriminant >= 0))
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg\n", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && compare_epsilon(discriminant) && (discriminant >= 0)) 
    {
        printf ("solutions to the equation: solution = %lg\n", answer[0]);

    } else 
    {
        printf ("Error! No valid values\n");

    }
    return 0;
}