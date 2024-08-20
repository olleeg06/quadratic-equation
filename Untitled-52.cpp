#include <stdio.h>
#include <math.h>

int check_program(double coefficient[3], double answer[2]);
int execute_program(double coefficient[3], double answer[2]);
int input_coefficient (double coefficient[3]);
int show_equation (double coefficient[3]); 
int solver_square (double coefficient [3], double discriminant, double answer[2]); 
int formula_square (double * x_1, double * x_2, double coefficient[3], double discriminant); 
int formula_linear (double *x, double coefficient[3]); 
int show_answers (double coefficient[3], double answer[2], double discriminant); 
double count_discriminant (double coefficient[3]); 


double const epsilon = 1e-11;


int main(void) {
    double coefficient[3] = {0,0,0};
    double answer[2] = {0,0};

    printf("Do you want to check the program before executing it? (if yes to '+', if no to '-')\n");
    char check;
    scanf("%c", &check);
    
    switch (check)
    {
        case '+' : check_program(coefficient, answer);
        break;

        case '-':  execute_program(coefficient, answer);
        break;
        default: printf("Error! Restart the program.");
    }
}

int execute_program (double coefficient[3], double answer[2])
{
    if (input_coefficient(coefficient) == 3)
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

int input_coefficient (double coefficient[3])


{
    printf ("Enter the coefficients of the quadratic equation:\n");
    return scanf ("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}

int show_equation (double coefficient[3])
{                              
    printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
    return 0;
}                                                       
double count_discriminant (double coefficient[3]) 
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}

int solver_square (double coefficient[3], double discriminant, double answer[2])
{
    if (coefficient[0] != 0 && discriminant >= 0)
    {
        formula_square (&answer[0], &answer[1], coefficient, discriminant);

    } else if (coefficient[0] == 0)
    {
        formula_linear (&answer[0], coefficient);
    } 
    return 0;
}

int formula_square (double * x_1, double * x_2, double coefficient[3], double discriminant)
{
    *x_1 = (double) (-coefficient[1] + sqrt(discriminant) ) / ( 2 * coefficient[0] );
    *x_2 = (double) (-coefficient[1] - sqrt(discriminant) ) / ( 2 * coefficient[0] );
    return 0;
}
int formula_linear (double *x, double coefficient[3])
{
    *x = (double) -1 * coefficient[2] / coefficient[1];
    return 0;
}

int show_answers (double coefficient[3], double answer[2], double discriminant)
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
    return 0;
}

int check_program (double coefficient[3], double answer[2])
{   
    input_coefficient(coefficient);    
    show_equation(coefficient);
    double discriminant = count_discriminant (coefficient);   
    solver_square (coefficient, discriminant, answer);
    printf("If you program is true, you should get ");
    show_answers(coefficient, answer, discriminant);
    
    return 0;
  
}

