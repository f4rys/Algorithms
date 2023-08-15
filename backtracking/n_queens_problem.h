#include <iostream>

using namespace std;

void PrintBoard(bool** board, int N) 
{
    for(int i=0; i<N; i++) 
    {
        for(int j=0; j<N; j++) 
        {
            if(board[i][j]) 
            {
                cout << "Q ";
            }

            else 
            {
                cout << "□ ";
            }
        }

        cout << endl;
    }
}

bool IsPositionSafe(bool** board, int N, int row, int column) 
{
    for (int i = 0; i < column; i++) 
    {
        if (board[row][i]) 
        {
            return false;
        }
    }

    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j]) 
        {
            return false;
        }
    }

    for (int i = row, j = column; j >= 0 && i < N; i++, j--) 
    {
        if (board[i][j]) 
        {
            return false;
        }
    }

    return true;
}

bool NQueensProblemSolver(bool** board, int N, int column) 
{
    if(column >= N) 
    {
        return true;
    }

    for(int i=0; i<N; i++) 
    {
        if(IsPositionSafe(board, N, i, column)) 
        {
            board[i][column] = true;

            if(NQueensProblemSolver(board, N, column + 1)) 
            {
                return true;
            }
            
            board[i][column] = false;
        }
    }

    return false;
}

void NQueensProblem(int N) 
{
    bool** board = new bool*[N];
    
    for (int i = 0; i < N; i++) 
    {
        board[i] = new bool[N];
        
        for (int j = 0; j < N; j++) 
        {
            board[i][j] = false;
        }
    }

    if(!NQueensProblemSolver(board, N, 0)) 
    {
        cout << "Solution for " << N << "x" << N << " board does not exist." << endl;
    }

    else 
    {
        PrintBoard(board, N);
        cout << endl << "Solution for " << N << "x" << N << " board." << endl;
    }
    
    for (int i = 0; i < N; i++) 
    {
        delete[] board[i];
    }
    
    delete[] board;
}