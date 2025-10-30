#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> parent, rank;
    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find(parent[n]);
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

    int n, m;
    cin >> n >> m;
    UF uf(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            if (num == 1)
                uf.merge(i, j);
        }
    }

    bool isc = true;
    int num;
    cin >> num;
    int res = uf.find(num);
    while (--m)
    {
        cin >> num;
        if (res != uf.find(num))
        {
            isc = false;
            break;
        }
    }

    if (isc)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}