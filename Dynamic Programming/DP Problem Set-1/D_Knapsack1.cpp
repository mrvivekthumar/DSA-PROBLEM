#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct item
{
    ll wt;
    ll val;
};

ll D_Knapsack(vector<item> ar, ll n, ll W)
{

    // first dimension of the dp represent the 'i'th item
    // second dimensin of the dp represent the wt of the knapsack
    ll dp[n + 1][W + 1];

    for (ll w = 0; w <= W; w++)
    {
        dp[1][w] = 0;
    }

    dp[1][ar[1].wt] = ar[1].val;

    for (ll i = 2; i <= n; i++)
    {
        for (ll w = 0; w <= W; w++)
        {
            dp[i][w] = dp[i - 1][w];
            if (ar[i].wt <= w)
            {
                dp[i][w] = max(dp[i][w], ar[i].val + dp[i - 1][w - ar[i].wt]);
            }
        }
    }

    return *max_element(dp[n], dp[n] + W + 1);
};

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<item> ar(n + 1);

    // one '1' base indexing
    for (ll i = 1; i <= n; i++)
    {
        cin >> ar[i].wt >> ar[i].val;
    }

    cout << D_Knapsack(ar, n, w);

    return 0;
}