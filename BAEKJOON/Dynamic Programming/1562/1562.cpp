#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000000;

int dp[101][10][1024];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= 9; ++i)
        dp[1][i][1 << i] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 1024; ++k)
            {
                if (dp[i][j][k] == 0)
                    continue;

                if (j - 1 >= 0)
                {
                    int next_num = j - 1;
                    int next_mask = k | (1 << next_num);
                    dp[i + 1][next_num][next_mask] = (dp[i][j][k] + dp[i + 1][next_num][next_mask]) % MOD;
                }

                if (j + 1 < 10)
                {
                    int next_num = j + 1;
                    int next_mask = k | (1 << next_num);
                    dp[i + 1][next_num][next_mask] = (dp[i][j][k] + dp[i + 1][next_num][next_mask]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j <= 9; ++j)
        ans = (ans + dp[N][j][1023]) % MOD;

    cout << ans;

    return 0;
}