#include <vector>
#include <iostream>

void countingSort(std::vector<int> &arr)
{
    // Find the maximum and minimum elements in the array
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    // Calculate the range of the elements in the array
    int range = max - min + 1;

    // Initialize the count vector with size equal to the range, and the output vector with size equal to the array size
    std::vector<int> count(range), output(arr.size());

    // Count the occurrence of each element in the array
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - min]++;
    }

    // Modify the count array such that each element at each index
    // stores the sum of previous counts
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

int main()
{

    std::vector<int> arr = {5, 2, 8, 1, 9};
    countingSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
