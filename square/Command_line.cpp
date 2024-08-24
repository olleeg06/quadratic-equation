#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <string.h>
#include "Command_line.hpp"
#include "check.hpp"
#include "execute.hpp"
#include "solution.hpp"
 


int reading_functions(int argc, char *argv[], const char *function[], int count[number_functions], char *file_name[]);

int reading_file(double *coefficient, double *answer, char *file_name[]);


int reading_functions(int argc, char *argv[], const char *function[], int count[number_functions], char *file_name[])
    {

    for(int i = 1; i < argc; i++){

     if (strcmp(argv[i], function[0]) == 0){
        count[0]++;

    } else if (strcmp(argv[i], function[1]) == 0){
        count[1]++;

    } else if (strcmp(argv[i], function[2]) == 0){
        count[2]++;

    } else if (strcmp(argv[i], function[3]) == 0){
        *file_name = argv[i+1];
        i++;
        count[3]++;
    }
    }

return 0;

}


int reading_file(double *coefficient, double *answer, char *file_name[]) {
    
    struct coefficientss{
        double coefficient[number_coefficient];
    };
    
    FILE *file = fopen(*file_name, "r");
    if (file == NULL) {
        printf("Error opening file");
    } else {
    for (int i = 1; (fscanf(file, "%lg%lg%lg", 
           &coefficient[0], &coefficient[1], &coefficient[2])) == number_coefficient ; i++) {
 
        double discriminant = count_discriminant (coefficient);   
        solver_square (coefficient, discriminant, answer);
        printf("Equation number %d: %lg * x^2 + %lg * x + %lg = 0\n", i, coefficient[0], coefficient[1] ,coefficient[2]);
        show_answers(coefficient, answer, discriminant);
        }
    }
return 0;
}