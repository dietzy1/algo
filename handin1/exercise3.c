// Exercise 3

#include <time.h>
#include <stdio.h>

// Prototypes for the functions
int A1(int n);
int A2(int n);
int A3(int n);
int A4(int n);

int A1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ++sum;
    }
    return sum;
}

int A2(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ++sum;
        }
    }
    return sum;
}

int A3(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n * n; ++j)
        {
            ++sum;
        }
    }
    return sum;
}

int A4(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++sum;
        }
    }
    return sum;
}
// Main function which does time benchmarking on the 4 functions
int main(void)
{

    int (*functionPointers[4])(int) = {A1, A2, A3, A4};

    int nValues[] = {
        100,
        200,
        300,
        400,
        500,
        600,
        700,
        800,
        900,
        1000,
        1100,
        1200,
        1300,
        1400,
    };

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 14; j++)
        {
            int n = nValues[j];
            printf("n: %d\n", n);

            clock_t begin = clock();

            int sum = functionPointers[i](n);

            clock_t end = clock();

            long double time_spent = (long double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time spent on A%d: %Lf seconds\n", i + 1, time_spent);
        }
    }

    return 0;
}
