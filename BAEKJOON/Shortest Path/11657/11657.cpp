#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, u, v, w;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    while (m--)
    {
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto &edge : edges)
        {
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool has_negative = false;
    for (auto &edge : edges)
    {
        tie(u, v, w) = edge;
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            has_negative = true;
            break;
        }
    }

    if (has_negative)
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
                cout << "-1\n";
            else
                cout << dist[i] << "\n";
        }
    }
    return 0;
}