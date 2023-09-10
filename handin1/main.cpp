/* Write a program that generates random M integers and puts them
in an vector. Then it generates another N random integers and counts how
many of them are in the array using an iterator. */

void generateRandomMIntegers(int M, int N);

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

// Exercise 1
// A

int main(void)
{
    int M = 10000;
    int N = 5000;

    generateRandomMIntegers(M, N);

    return 0;
}

// write function generates random M integers
void generateRandomMIntegers(int M, int N)
{
    srand(time(0));
    std::vector<int> randomMIntegers;
    int count = 0;

    // Create iterator
    std::vector<int>::iterator it;

    for (int i = 0; i < M; i++)
    {
        randomMIntegers.push_back(rand());
    }

    for (int i = 0; i < N; i++)
    {
        for (it = randomMIntegers.begin(); it != randomMIntegers.end(); it++)
        {
            if (*it == rand())
            {
                count++;
            }
        }
    }
    std::cout << "Count: " << count << std::endl;

    return;
}

// Exercise 1
// B

// the time complexity of the algorithm is O(M*N)
// the space complexity of the algorithm is O(M)
