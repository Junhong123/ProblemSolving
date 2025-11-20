#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == k)
        cout << "Impossible\n";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i > n - k)
                cout << i << " ";
            else if (i == 1)
                cout << n - k << " ";
            else
                cout << i - 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}