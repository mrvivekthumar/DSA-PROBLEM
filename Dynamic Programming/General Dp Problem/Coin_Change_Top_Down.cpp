#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Coin_Change_Top_Down(int n, int coins[], int numberOfCoins, int dp[])
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Lookup for already computed
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Rec case
    int ans = INT_MAX;
    for (int i = 0; i < numberOfCoins; i++)
    {
        if (n - coins[i] >= 0)
        {
            int subProblem = Coin_Change_Top_Down(n - coins[i], coins, numberOfCoins, dp) + 1;
            ans = min(ans, subProblem);
        }
    }
    dp[n] = ans;

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int coins[] = {1, 7, 10};

    int size = sizeof(coins) / sizeof(int);

    int dp[n + 1] = {0};
    cout << Coin_Change_Top_Down(n, coins, size, dp);
    return 0;
}