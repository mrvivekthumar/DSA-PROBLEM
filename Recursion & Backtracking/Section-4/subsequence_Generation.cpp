#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subsequence_Generation(char c[], char out[], int i, int j)
{
    // base case
    if (c[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // rec case
    // include the character
    out[j] = c[i];
    subsequence_Generation(c, out, i + 1, j + 1);

    // exclude the character
    subsequence_Generation(c, out, i + 1, j);

    return;
}

int main()
{
    char c[] = "abc";
    char out[10];
    subsequence_Generation(c, out, 0, 0);
    return 0;
}