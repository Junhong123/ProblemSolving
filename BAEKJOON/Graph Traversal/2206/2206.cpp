#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<vector<int>>> visited;

void BFS()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        auto [cur_y, cur_x, broken] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (ny < 0 || ny >= graph.size() || nx < 0 || nx >= graph[0].size())
                continue;

            if (visited[ny][nx][broken] == 0)
            {
                if (graph[ny][nx] == 1 && broken == 1)
                    continue;
                else if (graph[ny][nx] == 1 && broken == 0)
                {
                    q.push({ny, nx, 1});
                    visited[ny][nx][1] = visited[cur_y][cur_x][broken] + 1;
                }
                else
                {
                    q.push({ny, nx, broken});
                    visited[ny][nx][broken] = visited[cur_y][cur_x][broken] + 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    graph = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(2, 0)));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j] - '0';
        }
    }

    BFS();

    if (visited[n - 1][m - 1][0] == 0 && visited[n - 1][m - 1][1] == 0)
        cout << "-1\n";
    else if (visited[n - 1][m - 1][0] == 0)
        cout << visited[n - 1][m - 1][1] << "\n";
    else if (visited[n - 1][m - 1][1] == 0)
        cout << visited[n - 1][m - 1][0] << "\n";
    else
        cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]) << "\n";

    return 0;
}