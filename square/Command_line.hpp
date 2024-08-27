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

struct calculate{
    int function_1;
    int function_2;
    int function_3;
    int function_4;
    char *file_name;
};





int reading_functions(int argc, char *argv[], const char *function[], calculate *keys);
int reading_file(double *coefficient, double *answer, calculate keys);

#endif