// #PLACE THE TILES
// -------------------------------------------------------------------
// Given a wall of size of 4 X N, and tiles of size(1, 4) and (4, 1).
// In how many ways you can build the wall ?

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int placing_the_tiles(int n)
{
    // base case
    if (n <= 3)
    {
        return 1;
    }
    // rec case
    int ans = placing_the_tiles(n - 1) + placing_the_tiles(n - 4);

    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << placing_the_tiles(n) << endl;
    return 0;
}
