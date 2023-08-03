#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *tab = (int *)malloc(10 * sizeof(int));
    for (size_t i = 0; i < 10; ++i)
    {
        if (!i)
        {
            printf("c'est un zero: %i\n", tab[i]);
        }
        else
        {
            printf("c'est pas un zero: %i\n", tab[i]);
        }
    }
}