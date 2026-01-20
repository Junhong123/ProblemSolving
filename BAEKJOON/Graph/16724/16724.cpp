#include <bits/stdc++.h>

using namespace std;

int cnt;
char arr[1000][1000];
bool visited[1000][1000];
bool finished[1000][1000];
pair<int, int> nxt;

void DFS(int y, int x)
{
    visited[y][x] = true;
    if (arr[y][x] == 'D')
        nxt = {y + 1, x};
    else if (arr[y][x] == 'U')
        nxt = {y - 1, x};
    else if (arr[y][x] == 'L')
        nxt = {y, x - 1};
    else if (arr[y][x] == 'R')
        nxt = {y, x + 1};

    if (!visited[nxt.first][nxt.second])
        DFS(nxt.first, nxt.second);
    else
    {
        if (!finished[nxt.first][nxt.second])
        {
            cnt++;
        }
    }

    finished[y][x] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j])
                DFS(i, j);
        }
    }

    cout << cnt;

    return 0;
}