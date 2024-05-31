#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// n -> n/3, n -> 2, n -> n-1

int Minimum_Steps_Bottom_Up(int n)
{

    int dp[n + 1];
    // Base case
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int option1 = INT_MAX, option2 = INT_MAX, option3 = INT_MAX;

        if (n % 3 == 0)
        {
            option1 = dp[i / 3];
        }
        if (n % 2 == 0)
        {
            option2 = dp[i / 2];
        }
        option3 = dp[i - 1];

        dp[i] = min(min(option1, option2), option3) + 1;
    }

    return dp[n];
}

int Minimum_Steps_Top_Down(int n, int dp[])
{

    // Base case
    if (n == 1)
    {
        return 0;
    }

    // Look up for an already computed n if exist
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Recursive case
    int option1, option2, option3;
    option1 = option2 = option3 = INT_MAX;

    if (n % 3 == 0)
    {
        option1 = Minimum_Steps_Top_Down(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        option2 = Minimum_Steps_Top_Down(n / 2, dp) + 1;
    }
    option3 = Minimum_Steps_Top_Down(n - 1, dp) + 1;

    int ans = min(min(option1, option2), option3);

    dp[n] = ans;

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << Minimum_Steps_Top_Down(n, dp) << endl;
    cout << Minimum_Steps_Bottom_Up(n) << endl;

    return 0;
}
