#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (dist[u][v] > w)
            dist[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}