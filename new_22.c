#include <stdio.h>
#include <math.h>

int input (double coefficient [3]);
int show_equation(double coefficient [3]);
int solver(double coefficient [3], double discriminant, double answer [2]);
int formula (double * x_1, double * x_2, double coefficient[3], double discriminant);
int formula_linear (double *x, double coefficient[3]);
int show_answers (double coefficient[3], double answer[2], double discriminant);
double formula_discriminant(double coefficient[3]);


double const epsilon = 1e-11;

int main(void) {
    double coefficient[3] = {0,0,0};
    double answer[2] = {0,0};
    double discriminant = 0;

    while (input(coefficient) == 3)
    {
    show_equation(coefficient);
    discriminant = formula_discriminant(coefficient);
    solver (coefficient, discriminant, answer);
    show_answers(coefficient, answer, discriminant);
    }
    return 0;
}

int input(double coefficient [3])
{
    printf("Enter the coefficients of the quadratic equation (or 'q' to completion):\n");
    return scanf("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}

int show_equation(double coefficient [3])
{
    printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
}

double formula_discriminant(double coefficient[3])
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}

int solver(double coefficient [3], double discriminant, double answer [2])
{
    if (coefficient[0] != 0 && discriminant >= 0)
    {
        formula (&answer[0], &answer[1], coefficient, discriminant);

    } else if (coefficient[0] == 0)
    {
        formula_linear (&answer[0], coefficient);
    } 
}

int formula (double * x_1, double * x_2, double coefficient[3], double discriminant)
{
    *x_1 = (double) ( -1 * coefficient[1] + sqrt(discriminant) ) / ( 2 * coefficient[0] );
    *x_2 = (double) ( -1 * coefficient[1] - sqrt(discriminant) ) / ( 2 * coefficient[0] );
}

int formula_linear (double *x, double coefficient[3])
{
    *x = (double) -1 * coefficient[2] / coefficient[1];
}

int show_answers(double coefficient[3], double answer[2], double discriminant)
{
      if (coefficient[0] != 0 && discriminant >= epsilon)
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg\n", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && discriminant < epsilon && discriminant >= 0) 
    {
        printf ("solutions to the equation: solution = %lg\n", answer[0]);

    } else 
    {
        printf ("Error! No valid values\n");

    }
}