#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8}};

#define train_count (sizeof(train) / sizeof(train[0]))

float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

float cost(float w, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; i++)
    {
        float x = train[i][0];
        float y = x * w + b;
        float d = y - train[i][1];
        result += d * d; // ∑(y-t)^2
    }
    result /= train_count; // ∑(y-t)^2 / N Normalize
    return result;
}

int main(void)
{
    srand(time(0)); // use current time as seed for random generator
    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;
    printf("w = %f\n", w);

    float eps = 1e-3;
    float rate = 1e-3;
    for (size_t i = 0; i < 1e4; ++i)
    {
        float c = cost(w, b);
        float dcost = (cost(w + eps, b) - c) / eps;
        float db = (cost(w, b + eps) - c) / eps;
        w -= rate * dcost;
        b -= rate * db;
        printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }
    printf("--------------------\n");
    printf("w = %f\n", w);
    printf("b = %f\n", b);
    return 0;
}