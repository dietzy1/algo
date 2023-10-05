#include <iostream>

#define ROWS 5
#define COLS 5

bool navigateMaze(char maze[ROWS][COLS], int row, int col)
{
    // Base case we are looking for
    if (maze[row][col] == 'E')
    {
        return true;
    }
    // Check current position
    else if (maze[row][col] == 'X')
    {
        return false;
    }
    else
    {
        maze[row][col] = 'X';
        // Magic                // Its just smart usage of OR operator :)
        return navigateMaze(maze, row + 1, col) || navigateMaze(maze, row - 1, col) || navigateMaze(maze, row, col + 1) || navigateMaze(maze, row, col - 1);
    }
}

int main()
{

    char maze[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'E', 'X', 'X', 'X'},
    };

    std::cout << navigateMaze(maze, 1, 1) << std::endl;

    return 0;
}