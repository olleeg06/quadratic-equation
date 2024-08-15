#include <stdio.h>
#include <math.h>

int solve (double coefficient[3], double answer[6], double discriminant);
int input (double coefficient [3]);
int formula (double * x_1, double * x_2, double coefficient[3], double discriminant);
int formula_complex (double * x_real, double * x_imaginary, double coefficient[3], double discriminant);
int formula_small (double * x, double coefficient[3]);
int formula_linear (double *x, double coefficient[3]);
int discriminant_epsilon_plus (double discriminant, double epsilon);
int discriminant_epsilon_minus (double discriminant, double epsilon);
int show_answer(double coefficient[3], double answer[6], double discriminant);
double formula_discriminant (double coefficient[3]);

double const epsilon = 1e-11;

int main(void)
{   
    double coefficient [3];
    double answer [6];
    double discriminant = 0;
    
    printf("Enter the coefficients of the quadratic equation (or 'q' to completion):\n");

    while (input(coefficient) == 3)
    {
        discriminant = formula_discriminant(coefficient);
        printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
        solve (coefficient, answer, discriminant);
        show_answer (coefficient, answer, discriminant);
        printf("\nEnter the coefficients of the quadratic equation (or 'q' to completion):\n");
    }
    printf("\nHave a good day!");
 return 0;
}

double formula_discriminant(double coefficient[3])
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}

int solve(double coefficient[3], double answer[6], double discriminant)
{

      if (coefficient[0] != 0 && discriminant_epsilon_plus (discriminant, epsilon))
    {
        formula (&answer[0], &answer[1], coefficient, discriminant);

    } else if (coefficient[0] != 0 && discriminant_epsilon_minus (discriminant, epsilon))
    {
        formula_complex (&answer[2], &answer[3], coefficient, discriminant);

    } else if (coefficient[0] != 0 && !(discriminant_epsilon_plus (discriminant, epsilon)) && !(discriminant_epsilon_minus (discriminant, epsilon))) 
    {
        formula_small (&answer[4], coefficient);

    } else 
    {
        formula_linear (&answer[5], coefficient);
    }
    }

int input(double coefficient [3])
{
    return scanf("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}

int formula (double * x_1, double * x_2, double coefficient[3], double discriminant)
{
    *x_1 = (double) ( -1 * coefficient[1] + sqrt(discriminant) ) / ( 2 * coefficient[0] );
    *x_2 = (double) ( -1 * coefficient[1] - sqrt(discriminant) ) / ( 2 * coefficient[0] );
}

int formula_complex (double * x_real, double * x_imaginary, double coefficient[3], double discriminant)
{
    *x_real =  (double) -1 * coefficient[1] / ( 2 * coefficient[0] );
    *x_imaginary = (double) sqrt( -1 * discriminant ) / ( 2 * coefficient[0] );
}

int formula_small (double * x, double coefficient[3])
{
    *x = (double) -1 * coefficient[1] / ( 2 * coefficient[0] );
}

int formula_linear (double *x, double coefficient[3])
{
    *x = (double) -1 * coefficient[2] / coefficient[1];
}

int discriminant_epsilon_plus (double discriminant, double epsilon)
{
    if (discriminant >= epsilon)
    return 1;
    else 
    return 0;
}

int discriminant_epsilon_minus (double discriminant, double epsilon)
{
    if (discriminant <= -1 * epsilon)
    return 1;
    else 
    return 0;
}

int show_answer(double coefficient[3], double answer[6], double discriminant)
{
    if (coefficient[0] != 0 && discriminant_epsilon_plus (discriminant, epsilon))
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && discriminant_epsilon_minus (discriminant, epsilon))
    {
        printf ("solutions to the equation: solution_1 = %lg + %lg * i, solution_2 = %lg - %lg * i",
        answer[2], answer[3], answer[2], answer[3]);

    } else if (coefficient[0] != 0 && !(discriminant_epsilon_plus (discriminant, epsilon)) && !(discriminant_epsilon_minus (discriminant, epsilon))) 
    {
        printf ("solutions to the equation: solution_1 = solution_2 = %lg", answer[4]);

    } else 
    {
        printf ("solution to the equation: solution = %lg", answer[5]);

    }
}