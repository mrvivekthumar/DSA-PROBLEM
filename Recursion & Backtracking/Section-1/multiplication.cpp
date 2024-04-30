#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int multiplication_with_recursion(int a, int b)
{
    // base case
    if (b == 0 or b == 1)
    {
        return a;
    }

    // rec case
    return a + multiplication_with_recursion(a, b - 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = multiplication_with_recursion(a, b);
    cout << ans;
    return 0;
}
