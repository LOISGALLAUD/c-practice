/*
Loïs GALLAUD 1A généraliste
*/

#include <stdio.h>

int integer = 98;
float floating_number = 82.6;
double double_number = 185.3e2;
char character = 'a';

int main(void)
{

    printf("integer = %d\n", integer);
    printf("floating_number = %f\n", floating_number);
    printf("double_number = %f\n", double_number);
    printf("character = %c\n", character);

    char var = 127;
    var++;
    printf("%d\n", var);

    return 0;
}
