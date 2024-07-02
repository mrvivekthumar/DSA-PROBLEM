#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define prDouble(x) cout << fixed << setprecision(10) << x

double dp[3001][3001];

double I_Coins(vector<double> &ar, int i, int heads)
{
    if (heads == 0)
    {
        return 1;
    }
    if (i == 0)
    {
        return 0;
    }

    if (dp[i][heads] > -0.9)
    {
        return dp[i][heads];
    }

    return dp[i][heads] = (ar[i] * I_Coins(ar, i - 1, heads - 1) + (1 - ar[i]) * I_Coins(ar, i - 1, heads));
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    vector<double> ar(n + 1);
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> ar[i];
    }
    prDouble(I_Coins(ar, n, (n + 1) / 2));

    return 0;
}