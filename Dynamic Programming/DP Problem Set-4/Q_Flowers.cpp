#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000000007

struct flower
{
    ll hi;
    ll bty;
};

ll Q_Flower(vector<flower> &v, int n)
{
    vector<ll> dp(n + 1);
    map<ll, ll> meaningful;
    dp[1] = v[1].bty;
    meaningful[v[1].hi] = dp[1];
    ll ans = dp[1];

    for (int i = 2; i <= n; i++)
    {
        auto it = meaningful.lower_bound(v[i].hi + 1);
        if (it != meaningful.begin())
        {
            it--;
            dp[i] += it->second;
        }

        meaningful[v[i].hi] = dp[i];

        it = meaningful.upper_bound(v[i].hi);

        while (it != meaningful.end() && it->second <= dp[i])
        {
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it = temp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
};

int main()
{
    int n;
    cin >> n;
    vector<flower> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].hi;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].bty;
    }

    cout << Q_Flower(v, n);

    return 0;
}