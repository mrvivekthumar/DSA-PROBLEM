#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This is like convert in to for loop method.
void all_Occurance(int a[], int i, int n, int key)
{
    // base case
    if (i == n)
    {
        return;
    }

    // rec case
    if (a[i] == key)
    {
        cout << i << "  ";
    }

    all_Occurance(a, i + 1, n, key);
}

int main()
{
    int a[] = {1, 7, 3, 6, 7, 9, 5, 6};
    int n = sizeof(a) / sizeof(int);
    int key;
    cin >> key;

    all_Occurance(a, 0, n, key);
    return 0;
}
