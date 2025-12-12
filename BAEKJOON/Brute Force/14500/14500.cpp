#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m - 4; j++)
        {
            int tmp = 0;
            for (int k = j; k <= j + 3; k++)
                tmp += arr[i][k];
            ans = max(ans, tmp);
        }
    }

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp = 0;
            for (int k = i; k <= i + 3; k++)
                tmp += arr[k][j];
            ans = max(ans, tmp);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int tmp = 0;
            int dx[4] = {0, 1, 0, 1};
            int dy[4] = {0, 0, 1, 1};
            for (int k = 0; k < 4; k++)
                tmp += arr[i + dy[k]][j + dx[k]];
            ans = max(ans, tmp);
        }
    }

    pair<int, int> L[4][4] = {{{0, 0}, {1, 0}, {2, 0}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {1, 0}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {0, 2}, {-1, 2}}};
    for (int rotate = 0; rotate < 4; rotate++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + L[rotate][k].first;
                    int x = j + L[rotate][k].second;
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        tmp += arr[y][x];
                    }
                    else
                    {
                        tmp = -1;
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }

    pair<int, int> Z[2][4] = {{{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}}};
    for (int rotate = 0; rotate < 2; rotate++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + Z[rotate][k].first;
                    int x = j + Z[rotate][k].second;
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        tmp += arr[y][x];
                    }
                    else
                    {
                        tmp = -1;
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }

    pair<int, int> T[4][4] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}}, {{0, 0}, {1, 0}, {1, -1}, {2, 0}}, {{0, 0}, {0, 1}, {-1, 1}, {0, 2}}, {{0, 0}, {1, 1}, {1, 0}, {2, 0}}};
    for (int rotate = 0; rotate < 4; rotate++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + T[rotate][k].first;
                    int x = j + T[rotate][k].second;
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        tmp += arr[y][x];
                    }
                    else
                    {
                        tmp = -1;
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }

    pair<int, int> RL[4][4] = {{{0, 0}, {1, 0}, {2, 0}, {2, -1}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {2, 0}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}};
    for (int rotate = 0; rotate < 4; rotate++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + RL[rotate][k].first;
                    int x = j + RL[rotate][k].second;
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        tmp += arr[y][x];
                    }
                    else
                    {
                        tmp = -1;
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }

    pair<int, int> RZ[2][4] = {{{0, 0}, {1, 0}, {1, -1}, {2, -1}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}};
    for (int rotate = 0; rotate < 2; rotate++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 4; k++)
                {
                    int y = i + RZ[rotate][k].first;
                    int x = j + RZ[rotate][k].second;
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        tmp += arr[y][x];
                    }
                    else
                    {
                        tmp = -1;
                        break;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }

    cout << ans;

    return 0;
}