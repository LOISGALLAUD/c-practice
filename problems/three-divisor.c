/*
Three divisors

Given an integer n, return true if n
has exactly three positive divisors.
Otherwise, return false.

An integer m is a divisor of n if there
exists an integer k such that n = k * m.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isThree(int n)
{
    if (n < 4)
        return false;
    int m = sqrt(n);
    if (m * m != n)
        return false;

    for (int loop_idx = 2; loop_idx <= (m >> 1); loop_idx++)
    {
        if ((m % loop_idx) == 0)
            return false;
    }

    return true;
}

int *threeTimesDividedNumbers(int range)
{
    int *array = malloc(range * sizeof(int));
    size_t arrayIndex = 0;

    for (size_t i = 1; i <= range; ++i)
    {
        if (isThree(i))
        {
            array[arrayIndex++] = i;
        }
    }

    return array;
}

void print_array(int *array, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void free_array(int *array)
{
    free(array);
}

int main(void)
{
    int *threeTimes = threeTimesDividedNumbers(50);
    print_array(threeTimes, 5);
    free_array(threeTimes);
    return 0;
}
