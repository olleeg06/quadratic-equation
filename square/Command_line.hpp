#ifndef COMMAND_LINE
#define COMMAND_LINE


const int number_functions = 4;
const int number_coefficient = 3;
const int number_answer = 2;
const int total_tests = 5;
const int command_help = 5;
const int command_test = 5;
const int command_solution = 9;
const int command_file = 5;

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

struct commands{
   const char command_1[command_help];
   const char command_2[command_test];
   const char command_3[command_solution];
   const char command_4[command_file];
};


int reading_functions(int argc, char *argv[], struct commands meow, calculate *keys);
int reading_file(double *coefficient, double *answer, calculate keys);

#endif