// Road Cutting Problem

// N = 8

// Example 1
// length       |   1  2  3  4  5  6  7  8
// Price        |   1  5  8  9  10 17 17 20
// Max Profit   =   22

// Example 2
// length       |   1  2  3  4  5  6  7  8
// Price        |   3  5  8  9  10 17 17 20
// Max Profit   =   24

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Max_Profit(int prices[], int n)
{
    // Base case
    if (n <= 0)
    {
        return 0;
    }

    // Rec case
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;
        int subProblem = prices[i] + Max_Profit(prices, n - cut);
        ans = max(ans, subProblem);
    }
    return ans;
};
int Max_Profit_With_Dp() {};

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    cout << Max_Profit(prices, n);

    return 0;
}