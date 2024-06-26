#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool can_place(int mat[][9], int i, int j, int n, int number)
{
    // for both row and column simultaneouslu
    for (int x = 0; x < n; x++)
    {
        if (mat[x][j] == number || mat[i][x] == number)
        {
            return false;
        }
    }

    // for row check if the number already exist
    // for (int row = 0; row < n; row++)
    // {
    //     if (mat[row][j] == number)
    //     {
    //         return false;
    //     }
    // }

    // for columm check if the number already exist
    // for (int column = 0; column < n; column++)
    // {
    //     if (mat[i][column] == number)
    //     {
    //         return false;
    //     }
    // }
    // for subgrid check if the number already exist
    int sq_rt = sqrt(n);
    int sx = (i / sq_rt) * sq_rt;
    int sy = (j / sq_rt) * sq_rt;

    for (int x = sx; x < (sx + sq_rt); x++)
    {
        for (int y = sy; y < (sy + sq_rt); y++)
        {

            if (mat[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku_Solver(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << "  ";
            }
            cout << endl;
        }
        return true;
    }

    // case for the row end
    if (j == n)
    {
        return sudoku_Solver(mat, i + 1, 0, n);
    }
    // already occupied
    if (mat[i][j] != 0)
    {
        return sudoku_Solver(mat, i, j + 1, n);
    }
    // rec case
    // fill the current cell
    for (int number = 1; number <= n; number++)
    {
        if (can_place(mat, i, j, n, number))
        {
            mat[i][j] = number;
            bool nextPosition = sudoku_Solver(mat, i, j + 1, n);
            if (nextPosition)
            {
                return true;
            }
        }
    }
    mat[i][j] = 0;
    return false;
}
int main()
{
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    bool ans = sudoku_Solver(mat, 0, 0, 9);
    if (ans == false)
    {
        cout << "can't solve this sudoku.";
    }
    return 0;
}