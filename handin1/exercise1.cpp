
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

void generateRandomMIntegers(int M, int N)
{
    srand(time(NULL));
    int count = 0;

    std::vector<int> randomMIntegers;
    std::vector<int>::iterator it;

    for (int i = 0; i < M; i++)
    {
        // Add random integer to vector between 0 and 10000
        randomMIntegers.push_back(rand() % 10000);
    }

    for (int i = 0; i < N; i++)
    {
        for (it = randomMIntegers.begin(); it != randomMIntegers.end(); it++)
        {
            // Check if random integer is in vector of random integers from 0 to 10000
            if (*it == rand() % 10000)
            {
                count++;
            }
        }
    }
    std::cout << "Count: " << count << std::endl;

    return;
}
