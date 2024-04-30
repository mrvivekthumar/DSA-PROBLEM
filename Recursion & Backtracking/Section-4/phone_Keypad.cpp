#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char keypaid[][10] = {"", "", "ABC", "DEF", "GHI", "IJK", "JKL", "LMN", "OPQ", "RST", "UVW", "XYZ"};
void generate_PhonekeyPaid_names(char *in, char *out, int i, int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // rec case

    int digit = in[i] - '0';
    if (digit == 0 || digit == 1)
    {
        generate_PhonekeyPaid_names(in, out, i + 1, j);
    }
    for (int k = 0; keypaid[digit][k] != '\0'; k++)
    {
        out[j] = keypaid[digit][k];
        generate_PhonekeyPaid_names(in, out, i + 1, j + 1);
    }
    return;
}
int main()
{
    char in[100];
    cin >> in;
    cout << endl;
    char out[100];

    generate_PhonekeyPaid_names(in, out, 0, 0);
    return 0;
}