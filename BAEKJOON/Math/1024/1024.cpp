#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, l;
    cin >> n >> l;
    for (int k = l; k <= 100; ++k)
    {
        long long tmp = n - (1LL * k * (k - 1) / 2);

        if (tmp >= 0 && tmp % k == 0)
        {
            long long x = tmp / k;

            for (int i = 0; i < k; ++i)
                cout << x + i << " ";
            return 0;
        }
    }

    cout << -1;

    return 0;
}