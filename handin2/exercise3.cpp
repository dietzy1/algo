
#include <iostream>

bool searchMatrix(const int x, const int *const array, const int n, const int m);

int main()
{

    int matrix[4][4] = {{16, 15, 14, 13},
                        {12, 11, 10, 9},
                        {8, 7, 6, 5},
                        {4, 3, 2, 1}};

    bool found = searchMatrix(7, (int *)matrix, 4, 4);

    std::cout << found << std::endl;

    return 0;
}

// This implementation uses a one-dimensional array to represent a two-dimensional array.
// The function takes in the value to search for, the array, the number of rows and the number of columns.
bool searchMatrix(const int x, const int *const array, const int n, const int m)
{
    int i = 0;
    int j = m - 1;

    while (i < n && j >= 0)
    {
        if (array[i * m + j] == x)
        {
            return true;
        }
        else if (array[i * m + j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}

// the big o notation for this function is O(n+m) because we are iterating through the array n times and m times.
