#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[22][(1 << 22)];
ll O_Matching(vector<vector<int>> &compat, int i, int womenSubset, int N)
{
    if (i == N + 1)
    {
        if (womenSubset == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][womenSubset] != -1)
    {
        return dp[i][womenSubset];
    }

    ll ans = 0;
    for (int women = 0; women < N; women++)
    {
        bool available = (((1 << women) & (womenSubset)) == 0) ? 0 : 1;

        if (available && compat[i][women + 1])
        {
            ans = (ans + O_Matching(compat, i + 1, womenSubset ^ (1 << women), N)) % mod;
        }
    }
    return dp[i][womenSubset] = ans;
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> compat(n + 1, vector<int>(n + 1));
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> compat[i][j];
        }
    }

    cout << O_Matching(compat, 1, ((1 << (n)) - 1), n);

    return 0;
}