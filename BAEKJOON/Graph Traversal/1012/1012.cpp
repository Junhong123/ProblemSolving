#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int cnt;

void DFS(int y, int x)
{
    visited[y][x] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= graph.size() || nx < 0 || nx >= graph[y].size())
            continue;

        if (graph[ny][nx] == 1 && !visited[ny][nx])
        {
            DFS(ny, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m, k;
    cin >> T;

    while (T--)
    {
        cin >> m >> n >> k;
        cnt = 0;

        graph = vector<vector<int>>(n, vector<int>(m, 0));
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[v][u] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (graph[i][j] == 1 && visited[i][j] == false)
                {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}