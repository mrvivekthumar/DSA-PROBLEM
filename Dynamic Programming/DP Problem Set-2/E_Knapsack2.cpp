#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 1e9 + 1
using namespace std;

struct item
{
    int wt;
    int val;
};

int D_Knapsack(vector<item> ar, int n, int W)
{

    int maxVal = n * 1000;
    // first dimension of the dp represent the 'i'th item
    // second dimensin of the dp represent the value of the knapsack weight
    ll dp[n + 1][maxVal + 1];

    for (int val = 0; val <= maxVal; val++)
    {
        dp[1][val] = inf;
    }

    dp[1][0] = 0;
    dp[1][ar[1].val] = ar[1].wt;

    for (int i = 2; i <= n; i++)
    {
        for (int v = 0; v <= maxVal; v++)
        {
            dp[i][v] = dp[i - 1][v];
            if (ar[i].val <= v)
            {
                dp[i][v] = max(dp[i][v], ar[i].val + dp[i - 1][v - ar[i].val]);
            }
        }
    }

    int ans = 0;

    for (int x = 0; x <= maxVal; x++)
    {
        if (dp[n][x] = W)
        {
            ans = x;
        }
    }

    return ans;
};

int main()
{
    int n, w;
    cin >> n >> w;
    vector<item> ar(n + 1);

    // one '1' base indexing
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i].wt >> ar[i].val;
    }

    cout << D_Knapsack(ar, n, w);

    return 0;
}