#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll dp[10001][101][2];

ll S_Digit_Sum(string &k, int &D, int pos, int d, bool tight)
{
    if (dp[pos][d][tight] != -1)
    {
        return dp[pos][d][tight];
    }

    int ub = (tight) ? (k[pos] - '0') : 9;

    if (pos == k.length() - 1)
    {
        ll ans = 0;
        for (int x = 0; x <= ub; x++)
            if (x % D == d)
            {
                ans++;
            }
        return ans;
    }
    ll ans = 0;
    for (int x = 0; x <= ub; x++)
    {
        ans = (ans + S_Digit_Sum(k, D, pos + 1, (D + d - x % D) % D, tight && (x == ub))) % mod;
    }
    return dp[pos][d][tight] = ans;
};

int main()
{
    int D;
    string k;
    cin >> k;
    cin >> D;
    memset(dp, -1, sizeof dp);
    cout << S_Digit_Sum(k, D, 0, 0, 1);

    return 0;
}