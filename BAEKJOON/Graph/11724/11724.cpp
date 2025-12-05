#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int n)
{
    visited[n] = true;
    for (auto &next : graph[n])
    {
        if (!visited[next])
            DFS(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}