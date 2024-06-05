#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Maximum_Subarray_Sum(int arr[], int n)
{
    int dp[n + 1] = {0};
    int Max = 0;
    dp[0] = arr[0] > 0 ? arr[0] : 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        Max = max(Max, dp[i]);
    }

    return Max;
};

// This is called Kadane's Algorithem
int Maximum_Subarray_Sum_With_Space_Optimized(int arr[], int n)
{
    int Max = 0;
    int current_sum = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        if (current_sum < 0)
        {
            current_sum = 0;
        }
        Max = max(Max, current_sum);

        // Special case If all elements of  Array contins negative value then return smallest negative element
        if (Max == 0 && i == n - 1)
        {
            sort(arr, arr + n);
            return arr[n - 1];
        }
    }

    return Max;
};
int main()
{
    int arr[] = {-3, -1, -2, -5, -32, -4, 3, 4, 5, 6, 4, 23, 1};
    int n = sizeof(arr) / sizeof(int);

    cout << Maximum_Subarray_Sum(arr, n) << endl;
    cout << Maximum_Subarray_Sum_With_Space_Optimized(arr, n);
    return 0;
}