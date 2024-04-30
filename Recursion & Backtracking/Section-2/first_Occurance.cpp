#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int First_occurance(int a[], int n, int key)
{
    // base case
    if (n == 0)
    {
        return -1;
    }

    // recc case
    if (a[0] == key)
    {
        return 0;
    }

    int i = First_occurance(a + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }

    return i + 1;
}

// This is like convert in to for loop method.
int first_Occurance(int a[], int i, int n, int key)
{
    // base case
    if (i == n)
    {
        return -1;
    }

    // rec case
    if (a[i] == key)
    {
        return i;
    }

    first_Occurance(a, i + 1, n, key);
}

int main()
{
    int a[] = {1, 7, 3, 6, 7, 9, 5, 6};
    int n = sizeof(a) / sizeof(int);
    int key;
    cin >> key;

    int ans1 = first_Occurance(a, 0, n, key);
    int ans2 = First_occurance(a, n, key);
    cout << ans1 << "	" << ans2 << endl;
    return 0;
}
