#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Ladders_Bottom_Up(int n, int k)
{

    int dp[n + 1] = {0};

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[n];
};
int main()
{
    int n, k;
    cin >> n >> k;
    cout << Ladders_Bottom_Up(n, k);
    return 0;
}