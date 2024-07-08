// #COUNT BINARY STRINGS
// Count binary strings of lenght N, which have no consecutive once ?.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_binary_strings(string c[][3], int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    // rec case
    int ans = 0;

    return count_binary_strings(c, n - 1);
}
int main()
{
    int n;
    cin >> n;
    string c[1000][3];
    cout << count_binary_strings(c, n);
    return 0;
}
