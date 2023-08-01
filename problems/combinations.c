/*
Combination

Given two integers n and k, return all
possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    int **result = NULL;
    int *temp = NULL;
    int i = 0, j = 0, m = 0;
    int count = 0;
    int index = 0;
    int flag = 0;

    if (n < k)
    {
        return NULL;
    }

    count = 1;
    for (i = 0; i < k; i++)
    {
        count *= (n - i);
    }
    for (i = 0; i < k; i++)
    {
        count /= (i + 1);
    }

    result = (int **)malloc(sizeof(int *) * count);
    temp = (int *)malloc(sizeof(int) * k);
    for (i = 0; i < k; i++)
    {
        temp[i] = i + 1;
    }

    while (1)
    {
        result[index] = (int *)malloc(sizeof(int) * k);
        memcpy(result[index], temp, sizeof(int) * k);
        index++;

        flag = 0;
        for (i = k - 1; i >= 0; i--)
        {
            if (temp[i] < n - k + i + 1)
            {
                temp[i]++;
                for (j = i + 1; j < k; j++)
                {
                    temp[j] = temp[j - 1] + 1;
                }
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    *returnSize = count;
    *returnColumnSizes = (int *)malloc(sizeof(int) * count);
    for (i = 0; i < count; i++)
    {
        (*returnColumnSizes)[i] = k;
    }

    return result;
}

int main()
{
    int n = 10;
    int k = 5;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **result = NULL;
    int i = 0, j = 0;

    result = combine(n, k, &returnSize, &returnColumnSizes);

    for (i = 0; i < returnSize; i++)
    {
        for (j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}