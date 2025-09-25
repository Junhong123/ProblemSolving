#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, c;

    cin >> n >> c;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll start = 1;
    ll end = v[n - 1];
    ll res = 0;

    while (start <= end)
    {
        ll mid = (start + end) / 2;
        int preset = v[0];
        ll sum = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - preset >= mid)
            {
                sum++;
                preset = v[i];
            }
        }
        if (sum >= c)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << res << "\n";

    return 0;
}