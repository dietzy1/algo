
#include <iostream>

void printRecursiveTriangle(int m, int n)
{

    // Base case
    if (m > n)
    {
        return;
    }

    // Print the top of the triangle
    for (int i = 0; i < m; i++)
    {
        std::cout << "*";
    }

    std::cout << std::endl;

    // Recurse on the next smallest triangle
    printRecursiveTriangle(m + 1, n);

    // Print the bottom of the triangle
    for (int i = 0; i < m; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

int main()
{
    printRecursiveTriangle(4, 6);
    return 0;
}