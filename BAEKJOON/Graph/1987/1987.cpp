#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<vector<char>> arr;
bool visited[26];

void solve(int x, int y, int dist)
{
    ans = max(ans, dist);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[arr[ny][nx] - 'A'])
        {
            visited[arr[ny][nx] - 'A'] = true;
            solve(nx, ny, dist + 1);
            visited[arr[ny][nx] - 'A'] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    visited[arr[0][0] - 'A'] = true;
    solve(0, 0, 1);

    cout << ans;

    return 0;
}