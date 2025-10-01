#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
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

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for (auto next : graph[cur])
        {
            if (!--visited[next])
            {
                pq.push(next);
            }
        }
    }

    return 0;
}