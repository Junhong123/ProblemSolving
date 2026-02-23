#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    int p = (y * 100) / x;
    int first = p;
    if (p >= 99)
    {
        cout << -1;
        return 0;
    }
    long long res;
    long long mid;
    long long high = 2000000000;
    long long low = 0;
    while (low <= high)
    {
        mid = (high + low) / 2;
        p = ((y + mid) * 100) / (x + mid);
        if (first < p)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << res;

    return 0;
}