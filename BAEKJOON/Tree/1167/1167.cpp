#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> visited;
int max_len = -1;
int idx = -1;

void DFS(int start, int depth)
{
    if (visited[start] != -1 && visited[start] != 0)
        return;
    if (graph[start].size() == 1 && visited[start] == -1)
    {
        if (max_len < depth)
        {
            max_len = depth;
            idx = start;
        }
        return;
    }

    visited[start] = 1;

    for (auto [next_weight, next_node] : graph[start])
    {
        DFS(next_node, depth + next_weight);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    graph = vector<vector<pair<int, int>>>(n + 1);
    visited = vector<int>(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int node, adj, weight;
        cin >> node >> adj;
        while (adj != -1)
        {
            cin >> weight;
            graph[node].emplace_back(weight, adj);
            cin >> adj;
        }
    }

    visited[1] = 0;
    DFS(1, 0);
    fill(visited.begin(), visited.end(), -1);
    visited[idx] = 0;
    DFS(idx, 0);

    cout << max_len << "\n";

    return 0;
}