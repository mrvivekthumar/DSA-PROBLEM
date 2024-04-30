#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void replace_pi_with_3_14(char c[], int i)
{
    // base case
    if (c[i] == '\0' || c[i + 1] == '\0')
    {
        return;
    }
    // rec case
    if (c[i] == 'p' && c[i + 1] == 'i')
    {
        int j = i + 2;
        while (c[j] != '\0')
        {
            j++;
        }
        while (j >= i)
        {
            c[j + 2] = c[j];
            j--;
        }
        c[i] = '3';
        c[i + 1] = '.';
        c[i + 2] = '1';
        c[i + 3] = '4';
    }
    replace_pi_with_3_14(c, i + 1);
    return;
}
int main()
{
    char c[100] = {'x', 'p', 'i', 'g', 'h', 'p', 'i', 'w', 'e', 'p', 'i', 'p', 'i'};
    replace_pi_with_3_14(c, 0);
    cout << c;
    return 0;
}