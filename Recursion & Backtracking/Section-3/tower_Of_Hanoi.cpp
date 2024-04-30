#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int n, char src, char helper, char dest)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // rec case
    tower_of_hanoi(n - 1, src, dest, helper);
    cout << "Disk " << src << " moved to " << dest << endl;
    tower_of_hanoi(n - 1, helper, src, dest);
}

int main()
{
    int n;
    cin >> n;

    tower_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}