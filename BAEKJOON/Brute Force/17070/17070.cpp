#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int cnt = 0;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    queue<tuple<int, int, int>> q;
    q.push({0, 1, 0});
    while (!q.empty())
    {
        auto [y, x, arrow] = q.front();
        q.pop();
        if (y == n - 1 && x == n - 1)
            cnt++;
        else
        {
            if (x + 1 < n && arrow != 2 && arr[y][x + 1] != 1)
                q.push({y, x + 1, 0});
            if (x + 1 < n && y + 1 < n && arr[y][x + 1] != 1 && arr[y + 1][x + 1] != 1 && arr[y + 1][x] != 1)
                q.push({y + 1, x + 1, 1});
            if (y + 1 < n && arrow != 0 && arr[y + 1][x] != 1)
                q.push({y + 1, x, 2});
        }
    }

    cout << cnt;

    return 0;
}