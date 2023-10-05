

#include <iostream>

bool searchRecursively(const int *a, size_t n, int x)
{
    // First edge case
    if (n == 0)
    {
        return false;
    }
    // Second edge case
    else if (a[n - 1] == x)
    {
        return true;
    }
    else
    {
        return searchRecursively(a, n - 1, x);
    }
}

int findMaxRecursively(const int *a, size_t n)
{
    // First edge case
    if (n == 0)
        return 0;
    // Second edge case
    if (n == 1)
    {
        return a[0];
    }

    int max = findMaxRecursively(a, n - 1);
    if (max > a[n - 1])
    {
        return max;
    }
    else
    {
        return a[n - 1];
    }
}

int findMinRecursively(const int *a, size_t n)
{
    // First edge case
    if (n == 0)
        return 0;
    // Second edge case
    if (n == 1)
    {
        return a[0];
    }

    int min = findMinRecursively(a, n - 1);
    if (min < a[n - 1])
    {
        return min;
    }
    else
    {
        return a[n - 1];
    }
}

int main()
{

    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << searchRecursively(a, 8, 9) << std::endl;

    std::cout << findMaxRecursively(a, 8) << std::endl;

    std::cout << findMinRecursively(a, 8) << std::endl;

    return 0;
}