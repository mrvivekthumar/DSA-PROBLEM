#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void permutation(char *in, int i, set<string> &s)
{
    // base case
    if (in[i] == '\0')
    {
        string s1(in);
        s.insert(s1);
        cout << in << endl;
        return;
    }

    // rec case
    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permutation(in, i + 1, s);
        // backtracking
        swap(in[i], in[j]);
    }
}
int main()
{
    char in[100];
    cin >> in;
    cout << endl;
    set<string> s;

    permutation(in, 0, s);
    cout << endl;
    cout << "Unique Strings are : ";
    for (auto str : s)
    {
        cout << str << "    ";
    }
    return 0;
}