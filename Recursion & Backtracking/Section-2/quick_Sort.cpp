#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int partitation(int a[], int s, int e)
{
    int pivot = a[e];
    int i = s - 1;
    int j = s;
    for (int j = s; j < e; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);

    return i + 1;
}
void quicksort(int a[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // rec case
    int p = partitation(a, s, e);
    quicksort(a, s, p - 1);
    quicksort(a, p + 1, e);
}

int main()
{
    int arr[] = {54, 7, 4, 3, 33, 4, 5, 9, 6, 4, 3, 2, 4, 56, 7, 9};
    int n = sizeof(arr) / sizeof(int);

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
