#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void DFS(int r)
{
    cout << r << " ";
    visited[r] = order++;
    for (auto next : graph[r])
    {
        if (visited[next] == 0)
            DFS(next);
    }
}

void BFS(int r)
{
    queue<int> q;

    q.push(r);
    visited[r] = order++;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (auto next : graph[current])
        {
            if (visited[next] == 0)
            {
                q.push(next);
                visited[next] = order++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(r);

    cout << "\n";
    order = 1;
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    BFS(r);

    return 0;
}