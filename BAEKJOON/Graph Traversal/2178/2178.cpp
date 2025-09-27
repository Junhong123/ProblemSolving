#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;
int order = 1;

void BFS(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = order;
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
            if (nx < 0 || nx >= graph[c].size() || ny < 0 || ny >= graph.size())
                continue;

            if (graph[ny][nx] == 1 && visited[ny][nx] == 0)
            {
                q.push({ny, nx});
                visited[ny][nx] = visited[cur.first][cur.second] + 1;
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

    graph.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j] - '0';
        }
    }

    BFS(0, 0);

    cout << visited[n - 1][m - 1] << "\n";

    return 0;
}