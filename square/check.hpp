#ifndef CHECK
#define CHECK

const int number_coefficient = 3;
const int number_answer = 2;
const int total_tests = 5;



struct equations{
        double coefficient[number_coefficient];
        double answer_supposed[number_answer];
    };




    
int check_program(struct equations *key, double *answer);


#endif