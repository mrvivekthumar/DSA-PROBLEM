// # PRINT THE NUMBER
// You are given a integer number you have to print the number in the form of character
// EXAMPLE : 203  = two zero three

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
char c[][10] = {"zero", "one", "Two", "three", "four", "five", "six", "seven", "eight", "nine"};
void print_numbers(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // rec case
    print_numbers(n / 10);
    int digit = n % 10;
    cout << c[digit] << "   ";
    return;
}
void Print_numbers(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // rec case
    int digit = n % 10;
    cout << c[digit] << "   ";
    Print_numbers(n / 10);
    return;
}

int main()
{
    int n;
    cin >> n;
    print_numbers(n);
    cout << endl;
    Print_numbers(n);
    return 0;
}
