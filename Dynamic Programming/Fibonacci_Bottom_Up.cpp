#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fib(int n, int dp[])
{
    // Base case
    if (n == 0 or n == 1)
    {
        return n;
    }

    // Recursive case
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibWithSpaceOptimization(int n)
{
    if (n == 0 or n == 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    int n;
    cin >> n;

    int dp[n + 1] = {0};

    cout << fib(n, dp) << endl;
    cout << fibWithSpaceOptimization(n) << endl;

    return 0;
}