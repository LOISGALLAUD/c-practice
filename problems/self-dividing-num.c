/*
Self Dividing Numbers

A self-dividing number is a number
that is divisible by every digit it
contains.

For example, 128 is a self-dividing number
because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
A self-dividing number is not allowed to
contain the digit zero.

Given two integers left and right, return
a list of all the self-dividing numbers in
the range [left, right].
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *slice(int num)
{
    int *tab = (int *)malloc(10 * sizeof(int)); // Utiliser 10 plutôt que 1e3
    int i = 0;
    while (num)
    {
        *(tab + i) = num % 10;
        num /= 10;
        ++i;
    }
    return tab;
}

int *selfDividingNumbers(int left, int right, int *returnSize)
{
    int *result = (int *)malloc((right - left + 1) * sizeof(int)); // Allouer une taille appropriée
    int *tab;
    int i = 0;
    int j = 0;
    int k = 0;
    int isSelfDividing = 1;
    for (i = left; i <= right; ++i)
    {
        tab = slice(i);
        for (j = 0; j < 10; ++j) // Utiliser 10 plutôt que 1e3
        {
            if (*(tab + j) == 0)
            {
                isSelfDividing = 0;
                break;
            }
            if (i % *(tab + j) != 0)
            {
                isSelfDividing = 0;
                break;
            }
        }
        if (isSelfDividing)
        {
            *(result + k) = i;
            ++k;
        }
        isSelfDividing = 1;
        free(tab); // Libérer la mémoire allouée pour tab à chaque itération
    }
    *returnSize = k;
    return result;
}

int main(void)
{
    int left = 1;
    int right = 22;
    int returnSize = 0;
    int *result = selfDividingNumbers(left, right, &returnSize);
    for (size_t i = 0; i < returnSize; ++i)
    {
        printf("%i\n", result[i]); // Afficher les nombres auto-divisibles correctement
    }
    free(result); // Libérer la mémoire allouée pour result
    return 0;
}
