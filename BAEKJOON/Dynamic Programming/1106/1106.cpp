#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second;
    vector<int> dp(c + 101, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = items[i].first;
        int people = items[i].second;

        for (int j = people; j < c + 101; j++)
        {
            if (dp[j - people] != 1e9)
            {
                dp[j] = min(dp[j - people] + cost, dp[j]);
            }
        }
    }

    int ans = 1e9;
    for (int i = c; i < c + 101; i++)
        ans = min(dp[i], ans);

    cout << ans;

    return 0;
}