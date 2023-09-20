
#include "listMaxheap.h"
#include <stdexcept>
#include <algorithm>

bool MaxHeapList::isEmpty() const
{
    return heap.empty();
}

int MaxHeapList::size()
{
    return heap.size();
}

void MaxHeapList::insert(const int x)
{
    // Add the element to the end of the linked list.
    heap.push_back(x);
    heapifyDown(heap.size() - 1);
}

const int MaxHeapList::findMax() const
{
    if (!isEmpty())
    {
        // The maximum element is at the root.
        return heap.find_kth(0);
    }
    else
    {
        // Protective programming
        throw std::runtime_error("Heap is empty.");
    }
}

int MaxHeapList::deleteMax()
{
    if (!isEmpty())
    {
        int max = heap.find_kth(0);
        int lastElement = heap.pop_back();

        if (!isEmpty())
        {
            heap.push_front(lastElement);
            heapifyDown(0);
        }

        return max;
    }

    throw std::out_of_range("Heap is empty");
}

void MaxHeapList::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap.size() && heap.find_kth(leftChild) > heap.find_kth(largest))
        largest = leftChild;

    if (rightChild < heap.size() && heap.find_kth(rightChild) > heap.find_kth(largest))
        largest = rightChild;

    if (largest != index)
    {
        std::swap(heap.find_kth(index), heap.find_kth(largest));
        heapifyDown(largest);
    }
}

void MaxHeapList::heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap.find_kth(index) > heap.find_kth(parent))
    {
        std::swap(heap.find_kth(index), heap.find_kth(parent));
        index = parent;
        parent = (index - 1) / 2;
    }
}
