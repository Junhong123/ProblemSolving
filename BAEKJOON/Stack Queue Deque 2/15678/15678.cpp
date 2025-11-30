#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    deque<pair<ll, int>> dq;
    ll ans = -INF;

    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front().second < i - d)
            dq.pop_front();

        ll prev_max = dq.empty() ? 0 : dq.front().first;
        ll cur = arr[i] + max(0LL, prev_max);

        ans = max(ans, cur);

        while (!dq.empty() && dq.back().first <= cur)
            dq.pop_back();
        dq.push_back({cur, i});
    }

    cout << ans << "\n";

    return 0;
}