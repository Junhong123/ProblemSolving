#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<int> path(n + 1);
    dp[1] = 0;
    path[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        path[i] = i - 1;
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            path[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            path[i] = i / 2;
        }
    }

    cout << dp[n] << "\n";
    int cur = n;
    while (cur != 0)
    {
        cout << cur << " ";
        cur = path[cur];
    }
    cout << "\n";
    return 0;
}