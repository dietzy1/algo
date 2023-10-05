/* (Week 6) IntroSort is a modification of quickSort developed by Musser in 1997
(see MUSSER, D.R. (1997), Introspective Sorting and Selection Algorithms. Softw:
Pract. Exper., 27: 983-993.). It is the sorting algorithm used by many C++ compilers as the implementation of the std::sort algorithm. You can find the article
using our library (remember to use VPN or be on campus for access). You can
find a quick description and implementation using an array here: https://www.
geeksforgeeks.org/know-your-sorting-algorithm-set-2-introsort-cs-sorting-w(and in the code for this week).
(a) Modify the implementation of quick sort.h into an IntroSort. That is make
a constant (useInsertion) that defines when to use quickSort and when
to use insertionSort (in the geeksforgeeks implementation that is 16) and
change the quickSort method to use either quickSort or insertion sort depending on the size of the collection to be sorted. Add assert to ensure
2
the methods’ pre-conditions are true (i.e. what is the accepted values of the
parameters) */

/* Modify the implementation of quick sort.h into an IntroSort. That is make
a constant (useInsertion) that defines when to use quickSort and when
to use insertionSort (in the geeksforgeeks implementation that is 16) and
change the quickSort method to use either quickSort or insertion sort depending on the size of the collection to be sorted. Add assert to ensure
2
the methods’ pre-conditions are true (i.e. what is the accepted values of the
parameters)
 */

```cpp
#include <cassert>

    const int useInsertion = 16;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void quickSort(int arr[], int left, int right)
{
    assert(left >= 0 && right >= left && "Invalid range for sorting");

    int size = right - left + 1;

    if (size < useInsertion)
    {
        insertionSort(arr, left, right);
    }
    else
    {
        // Implement quickSort here
    }
}
