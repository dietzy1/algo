

#include "maxheap.h"
#include <iostream>
#include <algorithm>

int main()
{
    // Create a MaxHeapVector object
    MaxHeapVector maxHeapVector;

    // Insert elements into the heap
    maxHeapVector.insert(1);
    maxHeapVector.insert(2);

    // Find the maximum element in the heap
    std::cout << "The maximum element in the heap is: " << maxHeapVector.findMax() << std::endl;

    maxHeapVector.insert(1);
    maxHeapVector.insert(4);

    // Delete the maximum element in the heap
    std::cout << "The maximum element in the heap is: " << maxHeapVector.deleteMax() << std::endl;

    std::cout << "The maximum element in the heap is: " << maxHeapVector.findMax() << std::endl;

    // Check if the heap is empty
    if (maxHeapVector.isEmpty())
    {
        std::cout << "The heap is empty" << std::endl;
    }
    else
    {
        std::cout << "The heap is not empty" << std::endl;
    }

    // Check the size of the heap
    std::cout << "The size of the heap is: " << maxHeapVector.size() << std::endl;

    return 0;
}

bool MaxHeapVector::isEmpty() const
{
    if (heap.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int MaxHeapVector::size()
{
    return heap.size();
}

// Unoptimized simple way to insert elements into the heap
void MaxHeapVector::insert(const int x)
{
    // Create iterator to iterate through the heap
    std::vector<int>::iterator it;
    // Check if the heap is empty
    if (heap.size() == 0)
    {
        heap.push_back(x);
        return;
    }
    // check if x is greater than heap[0]
    if (x > heap[0])
    {
        heap.insert(heap.begin(), x);
        return;
    }
    // Else we simply add the element to the end of the heap
    heap.push_back(x);
}

const int MaxHeapVector::findMax() const
{
    // Protective programming throw exception if heap is empty
    if (heap.size() == 0)
    {
        throw std::out_of_range("Heap is empty");
    }

    // Since we already sort the heap when we insert an element, the maximum element is at the start of the heap
    return heap[0];
}

int MaxHeapVector::deleteMax()
{
    // Protective programming throw exception if heap is empty
    if (heap.size() == 0)
    {
        throw std::out_of_range("Heap is empty");
    }

    // Find the maximum element in the heap
    int max = heap[0];
    // Delete the maximum element in the heap
    heap.erase(heap.begin());

    // iterate through the heap and swap the max element to the start of the heap
    std::vector<int>::iterator it;

    for (it = heap.begin(); it != heap.end(); it++)
    {
        if (*it > max)
        {
            heap.insert(heap.begin(), *it);
            heap.erase(it);
            break;
        }
    }

    return max;
}
