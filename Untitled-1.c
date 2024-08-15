#include <stdio.h>
#include <math.h>
int formula_good(double * x_1, double * x_2, double coefficient_a, double coefficient_b, double discriminant);
int formula_complex(double * x_real, double * x_imaginary, double coefficient_a, double coefficient_b, double discriminant);
int formula_bad(double * x, double coefficient_a, double coefficient_b);
int formula_linear(double *x, double coefficient_b, double coefficient_c);

int main(void)
{   
    double const epsilon = 0.00000000001;
    double coefficient_a, coefficient_b, coefficient_c, discriminant;  
    printf("Enter the coefficients of the quadratic equation:\n");
    scanf("%lg %lg %lg", &coefficient_a, &coefficient_b, &coefficient_c);
    printf(" %lg * x^2 + %lg * x + %lg = 0 \n", coefficient_a ,coefficient_b ,coefficient_c);

    discriminant = coefficient_b * coefficient_b - 4 * coefficient_a * coefficient_c;


    if (coefficient_a != 0 && ( discriminant >= epsilon ))
    {
        double solution_1, solution_2;
        formula_good( &solution_1, &solution_2, coefficient_a, coefficient_b, discriminant );
        printf("solutions to the equation: solution_1 = %lg, solution_2 = %lg", solution_1, solution_2);
    }


    else if ( coefficient_a != 0 && ( discriminant <= ( -1 * epsilon ) ))
    {
        double solution_real, solution_imaginary;
        formula_complex( &solution_real, &solution_imaginary, coefficient_a, coefficient_b, discriminant );
        printf("solutions to the equation: solution_1 = %lg + %lg * i, solution_2 = %lg - %lg * i",
        solution_real, solution_imaginary,solution_real, solution_imaginary);
    }


    else if ( coefficient_a != 0 && ( discriminant > ( -1 * epsilon ) ) && ( discriminant < epsilon )) 
    {
        double solution_bad;
        formula_bad(&solution_bad, coefficient_a, coefficient_b );
        printf("solutions to the equation: solution_1 = solution_2 = %lg", solution_bad);
    }
        

    else 
    {
        double solution;
        formula_linear(&solution, coefficient_b, coefficient_c );
        printf("solution to the equation: solution = %lg", solution );
    }
 return 0;
}

int formula_good(double * x_1, double * x_2, double coefficient_a, double coefficient_b, double discriminant)
{
    *x_1 = (double) ( -1 * coefficient_b + sqrt(discriminant) ) / ( 2 * coefficient_a );
    *x_2 = (double) ( -1 * coefficient_b - sqrt(discriminant) ) / ( 2 * coefficient_a );
}

int formula_complex(double * x_real, double * x_imaginary, double coefficient_a, double coefficient_b, double discriminant)
{
    *x_real =  (double) -1 * coefficient_b / ( 2 * coefficient_a );
    *x_imaginary = (double) sqrt( -1 * discriminant ) / ( 2 * coefficient_a );
}

int formula_bad(double * x, double coefficient_a, double coefficient_b)
{
    *x = (double) -1 * coefficient_b / ( 2 * coefficient_a );
}

int formula_linear(double *x, double coefficient_b, double coefficient_c)
{
    *x = (double) -1 * coefficient_c / coefficient_b;
}