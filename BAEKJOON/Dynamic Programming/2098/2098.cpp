#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;
int N;
int W[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visited)
{
    if (visited == ((1 << N) - 1))
    {
        if (W[cur][0] != 0)
            return W[cur][0];
        else
            return INF;
    }

    if (dp[cur][visited] != -1)
        return dp[cur][visited];

    dp[cur][visited] = INF;

    for (int nxt = 0; nxt < N; ++nxt)
    {
        if ((visited & (1 << nxt)) || W[cur][nxt] == 0)
            continue;

        dp[cur][visited] = min(dp[cur][visited], W[cur][nxt] + dfs(nxt, visited | (1 << nxt)));
    }

    return dp[cur][visited];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> W[i][j];

    fill(&dp[0][0], &dp[0][0] + 16 * (1 << 16), -1);

    cout << dfs(0, 1);

    return 0;
}