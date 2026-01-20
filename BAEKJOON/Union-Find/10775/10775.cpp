#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent;
    UF(int n) : parent(n + 1)
    {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (u < v)
            parent[v] = u;
        else
            parent[u] = v;
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P, n;
    int ans = 0;
    cin >> G >> P;
    UF uf(G);
    while (P--)
    {
        cin >> n;
        int cur = uf.find(n);

        if (cur == 0)
            break;

        uf.merge(cur, cur - 1);
        ans++;
    }
    cout << ans;

    return 0;
}