#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Minimum_Cost_To_Reach_Bottom(int cost[3][3], int row, int column, int dp[4][4])
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = cost[0][0];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[0][j - 1] + cost[0][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][0] + cost[i][0];
            }
            else
            {
                dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[row - 1][column - 1];
};

int main()
{
    int cost[3][3] = {
        {2, 1, 1},
        {1, 3, 1},
        {8, 1, 3}};

    int dp[4][4] = {0};

    cout << Minimum_Cost_To_Reach_Bottom(cost, 3, 3, dp);

    return 0;
}