#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    ll n = A.size();
    vector<vector<ll>> resultMatrix(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                resultMatrix[i][j] = (resultMatrix[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return resultMatrix;
};

vector<vector<ll>> power(vector<vector<ll>> mat, ll exp)
{
    if (exp == 1)
    {
        return mat;
    }
    vector<vector<ll>> res = power(mat, exp / 2);

    if (exp & 1)
    {
        return multiply(multiply(mat, res), res);
    }
    else
    {
        return multiply(res, res);
    }
}

ll R_Walk(vector<vector<ll>> &adj, ll k, int n)
{
    vector<vector<ll>> ak = power(adj, k);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = (ans + ak[i][j]) % mod;
        }
    }
    return ans;
};

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<ll>> adj(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << R_Walk(adj, k, n);

    return 0;
}