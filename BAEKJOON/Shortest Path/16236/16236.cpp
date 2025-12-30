#include <bits/stdc++.h>

using namespace std;

int n, ans, sz, fll;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
vector<vector<int>> arr;
vector<vector<bool>> visited;

pair<int, int> eat(int y, int x)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, y, x});
    visited[y][x] = true;
    bool eaten = false;
    while (!pq.empty())
    {
        auto [cur, cy, cx] = pq.top();
        pq.pop();
        if (arr[cy][cx] != 0 && arr[cy][cx] < sz)
        {
            ans += cur;
            if (++fll == sz)
            {
                sz++;
                fll = 0;
            }
            arr[cy][cx] = 0;
            eaten = true;
            y = cy;
            x = cx;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n)
            {
                if (arr[ny][nx] <= sz && !visited[ny][nx])
                {
                    pq.push({cur + 1, ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    if (eaten)
        return {y, x};
    else
        return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sx, sy;
    cin >> n;
    arr.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                sx = j;
                sy = i;
                arr[i][j] = 0;
            }
        }
    }

    ans = 0;
    sz = 2;
    fll = 0;

    while (true)
    {
        auto [ny, nx] = eat(sy, sx);
        if (ny == -1 && nx == -1)
            break;
        sy = ny;
        sx = nx;
        fill(visited.begin(), visited.end(), vector<bool>(n, false));
    }

    cout << ans;

    return 0;
}