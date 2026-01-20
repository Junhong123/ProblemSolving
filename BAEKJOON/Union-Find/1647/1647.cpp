#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> rank, parent;
    UF(int n) : rank(n + 1, 1), parent(n + 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int idx)
    {
        if (parent[idx] == idx)
            return idx;
        else
            return parent[idx] = find(parent[idx]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, n, m, w;
    cin >> n >> m;
    UF uf(n);
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    sort(edges.begin(), edges.end());

    int tot = 0;
    int max_w = -1;
    for (auto &[w, u, v] : edges)
    {
        if (uf.find(u) == uf.find(v))
            continue;
        tot += w;
        uf.merge(u, v);
        max_w = max(max_w, w);
    }

    cout << tot - max_w;

    return 0;
}