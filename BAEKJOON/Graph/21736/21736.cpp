#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt = 0;
vector<vector<char>> arr;
vector<vector<bool>> visited;

void solve(int x, int y)
{
    visited[y][x] = true;
    if (arr[y][x] == 'P')
        cnt++;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && arr[ny][nx] != 'X')
            solve(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'I')
            {
                x = j;
                y = i;
            }
        }

    solve(x, y);

    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;

    return 0;
}