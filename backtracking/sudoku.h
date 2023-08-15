#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void PrintGrid(const vector<vector<int>>& grid) 
{
    for (const auto& row : grid) 
    {
        for (int number : row) 
        {
            cout << number << " ";
        }

        cout << endl;
    }
}

bool FindEmptySpot(const vector<vector<int>>& grid, int& row, int& column) 
{
    for (row = 0; row < grid.size(); row++) 
    {
        for (column = 0; column < grid[row].size(); column++) 
        {
            if (grid[row][column] == 0) 
            {
                return true;
            }
        }
    }

    return false;
}

bool IsUsedInRow(const vector<std::vector<int>>& grid, int row, int number) 
{
    for (int i = 0; i < grid.size(); i++) 
    {
        if (grid[row][i] == number) 
        {
            return true;
        }
    }

    return false;
}

bool IsUsedInColumn(const vector<vector<int>>& grid, int column, int number) 
{
    for (int i = 0; i < grid.size(); i++) 
    {
        if (grid[i][column] == number) 
        {
            return true;
        }
    }

    return false;
}

bool IsUsedInBox(const vector<vector<int>>& grid, int start_row, int start_column, int number) 
{
    int sqrt_size = sqrt(grid.size());

    for (int i = 0; i < sqrt_size; i++) 
    {
        for (int j = 0; j < sqrt_size; j++) 
        {
            if (grid[i + start_row][j + start_column] == number) 
            {
                return true;
            }
        }
    }

    return false;
}

bool IsSpotSafe(const vector<vector<int>>& grid, int row, int column, int number) 
{
    int sqrt_size = sqrt(grid.size());
    int start_row = row - row % sqrt_size;
    int start_column = column - column % sqrt_size;

    return !IsUsedInRow(grid, row, number)
           && !IsUsedInColumn(grid, column, number)
           && !IsUsedInBox(grid, start_row, start_column, number)
           && grid[row][column] == 0;
}

bool SudokuSolver(vector<vector<int>>& grid) 
{
    int row, column;

    if (!FindEmptySpot(grid, row, column)) 
    {
        return true;
    }

    for (int i = 1; i <= grid.size(); i++) 
    {
        if (IsSpotSafe(grid, row, column, i)) 
        {
            grid[row][column] = i;

            if (SudokuSolver(grid)) 
            {
                return true;
            }

            grid[row][column] = 0;
        }
    }

    return false;
}

void Sudoku(vector<vector<int>>& grid) 
{
    vector<vector<int>> grid_temp = grid;

    cout << "Riddle:" << endl;
    PrintGrid(grid_temp);
    cout << endl;

    if (SudokuSolver(grid)) 
    {
        cout << "Solution:"<< endl;
        PrintGrid(grid);
    }

    else
    {
        cout << "There is no solution to this sudoku.";
    }
}