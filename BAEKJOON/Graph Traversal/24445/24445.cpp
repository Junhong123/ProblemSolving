#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int order = 1;

void BFS(int r)
{
    queue<int> q;
    q.push(r);
    visited[r] = order++;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (auto val : graph[current])
        {
            if (visited[val] == 0)
            {
                q.push(val);
                visited[val] = order++;
            }
        }
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
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    BFS(r);

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << "\n";
    }

    return 0;
}