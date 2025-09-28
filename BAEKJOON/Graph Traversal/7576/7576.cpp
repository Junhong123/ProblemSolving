#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
queue<pair<int, int>> q;
int ans = 1;

void BFS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            if (nx < 0 || nx >= graph[0].size() || ny < 0 || ny >= graph.size())
                continue;

            if (graph[ny][nx] == 0)
            {
                q.push({ny, nx});
                graph[ny][nx] = graph[cur.first][cur.second] + 1;
                ans = max(graph[ny][nx], ans);
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    graph = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                q.push({i, j});
        }
    }

    BFS();

    for (auto row : graph)
    {
        for (auto val : row)
        {
            if (val == 0)
                ans = 0;
        }
    }

    cout << ans - 1 << "\n";

    return 0;
}