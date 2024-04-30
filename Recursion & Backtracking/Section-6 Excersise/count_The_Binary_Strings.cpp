#include <iostream>
#define ll unsigned long long int
using namespace std;

ll countStrings(int n)
{
    ll a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = (ll)(a[i - 1] + b[i - 1]);
        b[i] = (ll)a[i - 1];
        cout << a[i] << "   " << b[i] << endl;
    }
    return (ll)(a[n - 1] + b[n - 1]);
}

// Driver program to test above functions
int main()
{

    int n;
    cin >> n;
    cout << countStrings(n) << endl;

    return 0;
}