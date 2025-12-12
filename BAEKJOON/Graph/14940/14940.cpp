#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sx, sy, nx, ny;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                sy = i;
                sx = j;
                ans[i][j] = 0;
            }
            else if (graph[i][j] == 0)
                ans[i][j] = 0;
        }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sy][sx] = true;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (!visited[ny][nx] && graph[ny][nx] != 0)
                {
                    visited[ny][nx] = true;
                    ans[ny][nx] = ans[y][x] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (auto &row : ans)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}