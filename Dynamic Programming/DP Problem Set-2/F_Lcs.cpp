#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 3000

int dp[MAX + 1][MAX + 1];

string getLcs(string &s, string &t, int len)
{

    string Lcs;
    int i = 0, j = 0;

    while (len > 0)
    {
        if (s[i] == t[j])
        {
            Lcs.push_back(s[i]);
            i++;
            j++;
            len--;
        }
        else
        {
            if (dp[i][j + 1] > dp[i + 1][j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return Lcs;
};
int getLengthLcs(string &s, string &t, int i, int j)
{
    if (i >= s.length() || j >= t.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        return dp[i][j] = 1 + getLengthLcs(s, t, i + 1, j + 1);
    }
    else
    {
        return dp[i][j] = max(getLengthLcs(s, t, i + 1, j), getLengthLcs(s, t, i, j + 1));
    }
};

string F_Lcs(string s, string t)
{
    memset(dp, -1, sizeof dp);
    int len = getLengthLcs(s, t, 0, 0);
    return getLcs(s, t, len);
};
int main()
{
    string s, t;
    cin >> s >> t;
    cout << F_Lcs(s, t);
    return 0;
}