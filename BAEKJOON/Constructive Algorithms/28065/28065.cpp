#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        cout << n - i << " ";
        cout << i + 1 << " ";
    }
    if (n % 2 == 1)
        cout << n / 2 + 1;
    cout << "\n";
    return 0;
}