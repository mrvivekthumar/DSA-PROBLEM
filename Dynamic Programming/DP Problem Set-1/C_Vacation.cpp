#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int A, B, C;
};

int C_Vacation(vector<activity> ar, int n)
{

    int dp[n + 1][3];

    dp[0][0] = ar[0].A;
    dp[0][1] = ar[0].B;
    dp[0][2] = ar[0].C;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = ar[i].A + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = ar[i].B + max(dp[i - 1][2], dp[i - 1][0]);
        dp[i][2] = ar[i].C + max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
};

int main()
{
    int n;
    cin >> n;
    vector<activity> ar(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].A;
        cin >> ar[i].B;
        cin >> ar[i].C;
    }

    cout << C_Vacation(ar, n);

    return 0;
}