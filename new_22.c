#include <stdio.h>
#include <math.h>

int input (double coefficient [3]); // TODO: may me more spaces
                                    // TODO: general name input can be everywhere, add verbs
                                    // you may try get_coefficiets or something like that
int show_equation(double coefficient [3]); // good name
int solver(double coefficient [3], double discriminant, double answer [2]); // may be solve sth
int formula (double * x_1, double * x_2, double coefficient[3], double discriminant); // what formula, rename
int formula_linear (double *x, double coefficient[3]); // also
int show_answers (double coefficient[3], double answer[2], double discriminant); // good
double formula_discriminant(double coefficient[3]); // may be ok


double const epsilon = 1e-11;

// you can add some info about error input
// for example "you entered not a number, try again"


// TODO: Now your whole program is just a one .cpp file with everything in it.
//
//       You need to split your program in few different files.
//
//       To do this, learn about header files, they will help you to "join"
//       different modules together.
//
//       How to split your program -- is something you need to come up with 
//       yourself, try thinking about logical modules inside this program,
//       what can you extract and how it will help. Think carefully, don't 
//       overdo it too :) 


// TODO: use .cpp files, not .c
// c++ has a better compiler


int main(void) {
    double coefficient[3] = {0,0,0};
    double answer[2] = {0,0};
    double discriminant = 0; // why you put diskriminant here? it can be
                             // double discriminant = formula_discriminant(coefficient);  
                             // initialize variables closer to places where you use it 

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
//                          ^
//                          | ~~~~~ as for me that space looks strange

// NOTE: i had the same error hahahah

// a year ago:

   // TODO: inconsistent style, usually we don't put spaces before [] brackes, and you 
   //        didn't earlier in main, be consistent.

{
    printf("Enter the coefficients of the quadratic equation (or 'q' to completion):\n");
    return scanf("%lg %lg %lg", &coefficient[0], &coefficient[1], &coefficient[2]);
}

int show_equation(double coefficient [3]) // <------------------------------------------------------
{                                                       //                                         |                                     
    printf("%lg * x^2 + %lg * x + %lg = 0 \n",  coefficient[0], coefficient[1] ,coefficient[2]);
}                                                       //                                    why are they different???
                                                        //                                         |
double formula_discriminant(double coefficient[3]) // <---------------------------------------------
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
    //               ^ these spaces are also strange
}
    // TODO: you can write -coefficient[1] instead of -1 * coefficient[1]
int formula_linear (double *x, double coefficient[3])
{
    *x = (double) -1 * coefficient[2] / coefficient[1];
}

int show_answers(double coefficient[3], double answer[2], double discriminant)
{
      if (coefficient[0] != 0 && discriminant >= epsilon)
    {
        printf ("solutions to the equation: solution_1 = %lg, solution_2 = %lg\n", answer[0], answer[1]);

    } else if (coefficient[0] != 0 && discriminant < epsilon && discriminant >= 0) // and if D = -1e-25 then what?
                                                                                   // it is also zero
                                                                                   // may be use module comparison
    {
        printf ("solutions to the equation: solution = %lg\n", answer[0]);

    } else 
    {
        printf ("Error! No valid values\n");

    }
}

// about defines and consts from my mentor:

// TODO: Do not use define, there are a lot a cases where they can cause weird
//       behaviours they were necessary in C, but since we use C++ compiler we
//       have an alternative, constants:
//
//
//       const int LIMIT = 20; // For example
//       inline const int LIMIT = 20; // You can add "inline", although it's a newer C++
//                                    // it makes sure that constant is substituted
//                                    // pretty much the same way, define is, when possible
//
//
//       About weird cases, think what problems can occur if you were to use define
//       as a variable name later, or make define equal to expression, not just 
//       a single number, and so on... All this cases will cause weirdness, which only
//       gets worse since it's not easy to distinguish macros from variable without
//       searching for a declaration.
// 
//       So, try to avoid them, when possible.


