

#include "maxheap.h"
#include <iostream>

int main()
{
    // Create a MaxHeapVector object
    MaxHeapVector maxHeapVector;

    // Insert elements into the heap
    maxHeapVector.insert(1);
    maxHeapVector.insert(2);

    // Find the maximum element in the heap
    std::cout << "The maximum element in the heap is: " << maxHeapVector.findMax() << std::endl;

    // Delete the maximum element in the heap
    std::cout << "The maximum element in the heap is: " << maxHeapVector.deleteMax() << std::endl;

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

void MaxHeapVector::insert(const int x)
{
    heap.push_back(x);
}

const int MaxHeapVector::findMax() const
{
    // Protective programming throw exception if heap is empty
    if (heap.size() == 0)
    {
        throw std::out_of_range("Heap is empty");
    }

    // Find the maximum element in the heap
    int max = heap[0];

    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i] > max)
        {
            max = heap[i];
        }
    }
    return max;
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
    int maxIndex = 0;

    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i] > max)
        {
            max = heap[i];
            maxIndex = i;
        }
    }

    // Delete the maximum element in the heap
    heap.erase(heap.begin() + maxIndex);

    return max;
}
