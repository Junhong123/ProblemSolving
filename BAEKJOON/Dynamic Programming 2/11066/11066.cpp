#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, j;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
            dp[i][i] = 0;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                j = i + len - 1;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
    return 0;
}