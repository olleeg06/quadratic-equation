#ifndef SOLUTION
#define SOLUTION

int execute_program(double *coefficient, double *answer);

int solver_square (double *coefficient, double discriminant, double *answer); 
int input_coefficient (double *coefficient);
int show_equation (double *coefficient);
int show_answers (double *coefficient, double *answer, double discriminant); 
double count_discriminant (double *coefficient); 
int compare_epsilon(double argument);


#endif