#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1);
    visited = vector<int>(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        visited[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto next : graph[cur])
        {
            if (!--visited[next])
            {
                q.push(next);
            }
        }
    }

    return 0;
}