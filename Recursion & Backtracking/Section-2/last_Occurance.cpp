#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int last_occurance(int a[], int n, int key)
{
    // base case
    if (n == 0)
    {
        return -1;
    }

    // recc case
    int i = last_occurance(a + 1, n - 1, key);
    if (i == -1)
    {
        if (a[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    return i + 1;
}
int main()
{
    int a[] = {1, 7, 3, 6, 7, 9, 5, 6};
    int n = sizeof(a) / sizeof(int);
    int key;
    cin >> key;

    int ans = last_occurance(a, n, key);
    cout << ans << endl;
    return 0;
}
