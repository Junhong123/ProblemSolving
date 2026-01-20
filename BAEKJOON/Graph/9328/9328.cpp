#include <bits/stdc++.h>

using namespace std;

constexpr int dy[4] = {-1, 1, 0, 0};
constexpr int dx[4] = {0, 0, -1, 1};
bool visited[103][103];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, m;
    string tmp;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        vector<string> arr(n + 2, ".");
        for (int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            arr[i] += tmp;
            arr[i] += ".";
        }
        for (int i = 0; i <= m; ++i)
        {
            arr[0] += ".";
            arr[n + 1] += ".";
        }

        set<char> key;
        cin >> tmp;
        if (tmp != "0")
            for (auto &c : tmp)
                key.insert(c + ('A' - 'a'));
        vector<vector<pair<int, int>>> point(26);

        int ans = 0;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty())
        {
            const auto [cur_y, cur_x] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                const int ny = cur_y + dy[i];
                const int nx = cur_x + dx[i];
                if (ny < 0 || ny > n + 1 || nx < 0 || nx > m + 1)
                    continue;
                if (visited[ny][nx] || arr[ny][nx] == '*')
                    continue;

                const char cell = arr[ny][nx];
                if (cell == '$')
                {
                    ans++;
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
                else if (cell == '.')
                {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
                else if (cell >= 'a' && cell <= 'z')
                {
                    char target = arr[ny][nx] + ('A' - 'a');
                    key.insert(target);
                    if (point[target - 'A'].size() != 0)
                    {
                        for (auto &[y, x] : point[target - 'A'])
                        {
                            q.push({y, x});
                            visited[y][x] = true;
                        }
                        point[target - 'A'].clear();
                    }
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
                else if (cell >= 'A' && cell <= 'Z')
                {
                    if (key.find(cell) != key.end())
                    {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                    else
                    {
                        point[cell - 'A'].push_back({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}