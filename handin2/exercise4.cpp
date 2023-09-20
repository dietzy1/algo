#pragma once

#include "Week_03/stack/stack_class.h"
#include <stdexcept>
#include <iostream>

template <typename Object>
class Queue
{
private:
    Stack<Object> front;
    Stack<Object> rear;

    // Insert at rear
    // Delete at front

public:
    Queue()
    {
    }
    ~Queue()
    {
    }

    bool empty()
    {
        return front.empty() && rear.empty();
    }

    // put in element at the rear of the queue
    void enqueue(const Object x)
    {
        rear.push(x);
    }

    // remove element from the front of the queue
    Object dequeue()
    {
        if (front.empty())
        {
            // Reverse the order of elements from rearStack to frontStack.
            while (!rear.empty())
            {
                front.push(rear.top());
                rear.pop();
            }
        }

        if (front.empty())
        {
            // The queue is empty.
            throw std::runtime_error("Queue is empty");
        }

        Object frontElement = front.top();
        front.pop();
        return frontElement;
    }
};

int main()
{
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // print contents of queue
    while (!queue.empty())
    {
        std::cout << queue.dequeue() << std::endl;
    }

    return 0;
}
// The time complexity of the enqueue operation is O(1) because we are just pushing the element to the rear stack.
// The time complexity of the dequeue operation is O(N) when the front stack is empty
// But this is going to happen infrequently, so the amortized time complexity is O(1).