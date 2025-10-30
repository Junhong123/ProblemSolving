#include <bits/stdc++.h>

using namespace std;

struct UF
{
    map<string, string> parent;
    map<string, int> rank;
    map<string, int> sz;

    void con(string str)
    {
        parent[str] = str;
        rank[str] = 1;
        sz[str] = 1;
    }

    string find(string u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(string u, string v)
    {
        if (parent.find(u) == parent.end())
            con(u);
        if (parent.find(v) == parent.end())
            con(v);
        u = find(u);
        v = find(v);
        if (u == v)
        {
            cout << sz[u] << "\n";
            return;
        }
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        sz[v] += sz[u];
        if (rank[u] == rank[v])
            rank[v]++;
        cout << sz[v] << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, F;
    string name1, name2;
    cin >> T;
    while (T--)
    {
        UF uf;
        cin >> F;
        while (F--)
        {
            cin >> name1 >> name2;
            uf.merge(name1, name2);
        }
    }
    return 0;
}