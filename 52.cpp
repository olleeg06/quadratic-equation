#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <windows.h>

int compare_max(double a, double b, double *max, double *min);
int compare_epsilon(double argument);
int input_selection(char *ch, char check);
int check_program(struct equations key[5]);
int execute_program(double coefficient[3], double answer[2]);
int input_coefficient (double coefficient[3]);
int show_equation (double coefficient[3]); 
int solver_square (double coefficient [3], double discriminant, double answer[2]); 
int formula_square (double * x_1, double * x_2, double coefficient[3], double discriminant); 
int formula_linear (double *x, double coefficient[3]); 
int show_answers (double coefficient[3], double answer[2], double discriminant); 
double count_discriminant (double coefficient[3]); 



struct equations{
        double coefficient[3];
        double answer_supposed[2];
    };

    equations key[5]
    {
        {{      1,        2,     -8}, {       2,        -4}},
        {{     -5,       10,     40}, {       4,        -2}},
        {{      4,        7,    -15}, {    1.25,        -3}},
        {{ 48.755, -100.343,      5}, { 2.00701, 0.0510977}},
        {{-0.1543,    5.134, -1.851}, {32.90831,  0.364531}}
    };


int main(void) {
    double coefficient[3] = {0,0,0};
    double answer[2] = {0,0};
    char check;
    
    input_selection(&check, check);

    switch (check)
    {
        case '+' : check_program (key);
        break;

        case '-':  execute_program (coefficient, answer);
        break;
        default: printf("Error! Restart the program.");
    }
}

int input_selection(char *ch, char check)
{
    printf("Do you want to check the program before executing it? (if yes to '+', if no to '-')\n");
    scanf("%c", &check);
    *ch = check;
    return 0;
    
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
      if (coefficient[0] != 0 && compare_epsilon(discriminant))
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg\n", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && !(compare_epsilon(discriminant)) && discriminant >= 0) 
    {
        printf ("solutions to the equation: solution = %lg\n", answer[0]);

    } else 
    {
        printf ("Error! No valid values\n");

    }
    return 0;
}

int check_program (struct equations key[5])
{   
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    double answer[2] = {0,0};
    for (int i = 0; i < 5; i++){

        double discriminant = count_discriminant (key[i].coefficient);   
        solver_square (key[i].coefficient, discriminant, answer);

        compare_max(answer[0], answer[1], &answer[0], &answer[1]);
        double option_1 = fabs(key[i].answer_supposed[0] - answer[0]);
        double option_2 = fabs(key[i].answer_supposed[1] - answer[1]);
        

        if (compare_epsilon (option_1) && compare_epsilon (option_2) )
        {

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("Test %d is OK\n", i+1);
        } else 
        {
            

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("Test %d is Error\n The answers you should get are: solution_1 = %lg, solution_2 = %lg\n"
            "The answers you got: solution_1 = %lg, solution_2 = %lg\n",
            i+1, key[i].answer_supposed[0], key[i].answer_supposed[1], answer[0], answer[1]);
        }
        
    }
        return 0;
    }

int compare_epsilon(double argument)
{
    double const epsilon = 1e-5;
    if (fabs(argument) <= epsilon)
        return 1;
    else 
        return 0;
}

int compare_max(double a, double b, double *max, double *min)
{
    if (a >= b)
    { 
        *max = a;
        *min = b;
    } else 
    {
        *max = b;
        *min = a;
    }
    return 0;
}