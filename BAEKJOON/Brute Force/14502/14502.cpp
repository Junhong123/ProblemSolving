#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8][8];
int tmp_arr[8][8];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans = 0;

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            tmp_arr[i][j] = arr[i][j];
            if (tmp_arr[i][j] == 2)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        auto [cur_y, cur_x] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = cur_y + dy[i];
            int nxt_x = cur_x + dx[i];
            if (nxt_y >= 0 && nxt_y < n && nxt_x >= 0 && nxt_x < m)
            {
                if (tmp_arr[nxt_y][nxt_x] == 0)
                {
                    tmp_arr[nxt_y][nxt_x] = 2;
                    q.push({nxt_y, nxt_x});
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (tmp_arr[i][j] == 0)
                cnt++;
        }
    }

    ans = max(ans, cnt);
}

void make_wall(int cnt)
{
    if (cnt == 3)
    {
        bfs();
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                make_wall(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    make_wall(0);

    cout << ans;

    return 0;
}