#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int string_to_int(char c[], int e)
{
    // bae case
    if (e == 0)
    {
        return 0;
    }
    // rec case
    int digit = c[e - 1] - '0';
    int ans = string_to_int(c, e - 1);

    ans = ans * 10 + digit;

    return ans;
}
int main()
{
    char c[] = "1234";
    cout << string_to_int(c, 4) << " ";
    return 0;
}