#include <bits/stdc++.h>
using namespace std;
#define inf 1ll << 60
#define ll long long

ll dp[3001][3001];
ll sum[3001][3001];
ll N_Slimes(vector<ll> &v, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    ll minCost = inf;
    for (int k = i; k < j; k++)
    {
        minCost = min(minCost, sum[i][j] + N_Slimes(v, i, k) + N_Slimes(v, k + 1, j));
    }

    return dp[i][j] = minCost;
};

void preProcess(vector<ll> &v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j - 1]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    preProcess(v, n);
    cout << N_Slimes(v, 1, n);

    return 0;
}