#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> graph;
queue<pair<pair<int, int>, int>> q;
int ans = 1;

void BFS()
{
    int dx[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {1, -1, 0, 0, 0, 0};
    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first.second + dy[i];
            int nz = cur.first.first + dz[i];
            if (nx < 0 || nx >= graph[0][0].size() || ny < 0 || ny >= graph[0].size() || nz < 0 || nz >= graph.size())
                continue;

            if (graph[nz][ny][nx] == 0)
            {
                q.push({{nz, ny}, nx});
                graph[nz][ny][nx] = graph[cur.first.first][cur.first.second][cur.second] + 1;
                ans = max(graph[nz][ny][nx], ans);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;
    cin >> m >> n >> h;
    graph.resize(h, vector<vector<int>>(n, vector<int>(m, 0)));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1)
                    q.push({{i, j}, k});
            }
        }
    }

    BFS();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (graph[i][j][k] == 0)
                    ans = 0;
            }
        }
    }

    cout << ans - 1 << "\n";

    return 0;
}