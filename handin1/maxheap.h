#pragma once

#include <vector>

class MaxHeap
{
public:
    // is the heap empty?
    virtual bool isEmpty() const = 0;
    // number of elements in the heap
    virtual int size() = 0;
    // add an element to the heap
    virtual void insert(const int x) = 0;
    // find the maximum element in the heap
    virtual const int findMax() const = 0;
    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0;
};

class MaxHeapVector : public MaxHeap
{
    std::vector<int> heap;

public:
    bool isEmpty() const;
    int size();
    void insert(const int x);
    const int findMax() const;
    int deleteMax();
};