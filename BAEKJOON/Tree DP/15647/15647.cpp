#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<long long> sz;
vector<long long> sum_dist;
int n;

void DFS1(int u, int p)
{
    sz[u] = 1;
    sum_dist[u] = 0;

    for (auto &[w, v] : graph[u])
    {
        if (v == p)
            continue;
        DFS1(v, u);
        sz[u] += sz[v];
        sum_dist[u] += sum_dist[v] + (w * sz[v]);
    }
}

void DFS2(int u, int p)
{
    for (auto &[w, v] : graph[u])
    {
        if (v == p)
            continue;
        sum_dist[v] = sum_dist[u] - (sz[v] * w) + ((n - sz[v]) * w);
        DFS2(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, w;
    cin >> n;
    graph.resize(n + 1);
    sz.resize(n + 1, 0);
    sum_dist.resize(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    DFS1(1, 0);
    DFS2(1, 0);

    for (int i = 1; i <= n; i++)
        cout << sum_dist[i] << "\n";

    return 0;
}