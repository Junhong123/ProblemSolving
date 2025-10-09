#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<vector<ll>> dist(v + 1, vector<ll>(v + 1, INF));
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i <= v; i++)
        ans = min(dist[i][i], ans);

    if (ans == INF)
        cout << "-1" << "\n";
    else
        cout << ans << "\n";

    return 0;
}