#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n / 2; i > 0; i--)
        cout << i << " " << i + n / 2 << " ";
    if (n % 2 == 1)
        cout << n;
    cout << "\n";
    return 0;
}