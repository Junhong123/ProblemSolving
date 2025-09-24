#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    unsigned int n, k;

    cin >> k >> n;

    vector<int> v(k);
    ll max_len = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> v[i];

        if (v[i] > max_len)
            max_len = v[i];
    }

    ll start = 1;
    ll end = max_len;
    ll res = 0;

    while (start <= end)
    {
        ll mid = (start + end) / 2;
        ll sum = 0;

        for (auto val : v)
        {
            sum += val / mid;
        }

        if (sum >= n)
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