#include <stdlib.h>
#include <stdexcept>
#include <iostream>

class Stack
{
private:
    size_t size;
    int *array;
    int top;

public:
    Stack(size_t const size);
    ~Stack();
    void push(int const input);
    void pop();
    void print() const;
};

Stack::Stack(size_t const size)
{
    this->size = size;
    this->array = new int[size];
    this->top = -1;
}

Stack::~Stack()
{
    delete[] this->array;
}

void Stack::push(int const input)
{

    // Check if array is full
    if (this->top == this->size - 1)
    {
        // Reallocate the array by copying over the content into a new array
        int *newArray = new int[this->size * 2];
        for (int i = 0; i < this->size; i++)
        {
            newArray[i] = this->array[i];
        }
        this->size *= 2;

        // Delete the old array
        delete[] this->array;

        // Update the array pointer to point to the new array
        this->array = newArray;
    }

    // Add element to the end of the array
    this->array[++this->top] = input;
}

void Stack::pop()
{
    // Check if array is empty
    if (this->top == -1)
    {
        throw std::out_of_range("Stack is empty");
    }

    // remove the first element in the array
    this->array[this->top--];
}

void Stack::print() const
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->array[i] << std::endl;
    }
}

int main()
{
    // Create a StackImpl object
    Stack stackImpl(4);

    // Push elements into the stack
    stackImpl.push(1);
    stackImpl.push(2);
    stackImpl.push(3);
    stackImpl.push(4);
    stackImpl.push(5);
    stackImpl.push(5);
    stackImpl.push(5);
    stackImpl.push(5);
    stackImpl.push(5);
    stackImpl.push(5);

    // print the stack
    stackImpl.print();

    // Pop elements from the stack
    stackImpl.pop();
    stackImpl.pop();
    stackImpl.push(5);
    stackImpl.push(6);

    stackImpl.print();

    return 0;
}

// Push will always be O(1) constant time because we are only adding to the end of the array
// Pop will always be O(1) most of the time but when we are forced into reallocating the array it will be O(n) linear time