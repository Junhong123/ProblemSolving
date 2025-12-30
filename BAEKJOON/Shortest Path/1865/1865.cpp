#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, w, u, v, l, T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> w;
        vector<Edge> edges;
        while (m--)
        {
            cin >> u >> v >> l;
            edges.push_back({u, v, l});
            edges.push_back({v, u, l});
        }

        while (w--)
        {
            cin >> u >> v >> l;
            edges.push_back({u, v, -l});
        }

        bool iscom = false;
        vector<int> dist(n + 1, INF);
        for (int i = 1; i <= n; i++)
        {
            for (const auto &[u, v, w] : edges)
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;

                    if (i == n)
                    {
                        iscom = true;
                        break;
                    }
                }
            }
        }

        if (iscom)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}