#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<vector<int>> path;

void findPath(int start, int end)
{
    if (path[start][end] == 0)
        return;
    int k = path[start][end];
    findPath(start, k);
    ans.emplace_back(k);
    findPath(k, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    path = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == 1e9)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == 0 || dist[i][j] == 1e9)
            {
                cout << "0\n";
                continue;
            }

            ans.clear();
            findPath(i, j);

            cout << 2 + ans.size() << " " << i << " ";
            for (auto val : ans)
                cout << val << " ";
            cout << j << "\n";
        }
    }

    return 0;
}