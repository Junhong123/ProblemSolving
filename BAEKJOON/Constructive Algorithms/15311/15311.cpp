#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ones = 1000;
    if (n <= 1000)
        ones = n;
    int big_val = ones + 1;
    int bigs = 0;

    if (n > ones)
    {
        int needed = n - ones;
        bigs = (needed + big_val - 1) / big_val;
    }

    cout << ones + bigs << "\n";
    for (int i = 0; i < ones; i++)
    {
        cout << "1 ";
    }
    for (int i = 0; i < bigs; i++)
    {
        cout << big_val << " ";
    }

    cout << "\n";

    return 0;
}