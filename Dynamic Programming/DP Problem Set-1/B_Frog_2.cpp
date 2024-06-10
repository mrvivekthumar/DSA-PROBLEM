#include <iostream>
#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int B_Frog_2(vector<int> ar, int n, int k)
{
    vector<int> dp(n + 1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = inf;
        for (int j = i - 1; j >= 0 && i - j <= k; j--)
        {
            dp[i] = min(dp[i], abs(ar[i] - ar[j]) + dp[j]);
        }
    }
    return dp[n - 1];
};
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ar(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << B_Frog_2(ar, n, k);

    return 0;
}