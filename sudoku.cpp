// Code to solve sudoku

#include <bits/stdc++.h>
using namespace std;

bool CanPlace(int sudoku[9][9], int i, int j, int k)
{
    for (int x = 0; x < 9; x++)
    {
        if (sudoku[i][x] == k || sudoku[x][j] == k)
        {
            return false;
        }
    }
    int si = (i / 3) * 3;
    int sj = (j / 3) * 3;
    for (int x = si; x < si + 3; x++)
    {
        for (int y = sj; y < sj + 3; y++)
        {
            if (sudoku[x][y] == k)
            {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver(int board[9][9], int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return SudokuSolver(board, i + 1, 0);
    }
    if (board[i][j] != 0)
    {
        return SudokuSolver(board, i, j + 1);
    }
    for (int k = 1; k <= 9; k++)
    {
        if (CanPlace(board, i, j, k))
        {
            board[i][j] = k;
            bool CanSolve = SudokuSolver(board, i, j + 1);
            if (CanSolve)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int matrix[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];
        }
    }
    if (SudokuSolver(matrix, 0, 0))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Sudoku cannot be solved" << endl;
    }
    return 0;
}