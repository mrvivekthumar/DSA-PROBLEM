#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_sorted_Array(int a[], int n)
{
    // base case
    if (n == 0)
    {
        return true;
    }

    // rec case
    if (a[0] < a[1] & is_sorted_Array(a + 1, n - 1))
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {0, 1, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << is_sorted_Array(arr, n - 1) << endl;

    return 0;
}