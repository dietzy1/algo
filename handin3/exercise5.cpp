/* (Week 6) Consider the following strategy for sorting N numbers in an array A: find
the smallest element of A and exchange it with the element in A[0]. Then find the
second smallest element of A and exchange it with A[1]. Continue in this manner
for the first N − 1 elements of A. Extend the test sort.h file with a template
implementation of this algorithm (i.e. it can take a vector with a generic element
type), which is known as selection sort. Give the best-case and worst-case running
times for the resulting algorithm.
 */

#include <vector>
#include <iostream>

template <typename T>
void selectionSort(std::vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part of the array
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        // Swap the minimum element with the first element of the unsorted part
        std::swap(arr[min_index], arr[i]);
    }
}
