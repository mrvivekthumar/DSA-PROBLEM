#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Wines_Problem(int wines[], int i, int j, int dp[6][6], int year)
{
    // Base case
    if (i > j)
    {
        return 0;
    }

    // Lookup for already computed value
    if (dp[i][j] != 0)
    {
        return dp[i][j];
    }

    // Rec case
    int option1 = wines[i] * year + Wines_Problem(wines, i + 1, j, dp, year + 1);
    int option2 = wines[j] * year + Wines_Problem(wines, i, j - 1, dp, year + 1);

    int ans = max(option1, option2);
    dp[i][j] = ans;

    return ans;
};
int main()
{
    int wines[] = {2, 3, 5, 1, 4};
    int j = sizeof(wines) / sizeof(int);
    int year = 1;
    int dp[6][6] = {0};
    cout << Wines_Problem(wines, 0, j - 1, dp, year);
    return 0;
}