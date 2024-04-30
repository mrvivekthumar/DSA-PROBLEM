#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int friends_pairing_problem(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // rec case
    int ans = 0;
    ans = 1 * friends_pairing_problem(n - 1) + (n - 1) * friends_pairing_problem(n - 2);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << friends_pairing_problem(n);
    return 0;
}
