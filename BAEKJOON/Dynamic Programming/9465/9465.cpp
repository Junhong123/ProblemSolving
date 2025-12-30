#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<vector<int>> arr(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        for (int i = 1; i < n; i++)
        {
            if (i > 1)
            {
                dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
                dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
            }
            else
            {
                dp[0][i] = dp[1][i - 1] + arr[0][i];
                dp[1][i] = dp[0][i - 1] + arr[1][i];
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}