
#include <iostream>

void bookletPrint(int startPage, int endPage)
{
    // Base case
    if (startPage > endPage)
    {
        return;
    }

    // Calculate the sheet number
    int sheet = (startPage + 1) / 2;

    std::cout << "Sheet " << sheet << " contains pages ";

    // Recursively print the pages
    std::cout << startPage << ", " << startPage + 1 << ", " << endPage - 1 << ", " << endPage << ", " << std::endl;
    bookletPrint(startPage + 2, endPage - 2);
}

int main()
{

    bookletPrint(1, 8);
    return 0;
}