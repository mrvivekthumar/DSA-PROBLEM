#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct activity
{
    int wt;
    int val;
};

ll D_Knapsack(vector<activity> ar, int n, int W) {

};

int main()
{
    int n, w;
    cin >> n >> w;
    vector<activity> ar(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].wt >> ar[i].val;
    }

    cout << D_Knapsack(ar, n, w);

    return 0;
}