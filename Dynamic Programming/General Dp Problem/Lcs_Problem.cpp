#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Lcs(string s1, string s2, int m, int n)
{
    // Base case
    if (m == s1.length() || n == s2.length())
    {
        return 0;
    }

    // Rec case
    if (s1[m] == s2[n])
    {
        return 1 + Lcs(s1, s2, m + 1, n + 1);
    }

    int option1 = Lcs(s1, s2, m, n + 1);
    int option2 = Lcs(s1, s2, m + 1, n);

    return max(option1, option2);
};

int Lcs_With_Dp(string s1, string s2, int m, int n, vector<vector<int>> &dp)
{
    // Base case
    if (m == s1.length() || n == s2.length())
    {
        return 0;
    }

    // Lookup for dp if already computed
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    // Rec case
    if (s1[m] == s2[n])
    {
        return dp[m][n] = 1 + Lcs(s1, s2, m + 1, n + 1);
    }

    int option1 = Lcs_With_Dp(s1, s2, m, n + 1, dp);
    int option2 = Lcs_With_Dp(s1, s2, m + 1, n, dp);

    return dp[m][n] = max(option1, option2);
};
int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";

    cout << Lcs(s1, s2, 0, 0) << endl;

    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1, vector<int>(n2, -1));

    cout << Lcs_With_Dp(s1, s2, 0, 0, dp) << endl;

    return 0;
}