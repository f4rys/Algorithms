#include <iostream>
#include <vector>

using namespace std;

void PrintMaze(bool** solution, int N)
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++){
            cout << " " << solution[i][j] << " ";
        }

        cout << endl;
    }
}

bool IsSafe(bool** maze, int x, int y, int N)
{
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {
        return true;
    }

    return false;
}

bool MazeSolverUtil(bool** maze, int x, int y, bool** solution, int N)
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) 
    {
        solution[x][y] = 1;
        return true;
    }

    if (IsSafe(maze, x, y, N) == true) 
    {
        if (solution[x][y] == 1)
        {
            return false;
        }

        solution[x][y] = 1;

        if (MazeSolverUtil(maze, x + 1, y, solution, N) == true)
        {
            return true;
        }

        if (MazeSolverUtil(maze, x - 1, y, solution, N) == true)
        {
            return true;
        }

        if (MazeSolverUtil(maze, x, y + 1, solution, N) == true)
        {
            return true;
        }

        if (MazeSolverUtil(maze, x, y - 1, solution, N) == true)
        {
            return true;
        }

        solution[x][y] = 0;

        return false;
    }

    return false;
}

void MazeSolver(bool** maze, int N)
{
    bool** solution = new bool*[N];

    for (int i = 0; i < N; i++) 
    {
        solution[i] = new bool[N];

        for (int j = 0; j < N; j++) 
        {
            solution[i][j] = 0;
        }
    }

    if (MazeSolverUtil(maze, 0, 0, solution, N) == false) 
    {
        cout << "Solution does not exist" << endl;
        
        for (int i = 0; i < N; i++) 
        {
            delete[] solution[i];
        }

        delete[] solution;
        
        return;
    }

    cout << "Solution: " << endl;

    PrintMaze(solution, N);
    
    for (int i = 0; i < N; i++) 
    {
        delete[] solution[i];
    }

    delete[] solution;

    return;
}

void RatInAMaze(vector<vector<bool>>& initial_maze) 
{
    int N = initial_maze.size();
    bool** maze = new bool*[N];

    for (int i = 0; i < N; ++i) 
    {
        maze[i] = new bool[N];
    }

    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            maze[i][j] = initial_maze[i][j];
        }
    }

    cout << "Maze: " << endl;
    PrintMaze(maze, N);
    cout << endl;

    MazeSolver(maze, N);

    for (int i = 0; i < N; ++i) 
    {
        delete[] maze[i];
    }

    delete[] maze;
}