#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void generate_Bracate(char *out, int i, int n, int open, int close)
{
    // base case
    if (i == 2 * n)
    {
        out[i] = '\0';
        cout << out << endl;
    }

    // rec case
    if (open < n)
    {
        out[i] = '(';
        generate_Bracate(out, i + 1, n, open + 1, close);
    }
    if (close < open)
    {
        out[i] = ')';
        generate_Bracate(out, i + 1, n, open, close + 1);
    }
    return;
}
int main()
{
    int n;
    cin >> n;

    char out[1000];
    generate_Bracate(out, 0, n, 0, 0);
    return 0;
}