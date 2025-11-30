#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    long long cur;
    cin >> n >> k;
    vector<long long> dp(n + 1, 0);
    vector<long long> pre_sum(n + 1, 0);

    deque<pair<long long, int>> dq;
    dq.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        pre_sum[i] = pre_sum[i - 1] + cur;
        long long value = dp[i - 1] - pre_sum[i];
        while (!dq.empty() && dq.back().first < value)
            dq.pop_back();
        dq.push_back({value, i});
        if (dq.front().second < i - k)
            dq.pop_front();
        dp[i] = max(dp[i - 1], pre_sum[i] + dq.front().first);
    }

    cout << dp[n] << "\n";

    return 0;
}