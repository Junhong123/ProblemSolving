#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> v(n);
    ll max_len = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] > max_len)
            max_len = v[i];
    }

    ll start = 0;
    ll end = max_len;
    ll res = 0;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        ll sum = 0;
        for (auto val : v)
        {
            if (val > mid)
                sum += val - mid;
        }
        if (sum >= m)
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