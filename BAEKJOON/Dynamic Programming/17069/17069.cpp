#include <bits/stdc++.h>

using namespace std;

long long dp[33][33][3];
int arr[33][33];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j + 1 <= n && arr[i][j + 1] == 0)
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][1];
            if (i + 1 <= n && arr[i + 1][j] == 0)
                dp[i + 1][j][2] += dp[i][j][1] + dp[i][j][2];
            if (i + 1 <= n && j + 1 <= n && arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0)
                dp[i + 1][j + 1][1] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }
    }

    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

    return 0;
}