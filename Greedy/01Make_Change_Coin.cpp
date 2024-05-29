#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int make_change_coin(int coins[], int n, int money)
{
    int ans = 0;
    while (money > 0)
    {
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        money -= coins[idx];
        ans++;
    }

    return ans;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500};
    int n = sizeof(coins) / sizeof(int);
    int money;
    cin >> money;
    cout << make_change_coin(coins, n, money);

    return 0;
}