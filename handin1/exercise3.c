// Exercise 3

#include <time.h>
#include <stdio.h>

// Prototypes for the functions
int A1(int n);
int A2(int n);
int A3(int n);
int A4(int n);

// A1 -- There is a single for loop which loops n times. Therefore the time complexity is O(n).
// C1 -- We are expecting this to run very fast because it is only looping n times. The program confirmed this with time spent: 0.000004.
int A1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ++sum;
    }
    return sum;
}

// A2 -- There are two nested for loops which loop n times. Therefore the time complexity is O(n^2).
// C2 -- We are expecting this to run slower than A1 because it is looping n^2 times. The program confirmed this with time spent: 0.001912, which is a significant increase from A1 the sum value also reflects a n^2 increase.
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

// A3 -- There are two nested for loops where the second loop loops n^2 times. Therefore the time complexity is O(n^3).
// C3 -- We are expecting this to run slower than A2 because it is looping n^3 times. The program confirmed this with time spent: 2.863964, Which is a very significant increase from A2.
//       The sum value also reflects a n^3 increase.
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

// A4 -- There are two nested for loops where the second loop loops n times. Therefore the time complexity is O(n^2)
// C4 -- We are expecting this to run in a similar time to A2 because it is looping n^2 times. But here there is a difference in the second loop where it loops i times. So the time spent should be less than A2.
//       Which is confirmed in the running time which is 0.000833 and a sum value of 499500. So in this case our big O notation is not accurate, because the time spent is n^2/2.
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
    // Create array of function pointers
    int (*functionPointers[4])(int) = {A1, A2, A3, A4};

    for (int i = 0; i < 4; i++)
    {

        int n = 1000;
        clock_t begin = clock();
        // Call the function pointer
        int sum = functionPointers[i](n);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time spent on A%d: %f\n", i + 1, time_spent);

        printf("Sum: %d\n", sum);
    }

    return 0;
}

// No running the program with optimization on does not change anything in my analysis, since the time spent is simply proportionally reduced for each function.

// Without optimization on
/* Time spent on A1: 0.000006
Sum: 1000
Time spent on A2: 0.002294
Sum: 1000000
Time spent on A3: 2.888221
Sum: 1000000000
Time spent on A4: 0.000833
Sum: 499500 */

// With -0fast optimization on for the clang compiler

/* Time spent on A1: 0.000004
Sum: 1000
Time spent on A2: 0.002003
Sum: 1000000
Time spent on A3: 2.673198
Sum: 1000000000
Time spent on A4: 0.000931
Sum: 499500 */