#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void generate_string_from_numbers(char in[], char out[], int i, int j)
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
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generate_string_from_numbers(in, out, i + 1, j + 1);

    if (in[i + 1] != '\0')
    {
        int secondDigit = in[i + 1] - '0';
        int cnt = digit * 10 + secondDigit;
        if (cnt <= 26)
        {
            char ch = cnt + 'A' - 1;
            out[j] = ch;
            generate_string_from_numbers(in, out, i + 2, j + 1);
        }
    }
    return;
}

int main()
{
    char in[100];
    cin >> in;
    char out[100];

    generate_string_from_numbers(in, out, 0, 0);
    return 0;
}