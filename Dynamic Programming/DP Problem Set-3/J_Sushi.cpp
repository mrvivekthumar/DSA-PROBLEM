#include <bits/stdc++.h>
using namespace std;
bool Done(vector<int> &v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (v[i] != 0)
        {
            return 0;
        }
        return 1;
    }
};

int J_Sushi(vector<int> &v, int n)
{
    if (Done(v, n))
    {
        return 0;
    }
    else
    {
        int dish = (rand() % n) + 1;
        v[dish] = max(0, v[dish] - 1);
        return 1 + J_Sushi(v, n);
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> dishes(n + 1), temp(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> dishes[i];
        temp[i] = dishes[i];
    }

    double total = 0;
    int conduct_exp = 1000;
    for (int i = 1; i <= conduct_exp; i++)
    {
        total += J_Sushi(dishes, n);
        dishes = temp;
    }

    cout << total / conduct_exp;
    return 0;
}