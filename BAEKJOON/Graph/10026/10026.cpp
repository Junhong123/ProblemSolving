#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nx, ny;
    int cnt1 = 0;
    int cnt2 = 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    cin >> n;
    vector<string> str(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto [y, x] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            if (!visited[ny][nx] && str[y][x] == str[ny][nx])
                            {
                                q.push({ny, nx});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
                cnt1++;
            }
        }
    }

    fill(visited.begin(), visited.end(), vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto [y, x] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        nx = x + dx[i];
                        ny = y + dy[i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            if (!visited[ny][nx])
                            {
                                bool isc = false;
                                if (str[y][x] == str[ny][nx])
                                    isc = true;
                                else if (str[y][x] == 'R' && str[ny][nx] == 'G')
                                    isc = true;
                                else if (str[y][x] == 'G' && str[ny][nx] == 'R')
                                    isc = true;
                                if (isc)
                                {
                                    q.push({ny, nx});
                                    visited[ny][nx] = true;
                                }
                            }
                        }
                    }
                }
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n";

    return 0;
}