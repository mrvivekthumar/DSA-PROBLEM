#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Ladders_Top_Down(int n, int k, int dp[])
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    // Lookup for already computed values
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Rec case
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {

            ans += Ladders_Top_Down(n - i, k, dp);
        }
    }
    dp[n] = ans;
    return ans;
};

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[n + 1] = {0};
    cout << Ladders_Top_Down(n, k, dp);
    return 0;
}