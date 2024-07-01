#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define prDouble(x) cout << fixed << setprecision(10) << x;

double dp[3001][3001];

double I_Coins(vector<double> &ar, int i, int heads)
{
    
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

    int ans = I_Coins(ar, n, (n + 1 / 2));
    prDouble(ans);

    cout << ans;

    return 0;
}