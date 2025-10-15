#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> mat(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        mat[i] = {r, c};
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (mat[i].first * mat[k].second * mat[j].second));
            }
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}