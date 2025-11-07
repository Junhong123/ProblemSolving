#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;

const int INF = 1e9;

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = 1;

    if (graph[u].size() == 1 && p != 0)
    {
        return;
    }

    for (auto &v : graph[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    cin >> n;
    graph.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));
    while (--n)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(1, 0);

    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}