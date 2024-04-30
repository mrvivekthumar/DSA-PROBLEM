#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort_recursion(int a[], int n)
{
    // base case
    if (n == 1)
    {
        return;
    }

    // rec case
    // first move gratest element to the end of the array and then do recursive call for (n-1) elemnt''s
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }
    bubbleSort_recursion(a, n - 1);
}

int main()
{

    int arr[] = {9, 9, 9, 34, 23, 21, 21, 33, 45, 332, 1, 3, 5, 9, 6, 4, 4, 5, 6, 7, 8, 91, 2, 3};

    int n = sizeof(arr) / sizeof(int);

    bubbleSort_recursion(arr, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "	";
    }
    return 0;
}
