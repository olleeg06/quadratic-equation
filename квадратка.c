#include <stdio.h>
#include <math.h>

int solve (double coefficient[3]);
int input (double coefficient [3]);
int formula (double * x_1, double * x_2, double coefficient[3], double discriminant);
int formula_complex (double * x_real, double * x_imaginary, double coefficient[3], double discriminant);
int formula_small (double * x, double coefficient[3]);
int formula_linear (double *x, double coefficient[3]);
int discriminant_epsilon_plus (double discriminant, double epsilon);
int discriminant_epsilon_minus (double discriminant, double epsilon);

double const epsilon = 1e-11;

int main(void)
{   
    printf("Enter the coefficients of the quadratic equation (or 'q' to completion):\n");
    double coefficient [3];

    while (input(coefficient) == 3)
    {
        printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
        solve(coefficient);
        printf("\nEnter the coefficients of the quadratic equation (or 'q' to completion):\n");
    }
    printf("\nHave a good day!");
 return 0;
}

int solve(double coefficient[3])
{
        double discriminant = 0;
        discriminant = coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];

      if (coefficient[0] != 0 && discriminant_epsilon_plus (discriminant, epsilon))
    {
        double solution_1, solution_2;
        formula (&solution_1, &solution_2, coefficient, discriminant);
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg", solution_1, solution_2);

    } else if (coefficient[0] != 0 && discriminant_epsilon_minus (discriminant, epsilon))
    {
        double solution_real, solution_imaginary;
        formula_complex (&solution_real, &solution_imaginary, coefficient, discriminant);
        printf ("solutions to the equation: solution_1 = %lg + %lg * i, solution_2 = %lg - %lg * i",
        solution_real, solution_imaginary,solution_real, solution_imaginary);

    } else if (coefficient[0] != 0 && !(discriminant_epsilon_plus (discriminant, epsilon)) && !(discriminant_epsilon_minus (discriminant, epsilon))) 
    {
        double solution_small;
        formula_small (&solution_small, coefficient);
        printf ("solutions to the equation: solution_1 = solution_2 = %lg", solution_small);

    } else 
    {
        double solution;
        formula_linear (&solution, coefficient);
        printf ("solution to the equation: solution = %lg", solution);

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
