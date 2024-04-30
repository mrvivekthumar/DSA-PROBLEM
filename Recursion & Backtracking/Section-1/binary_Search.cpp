#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch_recursion(int a[], int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    // base case
    if (a[mid] == key)
    {
        return mid;
    }

    // rec case
    if (key > a[mid])
    {
        return binarySearch_recursion(a, mid + 1, end, key);
    }
    else
    {
        return binarySearch_recursion(a, start, mid - 1, key);
    }

    return -1;
}
int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 77};
    int n = sizeof(arr) / sizeof(int);
    int x;
    cin >> x;

    int ans = binarySearch_recursion(arr, 0, n - 1, x);
    cout << ans;
}
