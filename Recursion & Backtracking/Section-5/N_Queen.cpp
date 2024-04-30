#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_safe(int board[10][10], int i, int j, int n)
{
    // we place Queen row wise so
    // we have to check for only for upside of the part in column and diagonal.
    // for column
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }

    // for left diagonal UPPER SIDE
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    // for right diagonal UPPER SIDE
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}
bool n_queen_problem(int board[10][10], int i, int n)
{
    // base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // rec case
    for (int j = 0; j < n; j++)
    {
        // i have to check if i,j is safe or not
        if (is_safe(board, i, j, n))
        {
            board[i][j] = 1;
            bool nextQueen = n_queen_problem(board, i + 1, n);
            if (nextQueen)
            {
                return true;
            }
        }
        // i j is not the right place
        board[i][j] = 0;
    }
    return false;
}
int main()
{

    int n;
    cin >> n;
    int board[10][10] = {0};
    bool ans = n_queen_problem(board, 0, n);
    if (ans == false)
    {
        cout << "No arrangement is possible.";
    }
    return 0;
}
