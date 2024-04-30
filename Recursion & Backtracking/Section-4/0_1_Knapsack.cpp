#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int pro[], int capacity, int n)
{
    // base case
    if (capacity == 0 || n == 0)
    {
        return 0;
    }

    // rec case
    int include = INT16_MIN;
    int exclude = INT16_MIN;
    if (capacity >= wt[n - 1])
    {
        include = pro[n - 1] + knapsack(wt, pro, capacity - wt[n - 1], n - 1);
    }
    exclude = knapsack(wt, pro, capacity, n - 1);

    int maximum = max(include, exclude);

    return maximum;
}
int main()
{
    int capacity;
    cin >> capacity;
    int weight[] = {6, 3, 10, 9, 2};
    int profit[] = {100, 120, 100, 150, 40};
    int n = sizeof(weight) / sizeof(int);

    cout << knapsack(weight, profit, capacity, n);
    return 0;
}