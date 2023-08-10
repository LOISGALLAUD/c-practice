/*
Maximum and minimum
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
#define freeArray free

int *generateRandomArray(int size)
{
    int *array = (int *)malloc(size * sizeof(int));
    size_t *i = (size_t *)calloc(1, sizeof(size_t));
    for (; *i < size; ++(*i))
    {
        *(array + *i) = rand() % 10;
    }
    free(i);
    return array;
}

void printArray(int *array, int size)
{
    size_t *i = (size_t *)calloc(1, sizeof(size_t));
    printf("[ ");
    for (; *i < size; ++(*i))
    {
        printf("%d ", *(array + *i));
    }
    printf("]\n");
    free(i);
}

int getMax(int *array, int size)
{
    int maxValue = (*array);
    int *tmp = (int *)malloc(sizeof(int));
    size_t *i = (size_t *)calloc(1, sizeof(size_t));
    for (; *i < size; ++(*i))
    {
        *tmp = *(array + (*i));
        if (*tmp > maxValue)
        {
            maxValue = *tmp;
        }
    }
    free(i);
    free(tmp);
    return maxValue;
}

int main(void)
{
    srand(time(NULL));
    int *array = generateRandomArray(SIZE);
    int *maxValue = (int *)malloc(sizeof(int));
    *maxValue = getMax(array, SIZE);
    printf("Max value of the array: %d\n", *maxValue);
    printArray(array, SIZE);

    freeArray(array);
    free(maxValue);
    return 0;
}