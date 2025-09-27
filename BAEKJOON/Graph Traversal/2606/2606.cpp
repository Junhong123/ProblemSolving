#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int cnt = 1;

void DFS(int r)
{
    visited[r] = cnt++;
    for (auto val : graph[r])
    {
        if (visited[val] == 0)
            DFS(val);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1);

    cout << cnt - 2 << "\n";

    return 0;
}