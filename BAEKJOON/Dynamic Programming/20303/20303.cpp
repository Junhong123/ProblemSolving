#include <bits/stdc++.h>

using namespace std;

struct UF
{
    vector<int> size, parent;
    vector<long long> candy;
    UF(int n, vector<int> &initial_candies) : parent(n + 1), size(n + 1, 1), candy(n + 1)
    {
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            candy[i] = initial_candies[i];
        }
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

        if (u != v)
        {
            parent[v] = u;
            size[u] += size[v];
            candy[u] += candy[v];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, n, m, k;
    cin >> n >> m >> k;

    vector<int> candies(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> candies[i];

    UF uf(n, candies);

    while (m--)
    {
        cin >> u >> v;
        uf.merge(u, v);
    }

    vector<long long> dp(k, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (uf.parent[i] == i)
        {
            for (int j = k - 1; j >= uf.size[i]; --j)
                dp[j] = max(dp[j], dp[j - uf.size[i]] + uf.candy[i]);
        }
    }

    cout << dp[k - 1];
    return 0;
}