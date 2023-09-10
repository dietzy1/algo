// Exercise 2
// The time complexity of the myMethod algorhytm is n^3 because of the three nested for loops.

// The time complexity of the myMethod algorhytm is o(n^3) because of the initial three nested for loops. There is another for loop which loops n*n times which is the same as n^2.
// However the algorithm is still O(n^3) because 0(n^2) is smaller than 0(n^3) and therefore can be ignored. This is due to n^2 being insignificant compared to n^3 if N is large enough.

// The space complexity of the algorithm is O(1) because there aren't any extra data structures being created, accessing variables is constant time and the size of the input doesn't affect the space complexity.

int myMethod(int N)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N * sqrt(N); k++)
            {
                x++;
            }
        }
    }
    for (int i = 0; i < N * N; i++)
    {
        y++;
    }
    return x + y;
}