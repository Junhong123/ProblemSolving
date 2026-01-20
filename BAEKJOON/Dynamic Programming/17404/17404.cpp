#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int ans = 1e9;

    for (int StartColor = 0; StartColor < 3; ++StartColor)
    {
        fill(dp.begin(), dp.end(), vector<int>(3, 1e9));
        dp[0][StartColor] = cost[0][StartColor];

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
        }
        for (int i = 0; i < 3; ++i)
            if (i != StartColor)
                ans = min(ans, dp[n - 1][i]);
    }

    cout << ans;

    return 0;
}