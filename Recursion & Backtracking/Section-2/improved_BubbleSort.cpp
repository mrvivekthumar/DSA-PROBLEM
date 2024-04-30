#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void improved_bubbleSort_recursion(int a[], int j, int n)
{
    // base case
    if (n == 1)
    {
        return;
    }

    if (j == n)
    {
        return improved_bubbleSort_recursion(a, 0, n - 1);
    }

    // rec case
    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }
    improved_bubbleSort_recursion(a, j + 1, n);
    return;
}

int main()
{

    int arr[] = {9, 9, 9, 34, 23, 21, 21, 33, 45, 332, 8, 91, 2, 3};

    int n = sizeof(arr) / sizeof(int);

    improved_bubbleSort_recursion(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "	";
    }
    return 0;
}
