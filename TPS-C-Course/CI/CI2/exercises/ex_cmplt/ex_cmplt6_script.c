/*
Loïs GALLAUD 1A généraliste
*/

#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int tmp;

    printf("Enter a integer: \na = ");
    scanf("%d", &a);
    printf("\nEnter a second integer: \nb = ");
    scanf("%d", &b);

    tmp = a;
    a = b;
    b = tmp;

    printf("\nThe new values of a and b are:\na = %d\nb = %d\n", a, b);

    return 0;
}
