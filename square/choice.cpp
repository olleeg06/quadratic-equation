#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include "choice.hpp"

int input_selection()
{
    int check = -1;
    printf("Do you want to check the program before executing it? (if yes to '1', if no to '0')\n");
    scanf("%d", &check);
    return check;
    
}