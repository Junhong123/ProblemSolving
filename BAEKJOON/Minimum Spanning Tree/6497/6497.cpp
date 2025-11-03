#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent, rank;
    UF(int n) : parent(n), rank(n, 1)
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

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, x, y, w;
    vector<tuple<int, int, int>> arr;
    cin >> m >> n;
    while (m != 0 || n != 0)
    {
        arr.clear();
        UF uf(m);
        int tot = 0;
        while (n--)
        {
            cin >> x >> y >> w;
            arr.emplace_back(w, x, y);
            tot += w;
        }

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (auto &[w, x, y] : arr)
        {
            if (uf.unite(x, y))
                ans += w;
        }

        cout << tot - ans << "\n";

        cin >> m >> n;
    }

    return 0;
}