#ifndef COMMAND_LINE
#define COMMAND_LINE


const int number_functions = 4;
const int number_coefficient = 3;
const int number_answer = 2;
const int total_tests = 5;



struct equations{
        double coefficient[number_coefficient];
        double answer_supposed[number_answer];
    };



int reading_functions(int argc, char *argv[], const char *function[], int count[number_functions], char *file_name[]);
int reading_file(double *coefficient, double *answer, char *file_name[]);

#endif