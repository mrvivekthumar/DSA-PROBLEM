#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    // base case
    if (n == 1 or n == 0)
    {
        return n;
    }

    // rec case
    return (fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}