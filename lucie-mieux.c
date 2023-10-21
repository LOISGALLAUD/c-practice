#include <stdio.h>

int num1, num2, sum, diff;

int somme(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return abs(a - b);
}

int main(void)
{
    printf("entrer le premier nombre :");
    scanf("%d", &num1);
    printf("entrer le deuxième nombre :");
    scanf("%d", &num2);
    printf("LA somme des deux nombres est : %d\n et la différence est : %d\n)", somme(num1, num2), diff(num1, num2));
    return 0;
}