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

    int num, n, m, idx, tpl_root;
    cin >> n >> m;
    cin >> num;
    UF uf(n);

    int t_pl = -1;
    int prev = -1;
    for (int i = 0; i < num; i++)
    {
        cin >> t_pl;
        if (prev != -1)
            uf.merge(t_pl, prev);
        prev = t_pl;
    }

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> idx;
            parties[i].emplace_back(idx);
            uf.merge(parties[i][0], parties[i][j]);
        }
    }

    if (t_pl != -1)
        tpl_root = uf.find(t_pl);
    else
        tpl_root = -1;
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        if (uf.find(parties[i][0]) == tpl_root)
            continue;
        cnt++;
    }

    cout << cnt;

    return 0;
}