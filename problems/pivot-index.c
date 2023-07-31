/*
Find Pivot Index

Given an array of integers nums,
calculate the pivot index of this array.

The pivot index is the index where the
sum of all the numbers strictly to the
left of the index is equal to the sum of
all the numbers strictly to the index's right.

If the index is on the left edge of the array,
then the left sum is 0 because there are no
elements to the left. This also applies to the
right edge of the array.

Return the leftmost pivot index. If no such index
exists, return -1.
*/

#include <stdio.h>
#include <stdlib.h>

const int numsSize = 6;

int pivotIndex(int *nums, int numsSize)
{
    int sumRight, sumLeft;
    for (size_t currentIdx = 0; currentIdx < numsSize; ++currentIdx)
    {
        sumLeft = 0;
        sumRight = 0;
        if (!currentIdx)
        {
            sumLeft = 0;
        }
        else
        {
            for (size_t i = 0; i < currentIdx; ++i)
            {
                sumLeft += *(nums + i);
            }
        }

        if (currentIdx == numsSize - 1)
        {
            sumRight = 0;
        }
        else
        {
            for (size_t j = numsSize - 1; j > currentIdx; --j)
            {
                sumRight += *(nums + j);
            }
        }

        // printf("i: %zu, sumLeft: %i, sumRight: %i\n", currentIdx, sumLeft, sumRight);
        if (sumLeft == sumRight)
        {
            return currentIdx;
        }
    }
    return -1;
}

int fastPivotIndex(int *nums, int numsSize)
{
    int leftsum = 0, total = 0;

    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (leftsum + leftsum + nums[i] == total)
        {
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}

int main(void)
{
    int *tab = (int *)malloc(numsSize * sizeof(int));
    tab[0] = 1;
    tab[1] = 7;
    tab[2] = 3;
    tab[3] = 6;
    tab[4] = 5;
    tab[5] = 6;

    int pivotIdx = fastPivotIndex(tab, numsSize);
    printf("%i\n", pivotIdx);

    free(tab);
    return 0;
}