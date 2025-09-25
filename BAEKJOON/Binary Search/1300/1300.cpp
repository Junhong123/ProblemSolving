#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, m;

    cin >> n >> m;

    int start = 1;
    int end = m;
    int ans = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        ll sum = 0;

        for (int i = 1; i <= n; i++)
        {
            sum += min(n, mid / i);
        }

        if (sum >= m)
        {
            end = mid - 1;
            ans = mid;
        }
        else if (sum < m)
        {
            start = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}