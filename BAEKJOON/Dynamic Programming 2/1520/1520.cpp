#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> dp;
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int DFS(int y, int x)
{
    if (y == n && x == m)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];
    dp[y][x] = 0;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 1 || nx > m || ny < 1 || ny > n)
            continue;
        if (arr[ny][nx] < arr[y][x])
        {
            dp[y][x] += DFS(ny, nx);
        }
    }
    return dp[y][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

    cout << DFS(1, 1) << "\n";

    return 0;
}