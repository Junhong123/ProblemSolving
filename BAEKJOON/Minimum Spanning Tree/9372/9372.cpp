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

    void unite(int u, int v)
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
        cnt++;
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m, u, v;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        UF uf(n);
        while (m--)
        {
            cin >> u >> v;
            uf.unite(u, v);
        }
        cout << uf.cnt << "\n";
    }
    return 0;
}