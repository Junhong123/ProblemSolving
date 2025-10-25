#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int max_len = -1;
int idx = -1;

void DFS(int start, int depth)
{
    visited[start] = true;

    if (max_len < depth)
    {
        max_len = depth;
        idx = start;
    }

    for (auto &[next_weight, next_node] : graph[start])
    {
        if (!visited[next_node])
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
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    n--;
    while (n--)
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        graph[parent].emplace_back(weight, child);
        graph[child].emplace_back(weight, parent);
    }

    DFS(1, 0);
    fill(visited.begin(), visited.end(), false);
    DFS(idx, 0);

    cout << max_len << "\n";

    return 0;
}