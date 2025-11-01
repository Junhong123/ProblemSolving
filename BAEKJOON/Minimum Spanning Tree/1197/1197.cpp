#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent, rank;
    int cnt = 0;
    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v, int w)
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
        cnt += w;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, w;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    UF uf(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges)
    {
        uf.unite(u, v, w);
    }

    cout << uf.cnt << "\n";
    return 0;
}