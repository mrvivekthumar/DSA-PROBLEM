// link = "https://atcoder.jp/contests/dp/tasks/dp_a"

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define inf 1e9
int A_Frog_1(vector<int> ar, int n)
{
    vector<int> dp(n + 1);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int option1 = abs(ar[i] - ar[i - 1]) + dp[i - 1];
        int option2 = (i == 1) ? inf : abs(ar[i] - ar[i - 2]) + dp[i - 2];
        dp[i] = min(option1, option2);
    }
    return dp[n - 1];
};

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cout << A_Frog_1(ar, n);
    return 0;
}
