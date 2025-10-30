#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent, rank;

    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
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

    int n, m, u, v, first;
    cin >> n >> m;
    UF uf(n);

    while (m--)
    {
        cin >> first;
        if (first == 0)
        {
            cin >> u >> v;
            uf.merge(u, v);
        }
        else if (first == 1)
        {
            cin >> u >> v;
            int p1 = uf.find(u);
            int p2 = uf.find(v);
            if (p1 == p2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}