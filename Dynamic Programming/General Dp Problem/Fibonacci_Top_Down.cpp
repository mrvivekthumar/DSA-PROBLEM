#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fib(int n, int dp[])
{
    // Base case
    if (n == 0 or n == 1)
    {
        return n;
    }

    // Look up if n is already computed then return otherwise rec case
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Recursive case
    int ans = fib(n - 1, dp) + fib(n - 2, dp);
    return (dp[n] = ans);
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};

    cout << fib(n, dp);

    return 0;
}

// NOTE : Top-down approach is the recursive approach with mamoziation

//  TOP-DOWN DYANAMIC PROGRAMMING = RECURSIVE + MEMOIZATION