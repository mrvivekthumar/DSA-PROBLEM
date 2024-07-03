// Problem link : "https://www.spoj.com/problems/BAISED/"
#include <iostream>
#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int abs(int i, int j)
{
    if (i - j > 0)
    {
        return i - j;
    }
    return j - i;
}

int main()
{
    int arr[10000] = {0};
    int t;
    cin >> t;

    while (t--)
    {
        memset(arr, 0, sizeof arr);
        string name;
        int n, rank;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> name >> rank;
            arr[rank]++;
        }

        int actual_Rank = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                sum += abs(actual_Rank, i);
                arr[i]--;
                actual_Rank++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}