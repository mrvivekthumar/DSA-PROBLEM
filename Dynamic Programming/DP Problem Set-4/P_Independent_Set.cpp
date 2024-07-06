#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

vector<int> tree[100001];
ll dp[100001][2];

ll L_Independent_Set(int u, int constraint, int pr)
{
    ll ans = 0;
    ll way1 = 1;

    if (dp[u][constraint] != -1)
    {
        return dp[u][constraint];
    }

    for (int child : tree[u])
    {
        if (child != pr)
        {
            way1 = (way1 * L_Independent_Set(child, 0, u)) % mod;
        }
    }
    ans += way1;

    if (!constraint)
    {
        ll way2 = 1;
        for (int child : tree[u])
        {
            if (child != pr)
            {
                way2 = (way2 * L_Independent_Set(child, 1, u)) % mod;
            }
        }
        ans = (ans + way2) % mod;
    }

    return dp[u][constraint] = ans;
};

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << L_Independent_Set(1, 0, -1);

    return 0;
}