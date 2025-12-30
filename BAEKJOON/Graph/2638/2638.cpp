#include <bits/stdc++.h>

using namespace std;

int num, n, m;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> cheeses;

void DFS(int y, int x)
{
    if (arr[y][x] == 2)
        return;

    arr[y][x] = 1;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
        {
            if (!visited[ny][nx])
                DFS(ny, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            if (num == 1)
            {
                cheeses.emplace_back(i, j);
                arr[i][j] = 2;
            }
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                arr[i][j] = true;
        }
    }

    DFS(0, 0);

    bool isC = false;
    int ans = 0;
    int cnt;
    queue<pair<int, int>> q;
    while (!isC)
    {
        isC = true;
        for (auto &[y, x] : cheeses)
        {
            cnt = 0;
            if (arr[y][x] != 2)
                continue;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (arr[ny][nx] == 1)
                    cnt++;
            }
            if (cnt > 1)
            {
                q.push({y, x});
                isC = false;
            }
        }

        while (!q.empty())
        {
            auto [y, x] = q.front();
            q.pop();
            arr[y][x] = 1;
        }

        if (!isC)
        {
            ans++;
            fill(visited.begin(), visited.end(), vector<bool>(m, false));
            DFS(0, 0);
        }
    }

    cout << ans;

    return 0;
}