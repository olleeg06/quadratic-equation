#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <string.h>
#include "Command_line.hpp"
#include "check.hpp"
#include "execute.hpp"
#include "solution.hpp"
 


int reading_functions(int argc, char *argv[], struct commands meow, struct calculate *keys);

int reading_file(double *coefficient, double *answer, calculate keys);


int reading_functions(int argc, char *argv[], struct commands meow, struct calculate *keys)
    {

    for(int i = 1; i < argc; i++){

     if (strcmp(argv[i], meow.command_1) == 0){
        keys->function_1++;

    } else if (strcmp(argv[i], meow.command_2) == 0){
        keys->function_2++;

    } else if (strcmp(argv[i], meow.command_3) == 0){
        keys->function_3++;

    } else if (strcmp(argv[i], meow.command_4) == 0){
        keys->file_name = argv[i+1];
        i++;
        keys->function_4++;
    }
    }

return 0;

}


int reading_file(double *coefficient, double *answer, calculate keys) {
    
    struct coefficientss{
        double coefficient[number_coefficient];
    };
    
    FILE *file = fopen(keys.file_name, "r");
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