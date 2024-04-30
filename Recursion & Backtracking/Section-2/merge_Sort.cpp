#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = (mid + 1);
    int k = s;
    int temp[100] = {0};

    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // rec case
    int mid = (s + e) / 2;

    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 0, 5, 54, 3, 22, 34, 54, 32, 99, 88, 77, 66, 55433, 321, 23, 1111, 23, 12};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}