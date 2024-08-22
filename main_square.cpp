#include <ctype.h>
#include <string.h>
#include <math.h>
#include "decide.hpp"
#include <cstdio>

equations key[total_tests]
    {
        {{      1,        2,     -8}, {       2,        -4}},
        {{     -5,       10,     40}, {       4,        -2}},
        {{      4,        7,    -15}, {    1.25,        -3}},
        {{ 48.755, -100.343,      5}, { 2.00701, 0.0510977}},
        {{-0.1543,    5.134, -1.851}, {32.90831,  0.364531}}
    };


int main(void) {
    double coefficient[number_coefficient] = {0};
    double answer[number_answer] = {0};
    

    switch (input_selection())
    {
        case 1 : check_program (key, answer);
        break;

        case 0:  execute_program (coefficient, answer);
        break;

        default: printf("Error! Restart the program.");
    }


    return 0;
}