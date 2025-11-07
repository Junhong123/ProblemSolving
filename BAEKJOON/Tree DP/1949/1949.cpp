#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> number;
vector<vector<int>> dp;

const int INF = 1e9;

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = -INF;
    dp[u][2] = number[u];

    int total_sum = 0;
    int min_diff = INF;
    bool all_choose_1 = true;

    for (auto &v : graph[u])
    {
        if (v == p)
            continue;

        dfs(v, u);

        dp[u][2] += dp[v][0];

        int not_selected = max(dp[v][2], dp[v][1]);
        total_sum += not_selected;

        if (dp[v][2] >= dp[v][1])
        {
            all_choose_1 = false;
        }
        else
        {
            min_diff = min(min_diff, dp[v][1] - dp[v][2]);
        }
    }

    dp[u][0] = total_sum;

    if (graph[u].size() == 1 && p != 0)
    {
    }
    else if (all_choose_1)
    {
        if (min_diff != INF)
        {
            dp[u][1] = total_sum - min_diff;
        }
    }
    else
        dp[u][1] = total_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u, v;
    cin >> n;
    graph.resize(n + 1);
    number.resize(n + 1);
    dp.resize(n + 1, vector<int>(3));

    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(1, 0);

    cout << max(dp[1][1], dp[1][2]) << "\n";

    return 0;
}