#include <bits/stdc++.h>

using namespace std;

float get_dist(float x1, float y1, float x2, float y2)
{
    float nx = x2 - x1;
    float ny = y2 - y1;
    return sqrt(pow(nx, 2) + pow(ny, 2));
}

struct UF
{
    vector<int> parent, rank;
    map<pair<float, float>, int> mp;
    float dist = 0;
    int cnt = 1;
    UF(int n) : parent(n + 1), rank(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find_idx(float x, float y)
    {
        if (mp.find({x, y}) == mp.end())
        {
            return mp[{x, y}] = cnt++;
        }
        return mp[{x, y}];
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void unite(float x1, float y1, float x2, float y2)
    {
        int u = find_idx(x1, y1);
        int v = find_idx(x2, y2);
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            rank[v]++;
        dist += get_dist(x1, y1, x2, y2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    float x, y;
    vector<tuple<float, float, float, float, float>> arr;
    vector<pair<float, float>> v;
    cin >> n;
    UF uf(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.emplace_back(x, y);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            arr.emplace_back(get_dist(v[i].first, v[i].second, v[j].first, v[j].second), v[i].first, v[i].second, v[j].first, v[j].second);
        }
    }

    sort(arr.begin(), arr.end());

    for (auto [d, x1, y1, x2, y2] : arr)
    {
        uf.unite(x1, y1, x2, y2);
    }

    cout << fixed;
    cout.precision(2);
    cout << uf.dist << "\n";

    return 0;
}