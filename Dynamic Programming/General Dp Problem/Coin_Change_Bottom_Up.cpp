#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Coin_Change_Bottom_Up(int N, int coins[], int size)
{

    int dp[N + 1] = {0};

    // n is the money
    for (int n = 1; n <= N; n++)
    {
        dp[n] = INT_MAX;

        // i is the number of coins
        for (int i = 0; i < size; i++)
        {
            if (n - coins[i] >= 0)
            {
                int subProblem = dp[n - coins[i]];
                dp[n] = min(dp[n], subProblem + 1);
            }
        }
    }

    return dp[N];
}

int main()
{
    int money;
    cin >> money;
    int coins[] = {1, 5, 10};
    int size = sizeof(coins) / sizeof(int);
    cout << Coin_Change_Bottom_Up(money, coins, size);
    return 0;
}