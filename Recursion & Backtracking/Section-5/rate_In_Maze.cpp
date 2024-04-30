#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool rateInMaze(char maze[][10], int sol[][10], int i, int j, int m, int n)
{
    // base case
    if (i == m && j == n)
    {
        sol[0][0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << sol[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // rec case
    if (i > m || j > n)
    {
        return false;
    }
    if (maze[i][j] == 'X')
    {
        return false;
    }

    // assume solution exist through current cell
    sol[i][j] = 1;

    bool rightSide = rateInMaze(maze, sol, i, j + 1, m, n);
    bool downSide = rateInMaze(maze, sol, i + 1, j, m, n);

    // backtracking
    sol[i][j] = 0;

    if (rightSide || downSide)
    {
        return true;
    }
    return false;
};

int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"};

    int sol[10][10] = {0};
    bool ans = rateInMaze(maze, sol, 0, 0, 3, 3);
    if (ans == false)
    {
        cout << "path dose not exist." << endl;
    }
    return 0;
}