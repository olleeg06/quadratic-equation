#ifndef CHECK
#define CHECK

const int number_coefficient = 3;
const int number_answer = 2;
const int total_tests = 5;

const equations key[total_tests] =
    {
        {{      1,        2,     -8}, {       2,        -4}},
        {{     -5,       10,     40}, {       4,        -2}},
        {{      4,        7,    -15}, {    1.25,        -3}},
        {{ 48.755, -100.343,      5}, { 2.00701, 0.0510977}},
        {{-0.1543,    5.134, -1.851}, {32.90831,  0.364531}}
    };


struct equations{
        double coefficient[number_coefficient];
        double answer_supposed[number_answer];
    };

    
int check_program(struct equations *key, double *answer);


#endif