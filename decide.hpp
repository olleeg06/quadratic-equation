#ifndef DECIDE
#define DECIDE

const int total_tests = 5;
const int number_coefficient = 3;
const int number_answer = 2;

struct equations{
        double coefficient[number_coefficient];
        double answer_supposed[number_answer];
    };

    

int input_selection();
int check_program(struct equations key[total_tests], double answer[number_answer]);
int execute_program(double coefficient[number_coefficient], double answer[number_answer]);



#endif