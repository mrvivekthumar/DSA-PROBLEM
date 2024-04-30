#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// efficient and no more call on stack. so no more space;
int power_reccursion(int a, int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // rec case
    int ans = power_reccursion(a, n / 2);
    ans *= ans;

    if (n & 1)
    {
        return ans * a;
    }
    return ans;
}

int main()
{
    int a, n;
    cin >> a >> n;

    int ans = power_reccursion(a, n);
    cout << ans;
}
