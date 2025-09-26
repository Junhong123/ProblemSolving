#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;
int order = 1;

void DFS(int r)
{
    visited[r] = order++;

    for (auto val : graph[r])
    {
        if (visited[val] == 0)
            DFS(val);
    }
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(r);

    for (int i = 1; i <= n; i++)
        cout << visited[i] << "\n";

    return 0;
}