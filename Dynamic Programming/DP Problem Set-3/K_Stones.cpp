#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string K_Stones(vector<int> &v, int k)
{
    bool dp[k + 1];

    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= k; i++)
    {
        for (int move : v)
        {
            if (move > i)
            {
                continue;
            }
            if (dp[i - move] == 0)
            {
                dp[i] = 1;
            }
        }
    }
    return dp[k] ? "First" : "Second";
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << K_Stones(v, k);
    return 0;
}