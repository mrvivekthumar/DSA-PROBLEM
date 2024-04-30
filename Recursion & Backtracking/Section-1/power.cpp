#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int power_reccursion(int a, int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a;
    }
    // rec case
    return a * power_reccursion(a, n - 1);
}

int main()
{
    int a, n;
    cin >> a >> n;

    int ans = power_reccursion(a, n);
    cout << ans;
}
