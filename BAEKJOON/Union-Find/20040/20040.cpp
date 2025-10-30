#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent, rank;
    int ans = 1000001;
    int cnt = 1;

    UF(int n) : parent(n), rank(n)
    {
        for (int i = 0; i < n; i++)
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
        {
            ans = min(ans, cnt++);
            return;
        }
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        cnt++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    UF uf(n);
    while (m--)
    {
        cin >> u >> v;
        uf.merge(u, v);
    }

    cout << (uf.ans == 1000001 ? 0 : uf.ans) << "\n";

    return 0;
}