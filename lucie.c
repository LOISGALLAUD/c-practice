#include <stdio.h>

int main()
{
    int num1, num2, sum, diff;

    printf("Entrez le premier nombre : ");
    scanf("%d", &num1);
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &num2);

    sum = num1 + num2;

    if (num1 > num2)
    {
        diff = num1 - num2;
    }
    else
    {
        diff = num2 - num1;
    }

    printf("La somme des deux nombres est : %d\n", sum);
    printf("La différence entre les deux nombres est : %d\n", diff);

    return 0;
}
