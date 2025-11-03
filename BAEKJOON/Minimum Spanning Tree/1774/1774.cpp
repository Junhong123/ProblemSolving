#include <bits/stdc++.h>
#define int long long
#define float double

using namespace std;

float get_dist(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

struct UF
{
    vector<int> parent, rank;
    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    };

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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    float x, y;
    cin >> n >> m;
    UF uf(n);
    vector<pair<float, float>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<tuple<float, int, int>> dist_arr;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dist_arr.emplace_back(get_dist(arr[i].first, arr[i].second, arr[j].first, arr[j].second), i, j);
        }
    }

    while (m--)
    {
        cin >> u >> v;
        uf.unite(u, v);
    }

    sort(dist_arr.begin(), dist_arr.end());
    float ans = 0;

    for (auto &[dst, idx1, idx2] : dist_arr)
    {
        if (uf.unite(idx1, idx2))
        {
            ans += dst;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";

    return 0;
}