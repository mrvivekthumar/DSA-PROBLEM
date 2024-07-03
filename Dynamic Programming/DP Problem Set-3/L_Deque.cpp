#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3001][3001][2];

ll L_Deque(vector<int> &v, int i, int j, bool turn)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j][turn] != -1)
    {
        return dp[i][j][turn];
    }
    if (turn == 1)
    {
        return dp[i][j][turn] = max(v[i] + L_Deque(v, i + 1, j, 0), v[j] + L_Deque(v, i, j - 1, 0));
    }
    else
    {
        return dp[i][j][turn] = min(L_Deque(v, i + 1, j, 1), L_Deque(v, i, j - 1, 1));
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    memset(dp, -1, sizeof dp);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    ll scoreX = L_Deque(v, 1, n, 1);
    ll scoreY = (sum - scoreX);
    cout << scoreX - scoreY;

    return 0;

    return 0;
}