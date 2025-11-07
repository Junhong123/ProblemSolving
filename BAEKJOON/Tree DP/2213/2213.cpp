#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> path;
vector<int> weight;

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = weight[u];
    for (auto &v : graph[u])
    {
        if (p == v)
            continue;
        dfs(v, u);
        if (dp[v][1] >= dp[v][0])
            dp[u][0] += dp[v][1];
        else
            dp[u][0] += dp[v][0];

        dp[u][1] += dp[v][0];
    }

    return;
}

void trace(int u, int p, int state)
{
    if (state)
    {
        path.emplace_back(u);
        for (auto &v : graph[u])
        {
            if (v == p)
                continue;
            trace(v, u, 0);
        }
    }
    else
    {
        for (auto &v : graph[u])
        {
            if (v == p)
                continue;
            if (dp[v][0] > dp[v][1])
                trace(v, u, 0);
            else
                trace(v, u, 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    cin >> n;
    weight.resize(n + 1);
    graph.resize(n + 1);
    dp.resize(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        cin >> weight[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(1, 0);

    if (dp[1][0] > dp[1][1])
    {
        cout << dp[1][0] << "\n";
        trace(1, 0, 0);
    }
    else
    {
        cout << dp[1][1] << "\n";
        trace(1, 0, 1);
    }

    sort(path.begin(), path.end());
    for (auto &ans : path)
        cout << ans << " ";
    cout << "\n";

    return 0;
}